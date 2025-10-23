#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "mobilebot_interfaces/action/robot_move.hpp"


using RobotMove = mobilebot_interfaces::action::RobotMove;
using GoalHandleRobotMove = rclcpp_action::ServerGoalHandle<RobotMove>;
using namespace std::placeholders;

class RobotMoveServerNode : public rclcpp::Node
{
private:
    rclcpp_action::Server<RobotMove>::SharedPtr robot_move_;

    rclcpp_action::GoalResponse goal_callback(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const RobotMove::Goal> goal_)
    {
        (void) uuid;
        (void) goal_;
        RCLCPP_INFO(this->get_logger(), "Received a new goal request.");

        if(goal_->goalposition < 0 || goal_->goalposition > 100)
        {
            RCLCPP_ERROR(this->get_logger(), "Rejecting the goal: Invalid Input.");

            return rclcpp_action::GoalResponse::REJECT;            
        }

        RCLCPP_INFO(this->get_logger(), "Accepting the goal");

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;        
    }

    rclcpp_action::CancelResponse cancel_callback(const std::shared_ptr<GoalHandleRobotMove> goal_handle_)
    {
        (void) goal_handle_;
        RCLCPP_INFO(this->get_logger(), "Received cancel request");

        return rclcpp_action::CancelResponse::ACCEPT;        
    }

    void accepted_callback(const std::shared_ptr<GoalHandleRobotMove> goal_handle_)
    {
        (void) goal_handle_;
        RCLCPP_INFO(this->get_logger(), "executing the goal");
    }

public:
    RobotMoveServerNode() : Node("robot_move_server")
    {
        robot_move_ = rclcpp_action::create_server<RobotMove>(
            this,
            "robot_move",
            std::bind(&RobotMoveServerNode::goal_callback, this, _1, _2),
            std::bind(&RobotMoveServerNode::cancel_callback, this, _1),
            std::bind(&RobotMoveServerNode::accepted_callback, this, _1)
            // accepted_callback,
            // rcl_action_server_get_default_options(),
            // callback_group
        );
        RCLCPP_INFO(this->get_logger(), "Action Server is ready");
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotMoveServerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}


