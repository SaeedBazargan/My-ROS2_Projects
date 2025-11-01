#include <queue>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "mobilebot_interfaces/action/count_until.hpp"

using CountUntil = mobilebot_interfaces::action::CountUntil;
using GoalHandleCountUntil = rclcpp_action::ServerGoalHandle<CountUntil>;
using namespace std::placeholders;

class CountUntilServerNode : public rclcpp::Node
{
private:
    // 1- Action server instance
    // 2- For concurrency control
    // 3- Protects access to goal queue
    // 4- Stores incoming goals (FIFO)
    // 5- Background worker thread
    rclcpp_action::Server<CountUntil>::SharedPtr count_server_;
    rclcpp::CallbackGroup::SharedPtr callback_group_;
    std::mutex mutex_;
    std::queue<std::shared_ptr<GoalHandleCountUntil>> goal_queue_;
    std::thread goal_queue_thread_;

    // ---------------------------------------------------------
    // Called when a client sends a new goal request.
    // Decide here whether to accept or reject the goal.
    // ---------------------------------------------------------
    rclcpp_action::GoalResponse goal_callback(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const CountUntil::Goal> goal_)
    {
        (void) uuid;
        RCLCPP_INFO(this->get_logger(), "Received a new goal request.");

        if(goal_->target_number <= 0.0)
        {
            RCLCPP_ERROR(this->get_logger(), "Rejecting the goal: Invalid Input.");

            return rclcpp_action::GoalResponse::REJECT;
        }

        RCLCPP_INFO(this->get_logger(), "Accepting the goal");

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    // ---------------------------------------------------------
    // Called once a goal has been accepted. 
    // The accepted goal is added to the queue and will be executed when it reaches the front of the queue.
    // ---------------------------------------------------------
    void handle_accepted_callback(const std::shared_ptr<GoalHandleCountUntil> goal_handle_)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        goal_queue_.push(goal_handle_);

        RCLCPP_INFO(this->get_logger(), "Add goal to the queue.");
        RCLCPP_INFO(this->get_logger(), "Queue size: %d", (int)goal_queue_.size());
    }

    // ---------------------------------------------------------
    // When a goal is available, it executes it using execute_goal().
    // This ensures that only one goal is active at a time.
    // ---------------------------------------------------------
    void run_goal_queue_thread()
    {
        rclcpp::Rate loop_rate(1000.0);

        while(rclcpp::ok())
        {
            std::shared_ptr<GoalHandleCountUntil> next_goal_;

            // Safely check and pop from the queue
            {
                std::lock_guard<std::mutex> lock(mutex_);

                if(!goal_queue_.empty())
                {
                    next_goal_ = goal_queue_.front();
                    goal_queue_.pop();
                }
            }

            // Execute the next goal if available
            if(next_goal_)
            {
                RCLCPP_INFO(this->get_logger(), "Execute the next goal in queue.");
                execute_goal(next_goal_);
            }

            loop_rate.sleep();
        }
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
        
        // Launch background thread to process queued goals
        goal_queue_thread_ = std::thread(&CountUntilServerNode::run_goal_queue_thread, this);

        RCLCPP_INFO(this->get_logger(), "Actions Server is ready");
    }

    // gracefully stops the worker thread before node destruction.
    ~CountUntilServerNode()
    {
        goal_queue_thread_.join();
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

