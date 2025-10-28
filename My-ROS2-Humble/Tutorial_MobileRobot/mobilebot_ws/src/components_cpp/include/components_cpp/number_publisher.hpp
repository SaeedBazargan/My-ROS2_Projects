#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"


namespace my_components_namespace_
{
class NumberPub : public rclcpp::Node
{
private:
    int number_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;

    void publishNumber();

public:
    NumberPub(const rclcpp::NodeOptions &options_);
};
}   // my_components_namespace_
