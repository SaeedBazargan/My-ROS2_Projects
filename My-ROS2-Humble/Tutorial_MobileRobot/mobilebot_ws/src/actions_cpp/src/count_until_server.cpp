#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "mobilebot_interfaces/action/count_until.hpp"

using CountUntil = mobilebot_interfaces::action::CountUntil;
using GoalHandleCountUntil = rclcpp_action::ServerGoalHandle<CountUntil>;
using namespace std::placeholders;

class CountUntilServerNode : public rclcpp::Node
{
private:
    rclcpp_action::Server<CountUntil>::SharedPtr count_server_;
    rclcpp::CallbackGroup::SharedPtr callback_group_;
    std::shared_ptr<GoalHandleCountUntil> multiple_goal_handle_;
    std::mutex mutex_;

    // ---------------------------------------------------------
    // Called when a client sends a new goal request.
    // Decide here whether to accept or reject the goal.
    // ---------------------------------------------------------
    rclcpp_action::GoalResponse goal_callback(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const CountUntil::Goal> goal_)
    {
        (void) uuid;
        RCLCPP_INFO(this->get_logger(), "Received a new goal request.");

        // Policy_1: Refuse new goal if one goal is being active.
        std::lock_guard<std::mutex> lock(mutex_);

        if(multiple_goal_handle_ && multiple_goal_handle_->is_active())
        {
            RCLCPP_WARN(this->get_logger(), "Rejecting new goal: another goal is active.");
            return rclcpp_action::GoalResponse::REJECT;
        }

        if(goal_->target_number <= 0.0)
        {
            RCLCPP_ERROR(this->get_logger(), "Rejecting the goal: Invalid Input.");

            return rclcpp_action::GoalResponse::REJECT;
        }

        RCLCPP_INFO(this->get_logger(), "Accepting the goal");

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    // ---------------------------------------------------------
    // Called when a client requests goal cancellation.
    // Decide whether to accept or reject the cancellation.
    // ---------------------------------------------------------
    rclcpp_action::CancelResponse cancel_callback(const std::shared_ptr<GoalHandleCountUntil> goal_handle_)
    {
        (void) goal_handle_;
        RCLCPP_INFO(this->get_logger(), "Received cancel request");

        return rclcpp_action::CancelResponse::ACCEPT;
    }

    // ---------------------------------------------------------
    // Called once a goal has been accepted. This launches the goal execution in a separate thread.
    // ---------------------------------------------------------
    void handle_accepted_callback(const std::shared_ptr<GoalHandleCountUntil> goal_handle_)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            this->multiple_goal_handle_ = goal_handle_;
        }

        RCLCPP_INFO(this->get_logger(), "executing the goal");
        execute_goal(goal_handle_);
    }

    // ---------------------------------------------------------
    // Main goal execution logic. Performs the counting process and sends feedback to the client.
    // ---------------------------------------------------------
    void execute_goal(const std::shared_ptr<GoalHandleCountUntil> goal_handle_)
    {
        // Extract goal parameters
        int target_num_ = goal_handle_->get_goal()->target_number;
        double period_num_ = goal_handle_->get_goal()->period;

        // Execute the action
        auto feedback_ = std::make_shared<CountUntil::Feedback>();
        auto result_ = std::make_shared<CountUntil::Result>();

        rclcpp::Rate loop_rate_(1.0 / period_num_);     // frequency of the rate
        int counter = 0;
        
        for(int i = 0; i < target_num_; i++)
        {
            if(goal_handle_->is_canceling())        // Check for cancellation request
            {
                result_->reached_number = counter;
                goal_handle_->canceled(result_);
                
                return;
            }
            else
            {
                counter++;
                RCLCPP_INFO(this->get_logger(), "%d", counter);
                
                // send feedback to the client
                feedback_->current_number = counter;
                goal_handle_->publish_feedback(feedback_);
                
                loop_rate_.sleep();
            }
        }

        // set final state and return the result
        result_->reached_number = counter;

        goal_handle_->succeed(result_);
    }

public:
    CountUntilServerNode() : Node("count_until_server")
    {
        callback_group_ = create_callback_group(rclcpp::CallbackGroupType::Reentrant);
        
        // --- Create the Action Server ---
        // This sets up the "count_until" action server, registering three callbacks:
        // 1. goal_callback()    → to accept/reject incoming goals
        // 2. cancel_callback()  → to handle cancellation requests
        // 3. handle_accepted_callback() → to start goal execution once accepted
        count_server_ = rclcpp_action::create_server<CountUntil>(
            this,
            "count_until",
            std::bind(&CountUntilServerNode::goal_callback, this, _1, _2),
            std::bind(&CountUntilServerNode::cancel_callback, this, _1),
            std::bind(&CountUntilServerNode::handle_accepted_callback, this, _1),
            rcl_action_server_get_default_options(),
            callback_group_
        );
        RCLCPP_INFO(this->get_logger(), "Actions Server is ready");
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CountUntilServerNode>();

    // Use a multithreaded executor to handle callbacks concurrently
    rclcpp::executors::MultiThreadedExecutor executor_;
    executor_.add_node(node);
    executor_.spin();
    
    // rclcpp::spin(node);     // this is a single thread executor
    rclcpp::shutdown();

    return 0;
}

