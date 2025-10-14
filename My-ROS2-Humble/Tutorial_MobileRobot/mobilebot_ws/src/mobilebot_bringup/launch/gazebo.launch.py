from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, IncludeLaunchDescription
from launch.substitutions import Command, LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_path, get_package_prefix
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    urdf_path = os.path.join(get_package_share_path('mobilebot_description'),
                             'urdf', 'mobilebot.urdf.xacro')
    rviz_config_path = os.path.join(get_package_share_path('mobilebot_bringup'),
                             'rviz', 'mobilebot_config.rviz')

    robot_description = ParameterValue(Command(["xacro ", urdf_path]), value_type=str)

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}]
    )

    start_gazebo_server = IncludeLaunchDescription(PythonLaunchDescriptionSource(
        os.path.join(get_package_share_path("gazebo_ros"), "launch", "gzserver.launch.py")
    ))

    start_gazebo_client = IncludeLaunchDescription(PythonLaunchDescriptionSource(
        os.path.join(get_package_share_path("gazebo_ros"), "launch", "gzclient.launch.py")
    ))

    spawn_robot_node = Node(
        package="gazebo_ros",
        executable="spawn_entity.py",
        arguments=["-entity", "mobilebot", "-topic", "robot_description"]
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", rviz_config_path]
    )    

    return LaunchDescription([
        robot_state_publisher_node,
        start_gazebo_server,
        start_gazebo_client,
        spawn_robot_node,
        rviz_node
    ])