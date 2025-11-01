#include "rclcpp/rclcpp.hpp"
#include "components_cpp/number_publisher.hpp"

using namespace std::chrono_literals;

namespace my_components_namespace_
{
    int number_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;

    void NumberPub::publishNumber()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_;
        number_publisher_->publish(msg);
    }

    NumberPub::NumberPub(const rclcpp::NodeOptions &options_) : Node("number_publisher", options_)
    {
        number_ = 2;

        number_publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        number_timer_ = this->create_wall_timer(1000ms, std::bind(&NumberPub::publishNumber, this));

        RCLCPP_INFO(this->get_logger(), "Number publisher has been started.");
    }
}   // my_components_namespace_

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(my_components_namespace_::NumberPub)