#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "mobilebot_interfaces/action/robot_move.hpp"
#include "std_msgs/msg/bool.hpp"

using RobotMove = mobilebot_interfaces::action::RobotMove;
using GoalHandleRobotMove = rclcpp_action::ClientGoalHandle<RobotMove>;
using namespace std::placeholders;


class RobotMoveClientNode : public rclcpp::Node
{
private:
    rclcpp_action::Client<RobotMove>::SharedPtr robot_move_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr cancel_sub_;
    GoalHandleRobotMove::SharedPtr active_goal_;   // store active goal handle for canceling

    // ------------------------------------------------------------------------
    // Handle goal acceptance or rejection
    // ------------------------------------------------------------------------
    void goal_response_callback(const GoalHandleRobotMove::SharedPtr &goal_handle_)
    {
        if(!goal_handle_)
        {
            RCLCPP_WARN(this->get_logger(), "Goal got rejected.");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Goal got accepted.");
            active_goal_ = goal_handle_;
        }        
    }

    // ------------------------------------------------------------------------
    // Handle result from server
    // ------------------------------------------------------------------------
    void goal_result_callback(const GoalHandleRobotMove::WrappedResult &result_)
    {
        auto status_ = result_.code;
        if(status_ == rclcpp_action::ResultCode::SUCCEEDED)
        {
            RCLCPP_INFO(this->get_logger(), "Succeeded.");
        }
        else if(status_ == rclcpp_action::ResultCode::ABORTED)
        {
            RCLCPP_ERROR(this->get_logger(), "Aborted.");
        }
        else if(status_ == rclcpp_action::ResultCode::CANCELED)
        {
            RCLCPP_WARN(this->get_logger(), "Canceled.");
        }        

        uint8_t reached_pos_ = result_.result->position;
        RCLCPP_INFO(this->get_logger(), "Result: %d", reached_pos_);

        active_goal_.reset();  // clear active goal handle after completion
    }

    // ------------------------------------------------------------------------
    // Handle feedback from server
    // ------------------------------------------------------------------------
    void goal_feedback_callback(const GoalHandleRobotMove::SharedPtr &goal_handle_, const std::shared_ptr<const RobotMove::Feedback> feedback_)
    {
        (void) goal_handle_;
        uint8_t num_ = feedback_->current_position;
        RCLCPP_INFO(this->get_logger(), "Feedback: %d", num_);
    }

    // ------------------------------------------------------------------------
    // Handle cancel command from topic
    // ------------------------------------------------------------------------
    void cancel_callback(const std_msgs::msg::Bool::SharedPtr msg_)
    {
        if(msg_->data && active_goal_)
        {
            RCLCPP_WARN(this->get_logger(), "Cancel request received. Canceling goal...");
            robot_move_->async_cancel_goal(active_goal_);
        }
    }

public:
    RobotMoveClientNode() : Node("robot_move_client")
    {
        robot_move_ = rclcpp_action::create_client<RobotMove>(
            this, 
            "robot_move"
        );

        // Subscriber for cancel topic
        cancel_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/cancel_move",
            10,
            std::bind(&RobotMoveClientNode::cancel_callback, this, _1)
        );
    }

    // ------------------------------------------------------------------------
    //
    // ------------------------------------------------------------------------
    void send_goal(uint8_t goalpos_, uint8_t goalvel_)
    {
        robot_move_->wait_for_action_server();

        auto goal_ = RobotMove::Goal();
        goal_.goalposition = goalpos_;
        goal_.goalvelocity = goalvel_;

        auto options = rclcpp_action::Client<RobotMove>::SendGoalOptions();
        options.goal_response_callback = std::bind(&RobotMoveClientNode::goal_response_callback, this, _1);
        options.result_callback = std::bind(&RobotMoveClientNode::goal_result_callback, this, _1);
        options.feedback_callback = std::bind(&RobotMoveClientNode::goal_feedback_callback, this, _1, _2);

        // Send the goal asynchronously (non-blocking)
        RCLCPP_INFO(this->get_logger(), "sending the goal");
        robot_move_->async_send_goal(goal_, options);
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotMoveClientNode>();
    node->send_goal(76, 1);         // just for test
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

