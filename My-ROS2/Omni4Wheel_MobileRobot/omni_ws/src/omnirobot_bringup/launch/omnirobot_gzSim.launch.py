from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_path
from launch.actions import TimerAction

def generate_launch_description():
    urdf_path = os.path.join(get_package_share_path('omnirobot_description'), 'urdf', 'gazebo_ros2_control.xacro')
    rviz_config_path = os.path.join(get_package_share_path('omnirobot_description'), 'rviz', 'rviz_config.rviz')
    gazebo_config_path = os.path.join(get_package_share_path('omnirobot_bringup'), 'config', 'gz_sim_bridge.yaml')
    world_path = os.path.join(get_package_share_path('omnirobot_description'), 'models', 'model.sdf')

    # Convert xacro to URDF string
    robot_description = ParameterValue(Command(["xacro ", urdf_path]), value_type=str)

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
    )

    start_gazebo = IncludeLaunchDescription(PythonLaunchDescriptionSource(
        os.path.join(get_package_share_path("ros_gz_sim"), "launch", "gz_sim.launch.py")),
        launch_arguments={'gz_args': "-r empty.sdf"}.items())
        # Gazebo without 3D: launch_arguments={'gz_args': "-s -r empty.sdf"}.items())

    ros_gazebo_sim_node = TimerAction(
        period=2.0,
        actions=[
            Node(
                package="ros_gz_sim",
                executable="create",
                arguments=[
                    "-topic", "robot_description",
                    "-name", "omnirobot",
                    "-x", "0.1",
                    "-y", "-3",
                    "-z", "0.1"                    
                ],
                output="screen",
            )
        ]
    )

    spawn_world = TimerAction(
        period=3.0,
        actions=[
            Node(
                package="ros_gz_sim",
                executable="create",
                arguments=[
                    "-file", world_path,
                    "-name", "line_track",
                ],
                output="screen",
            )
        ]
    )
    ros_gazebo_bridge_node = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        parameters=[{"config_file": gazebo_config_path}],
        output="screen",
    )

    joint_state_broadcaster_spawner = TimerAction(
        period=3.0,
        actions=[
            Node(
                package="controller_manager",
                executable="spawner",
                arguments=["joint_state_broadcaster"],
                output="screen",
            )
        ]
    )

    omni_wheel_drive_controller_spawner = TimerAction(
        period=5.0,
        actions=[
            Node(
                package="controller_manager",
                executable="spawner",
                arguments=["omni_wheel_drive_controller"],
                output="screen",
            )
        ]
    )
    # joint_state_broadcaster_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["joint_state_broadcaster"],
    # )

    # omni_wheel_drive_controller_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["omni_wheel_drive_controller"],
    # ) 

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", rviz_config_path],
    )

    return LaunchDescription([
        robot_state_publisher_node,
        start_gazebo,
        ros_gazebo_sim_node,
        spawn_world,
        ros_gazebo_bridge_node,
        joint_state_broadcaster_spawner,
        omni_wheel_drive_controller_spawner,
        # rviz_node,
    ])
