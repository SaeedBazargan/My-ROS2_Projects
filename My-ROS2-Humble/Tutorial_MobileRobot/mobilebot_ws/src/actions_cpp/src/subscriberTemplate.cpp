/* How to use:
* Run this in one terminal: ros2 run your_package simple_subscriber
* Then in another terminal, publish a message: ros2 topic pub /chatter std_msgs/msg/String "data: Hello ROS2"
*/

// #include "rclcpp/rclcpp.hpp"
// #include "std_msgs/msg/string.hpp"   // Change this to your message type if needed

// using namespace std::placeholders;

// class SimpleSubscriber : public rclcpp::Node
// {
// public:
//     SimpleSubscriber() : Node("simple_subscriber_node")
//     {
//         // Create the subscriber
//         subscription_ = this->create_subscription<std_msgs::msg::String>(
//             "chatter",
//             10,
//             std::bind(&SimpleSubscriber::topic_callback, this, _1)
//         );

//         RCLCPP_INFO(this->get_logger(), "Subscriber is ready and listening on 'chatter' topic.");
//     }

// private:
//     rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    
//     void topic_callback(const std_msgs::msg::String::SharedPtr msg)
//     {
//         RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
//     }
// };

// int main(int argc, char * argv[])
// {
//     rclcpp::init(argc, argv);
//     rclcpp::spin(std::make_shared<SimpleSubscriber>());
//     rclcpp::shutdown();

//     return 0;
// }
