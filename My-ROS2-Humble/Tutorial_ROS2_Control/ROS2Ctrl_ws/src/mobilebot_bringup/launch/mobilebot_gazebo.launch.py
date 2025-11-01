from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_path

def generate_launch_description():
    urdf_path = os.path.join(get_package_share_path('mobilebot_description'), 'urdf', 'mobilebot_gazebo_ros2_control.xacro')
    gazebo_config_path = os.path.join(get_package_share_path('mobilebot_bringup'), 'config', 'gazebo_bridge.yaml')
    rviz_config_path = os.path.join(get_package_share_path('mobilebot_description'), 'rviz', 'mobilebot_config.rviz')

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

    ros_gazebo_sim_node = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-topic", "robot_description",
            "-name", "mobilebot"],
    )

    ros_gazebo_bridge_node = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        parameters=[{"config_file": gazebo_config_path}],
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )

    diff_drive_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["diff_drive_controller"],
    )

    arm_joint_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["arm_joints_controller"],
    )

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
        ros_gazebo_bridge_node,
        joint_state_broadcaster_spawner,
        diff_drive_controller_spawner,
        arm_joint_controller_spawner,
        rviz_node,
    ])

