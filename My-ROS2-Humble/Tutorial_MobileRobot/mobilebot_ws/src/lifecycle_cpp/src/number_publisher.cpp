#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "mobilebot_interfaces/msg/int64.hpp"

using LifecycleCallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

class NumberPublisherNode : public rclcpp_lifecycle::LifecycleNode
{
private:
    int number_;
    double publish_freq_;

    rclcpp::Publisher<mobilebot_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;

    // ----------------------------------------------------
    // Timer callback function that publishes the current number.
    // Each time this function is called, the current `number_` value is published on the "number" topic, then incremented.
    // ----------------------------------------------------
    void publishNumber()
    {
        auto msg = mobilebot_interfaces::msg::Int64();
        msg.data = number_;

        number_publisher_->publish(msg);
        
        number_++;
    }
    
public:
    NumberPublisherNode() : LifecycleNode("number_publisher")
    {
        // At this stage, the node is still in the "unconfigured" state.
        
        RCLCPP_INFO(this->get_logger(), "In unconfigured state.");

        number_ = 1;
        publish_freq_ = 1.0;
    }

    // ----------------------------------------------------
    // Called when the node transitions from "unconfigured" to "inactive".
    // Initializes publishers, timers, and other resources.
    // The timer is created but immediately stopped, so publishing will only start when the node becomes "active".
    // ----------------------------------------------------
    LifecycleCallbackReturn on_configure(const rclcpp_lifecycle::State &previous_state_)
    {
        (void)previous_state_;

        RCLCPP_INFO(this->get_logger(), "In on_configure state.");

        number_publisher_ = this->create_publisher<mobilebot_interfaces::msg::Int64>("number", 10);
        number_timer_ = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / publish_freq_)), 
                                                std::bind(&NumberPublisherNode::publishNumber, this));      // timer will start
        
        number_timer_->cancel();        // Prevent timer from running until node is activated
        
        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Called when transitioning from "inactive" to "active".
    // Reactivates the timer and allows messages to be published.
    // Start the timer to begin publishing periodically
    // ----------------------------------------------------
    LifecycleCallbackReturn on_activate(const rclcpp_lifecycle::State &previous_state_)
    {
        RCLCPP_INFO(this->get_logger(), "In on_activate state.");

        number_timer_->reset();

        rclcpp_lifecycle::LifecycleNode::on_activate(previous_state_);

        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Called when transitioning from "active" to "inactive".
    // Stops the timer, so publishing is paused.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_deactivate(const rclcpp_lifecycle::State &previous_state_)
    {
        RCLCPP_INFO(this->get_logger(), "In on_deactivate state.");

        number_timer_->cancel();

        rclcpp_lifecycle::LifecycleNode::on_deactivate(previous_state_);

        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Called when transitioning from "inactive" to "unconfigured".
    // Cleans up resources such as publishers and timers.
    // destroy the publisher and timer shared pointers. This stops any active publishing or timers and releases the allocated resources.
    // After calling reset(), both objects become nullptr.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_cleanup(const rclcpp_lifecycle::State &previous_state_)
    {
        (void)previous_state_;

        RCLCPP_INFO(this->get_logger(), "In on_cleanup state.");

        number_publisher_.reset();
        number_timer_.reset();

        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Called when the node is shutting down (any state → "finalized").
    // Similar to cleanup, but for permanent shutdown.
    // Cleans up resources such as publishers and timers.
    // destroy the publisher and timer shared pointers. This stops any active publishing or timers and releases the allocated resources.
    // After calling reset(), both objects become nullptr.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_shutdown(const rclcpp_lifecycle::State &previous_state_)
    {
        (void)previous_state_;

        RCLCPP_INFO(this->get_logger(), "In on_shutdown state.");

        number_publisher_.reset();
        number_timer_.reset();

        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Called automatically if an error occurs during a lifecycle transition.
    // Resets resources and transitions to the error-processing state.
    // Cleans up resources such as publishers and timers.
    // destroy the publisher and timer shared pointers. This stops any active publishing or timers and releases the allocated resources.
    // After calling reset(), both objects become nullptr.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_error(const rclcpp_lifecycle::State &previous_state_)
    {
        (void)previous_state_;

        RCLCPP_INFO(this->get_logger(), "In on_error state.");

        number_publisher_.reset();
        number_timer_.reset();

        return LifecycleCallbackReturn::SUCCESS;
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node->get_node_base_interface());      // Spin the node's base interface (necessary for lifecycle operation)
    rclcpp::shutdown();
    
    return 0;
}