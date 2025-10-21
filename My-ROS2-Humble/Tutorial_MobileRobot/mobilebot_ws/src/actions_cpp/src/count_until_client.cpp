#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "mobilebot_interfaces/action/count_until.hpp"

using CountUntil = mobilebot_interfaces::action::CountUntil;
using GoalHandleCountUntil = rclcpp_action::ClientGoalHandle<CountUntil>;
using namespace std::placeholders;

class CountUntilClientNode : public rclcpp::Node
{
private:
    rclcpp_action::Client<CountUntil>::SharedPtr count_client_;

    void goal_response_callback(const GoalHandleCountUntil::SharedPtr &goal_handle_)
    {
        if(!goal_handle_)
        {
            RCLCPP_INFO(this->get_logger(), "Goal got rejected.");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Goal got accepted.");
        }
    }

    // ------------------------------------------------------------------------
    //  This callback is automatically triggered when the action server finishes executing a goal and returns the result message.
    // ------------------------------------------------------------------------
    void goal_result_callback(const GoalHandleCountUntil::WrappedResult &result_)
    {
        int reached_num_ = result_.result->reached_number;
        RCLCPP_INFO(this->get_logger(), "Result: %d", reached_num_);
    }

public:
    // ------------------------------------------------------------------------
    //  Creates the action client and binds it to the "count_until" action topic.
    //  This does not yet send any goals — it only prepares the communication link.
    // ------------------------------------------------------------------------
    CountUntilClientNode() : Node("count_until_client")
    {
        count_client_ = rclcpp_action::create_client<CountUntil>(
            this,
            "count_until"
        );
    }

    // ------------------------------------------------------------------------
    //  Creates and sends a goal request to the action server.
    //  It waits until the server becomes available, builds the goal message,
    //  attaches callbacks, and sends the goal asynchronously.
    // ------------------------------------------------------------------------    
    void send_goal(int target_, double period_)
    {
        // wait for the action server
        count_client_->wait_for_action_server();

        // Prepare the goal message
        auto goal_ = CountUntil::Goal();
        goal_.target_number = target_;
        goal_.period = period_;

        // add callbacks
        auto options = rclcpp_action::Client<CountUntil>::SendGoalOptions();
        options.goal_response_callback = std::bind(&CountUntilClientNode::goal_response_callback, this, _1);
        options.result_callback = std::bind(&CountUntilClientNode::goal_result_callback, this, _1);

        // Send the goal asynchronously (non-blocking)
        RCLCPP_INFO(this->get_logger(), "sending the goal");
        count_client_->async_send_goal(goal_, options);
    }
};

int main(int argc, char**argv)
{
    // Initialize ROS2 communication
    // Create the client node as a shared pointer
    // Send a test goal (count to 6 with 1.0 second between counts)
    // Keep the node alive to handle callbacks and communication
    // Graceful shutdown
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CountUntilClientNode>();
    node->send_goal(6, 1.0);
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

