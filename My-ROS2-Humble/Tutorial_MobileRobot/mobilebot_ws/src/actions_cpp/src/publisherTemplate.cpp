// /* How to use:
//  * 1. Run this publisher in one terminal: ros2 run your_package simple_publisher
//  * 2. In another terminal, check the topic: ros2 topic echo /chatter
//  * This node publishes a message on the 'chatter' topic every 500 ms.
//  */

// #include "rclcpp/rclcpp.hpp"
// #include "std_msgs/msg/string.hpp"   // Change this to your message type if needed

// class SimplePublisher : public rclcpp::Node
// {
// public:
//     SimplePublisher() : Node("simple_publisher_node")
//     {
//         // Create the publisher
//         publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);

//         // Create a timer to publish messages periodically (every 500 ms)
//         timer_ = this->create_wall_timer(
//             std::chrono::milliseconds(500),
//             std::bind(&SimplePublisher::timer_callback, this)
//         );

//         RCLCPP_INFO(this->get_logger(), "Publisher is ready and publishing to 'chatter' topic.");
//     }

// private:
//     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
//     rclcpp::TimerBase::SharedPtr timer_;
//     int counter_ = 0;

//     // Callback triggered by the timer
//     void timer_callback()
//     {
//         auto message = std_msgs::msg::String();
//         message.data = "Hello ROS2! Count: " + std::to_string(counter_++);

//         publisher_->publish(message);

//         RCLCPP_INFO(this->get_logger(), "Published: '%s'", message.data.c_str());
//     }
// };

// int main(int argc, char * argv[])
// {
//     rclcpp::init(argc, argv);
//     rclcpp::spin(std::make_shared<SimplePublisher>());
//     rclcpp::shutdown();
//     return 0;
// }
