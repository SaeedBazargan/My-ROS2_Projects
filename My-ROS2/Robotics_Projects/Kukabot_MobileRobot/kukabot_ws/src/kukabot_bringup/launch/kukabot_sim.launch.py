from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, RegisterEventHandler, SetEnvironmentVariable
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

import os
import xacro
from pathlib import Path
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # Paths
    description_pkg_path = get_package_share_directory("kukabot_description")
    bringup_pkg_path = get_package_share_directory("kukabot_bringup")

    urdf_path = os.path.join(description_pkg_path, "urdf", "main.urdf.xacro")
    rviz_config_file = os.path.join(description_pkg_path, "rviz", "rviz_config.rviz")

    # URDF
    robot_description = xacro.process_file(urdf_path, mappings={"use_sim": "true"}).toxml()

    # Publish TF + robot model
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
        output="screen",
    )

    # Make Gazebo find models
    gazebo_resource_path = SetEnvironmentVariable(
        name="GZ_SIM_RESOURCE_PATH",
        value=[os.path.join(bringup_pkg_path, "worlds"), ":" + str(Path(description_pkg_path).parent.resolve())]
    )

    # World argument
    declare_world_arg = DeclareLaunchArgument(
        "world",
        default_value="kukabot_world",
    )

    # Start Gazebo
    start_gazebo = IncludeLaunchDescription(PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory("ros_gz_sim"), "launch", "gz_sim.launch.py")),
            launch_arguments={"gz_args": [LaunchConfiguration("world"), ".sdf", " -v 4", " -r"]}.items()
    )

    # Spawn robot into Gazebo
    gz_spawn_entity_node = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-string", robot_description,
            "-name", "kukabot",
            "-allow_renaming", "false",
            "-x", "0", 
            "-y", "0", 
            "-z", "0.07"],
        output="screen",
    )

    # Bridge
    ros_gazebo_bridge_node = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        output="screen",
    )

    # Controller Spawners (correct & clean)
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
        output="screen",
    )

    forward_velocity_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["forward_velocity_controller"],
        output="screen",
    )

    # RViz
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file]
    )

    # Ensure correct order: Spawn robot → load joint_state → load drive controller
    return LaunchDescription([
        gazebo_resource_path,
        declare_world_arg,
        start_gazebo,
        robot_state_publisher,
        gz_spawn_entity_node,
        ros_gazebo_bridge_node,
        rviz_node,

        RegisterEventHandler(OnProcessExit(target_action=gz_spawn_entity_node, on_exit=[joint_state_broadcaster_spawner])),
        RegisterEventHandler(OnProcessExit(target_action=joint_state_broadcaster_spawner, on_exit=[forward_velocity_controller_spawner])),
    ])
