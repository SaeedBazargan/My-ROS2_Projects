from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    container = ComposableNodeContainer(
        name = "my_container",
        namespace = "",
        package = "rclcpp_components",
        executable = "component_container",
        composable_node_descriptions = [
            ComposableNode(
                package="components_cpp",
                plugin = "my_components_namespace_::NumberPub",
                name="number_pub_1"
            ),
            ComposableNode(
                package="components_cpp",
                plugin = "my_components_namespace_::NumberPub",
                name="number_pub_2"
            ),
        ]
    )

    return LaunchDescription([
        container
    ])
