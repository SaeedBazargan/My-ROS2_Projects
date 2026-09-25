import os

from launch import LaunchDescription
from launch.actions import TimerAction, DeclareLaunchArgument
from launch.substitutions import Command, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

from ament_index_python.packages import get_package_share_path

from webots_ros2_driver.webots_launcher import WebotsLauncher
from webots_ros2_driver.webots_controller import WebotsController


def generate_launch_description():

    # Paths
    urdf_path = os.path.join(get_package_share_path('omnirobot_description'), 'urdf', 'main.xacro')
    rviz_config_path = os.path.join(get_package_share_path('omnirobot_description'), 'rviz', 'rviz_config.rviz')
    controller_path = os.path.join(get_package_share_path('omnirobot_bringup'), 'config', 'controllers.yaml')
    world_path = os.path.expanduser('~/Desktop/My-ROS2_Projects/My-ROS2/Omni4Wheel_MobileRobot_Webots/webots_ws/worlds/omni_world.wbt')
    use_sim_time = LaunchConfiguration('use_sim_time', default=True)

    # Xacro -> URDF: Used by robot_state_publisher
    robot_description = ParameterValue(Command(['xacro ', urdf_path]), value_type=str)

    declare_use_sim_time = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation time'
    )

    # Publish /robot_description
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description, 'use_sim_time': use_sim_time}]
    )

    # Webots
    start_webots = WebotsLauncher(
        world=world_path,
        ros2_supervisor=True
    )

    # Webots ROS 2 Controller -> IMPORTANT: WebotsController receives the Xacro FILE PATH here, not the Launch Command substitution above.
    robot_driver = WebotsController(
        robot_name='omnirobot',
        parameters=[{'robot_description': urdf_path, 'use_sim_time': use_sim_time, 'set_robot_state_publisher': False}, controller_path],
        respawn=False
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

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", rviz_config_path],
    )

    return LaunchDescription([
        declare_use_sim_time,
        start_webots,
        robot_state_publisher_node,
        robot_driver,
        start_webots._supervisor,
        joint_state_broadcaster_spawner,
        omni_wheel_drive_controller_spawner,
        # rviz_node
    ])
