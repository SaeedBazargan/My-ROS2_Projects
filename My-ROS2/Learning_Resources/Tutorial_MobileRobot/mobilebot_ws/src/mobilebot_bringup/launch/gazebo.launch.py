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
    world_path = os.path.join(get_package_share_path('mobilebot_bringup'),
                             'worlds', 'mobilebot_gazeboWorld.world')

    robot_description = ParameterValue(Command(["xacro ", urdf_path]), value_type=str)

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}]
    )

    start_gazebo = IncludeLaunchDescription(PythonLaunchDescriptionSource(
        os.path.join(get_package_share_path("gazebo_ros"), "launch", "gazebo.launch.py")),
        launch_arguments={'world': world_path}.items())

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
        start_gazebo,
        spawn_robot_node,
        rviz_node
    ])