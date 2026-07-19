/* How to use:
 * 1. Run this publisher in one terminal: ros2 run your_package simple_publisher
 * 2. In another terminal, check the topic: ros2 topic echo /chatter
 * This node publishes a message on the 'chatter' topic every 500 ms.
 */

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"   // Change this to your message type if needed

class BlinkLED_Publisher : public rclcpp::Node
{
public:
    BlinkLED_Publisher() : Node("blinkLED_publisher_node")
    {
        // Create the publisher
        publisher_ = this->create_publisher<std_msgs::msg::Int32>(
            "microros/led_topic", 
            10);

        // Create a timer to publish messages periodically (every 2000 ms)
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(2000),
            std::bind(&BlinkLED_Publisher::timer_callback, this)
        );

        RCLCPP_INFO(this->get_logger(), "Publisher is ready and publishing to 'led_topic' topic.");
    }

private:
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_ = 0;

    // Callback triggered by the timer
    void timer_callback()
    {
        auto message = std_msgs::msg::Int32();
        message.data = counter_;

        publisher_->publish(message);

        counter_ = 1 - counter_;

        RCLCPP_INFO(this->get_logger(), "Published: '%d'", message.data);
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BlinkLED_Publisher>());
    rclcpp::shutdown();

    return 0;
}