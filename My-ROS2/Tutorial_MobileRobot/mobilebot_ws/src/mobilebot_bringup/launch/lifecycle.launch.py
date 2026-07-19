from launch import LaunchDescription
from launch_ros.actions import LifecycleNode
from launch_ros.actions import Node

def generate_launch_description():
    node_name = "number_pub_node"

    number_node = LifecycleNode(
        package="lifecycle_cpp",
        executable="number_publisher",
        name=node_name,
        namespace=""
    )

    lifecycle_node_manager = Node(
        package="lifecycle_cpp",
        executable="lifecycle_node_manager",
        parameters=[
            {"managed_node_name": node_name}
        ]
    )

    return LaunchDescription([
        number_node,
        lifecycle_node_manager
    ])
