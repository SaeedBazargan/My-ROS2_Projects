from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
import os
from ament_index_python.packages import get_package_share_path

def generate_launch_description():
    urdf_path = os.path.join(get_package_share_path('mobilebot_description'), 'urdf', 'mobilebot.urdf.xacro')
    robot_controllers = os.path.join(get_package_share_path('mobilebot_bringup'), 'config', 'mobilebot_controllers.yaml')
    rviz_config_path = os.path.join(get_package_share_path('mobilebot_description'), 'rviz', 'mobilebot_config.rviz')


    # Convert xacro to URDF string
    robot_description = ParameterValue(Command(["xacro ", urdf_path]), value_type=str)

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
    )

    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[{"robot_description": robot_description},
        robot_controllers],
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

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", rviz_config_path],
    )

    return LaunchDescription([
        robot_state_publisher_node,
        control_node,
        joint_state_broadcaster_spawner,
        diff_drive_controller_spawner,
        rviz_node,
    ])

