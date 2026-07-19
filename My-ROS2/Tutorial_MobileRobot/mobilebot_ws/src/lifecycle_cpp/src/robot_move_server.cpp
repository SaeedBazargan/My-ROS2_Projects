#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "mobilebot_interfaces/action/robot_move.hpp"


using RobotMove = mobilebot_interfaces::action::RobotMove;
using GoalHandleRobotMove = rclcpp_action::ServerGoalHandle<RobotMove>;
using LifecycleCallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;
using namespace std::placeholders;

// ----------------------------------------------------
// RobotMoveServerNode: A lifecycle-aware ROS2 Action Server
// This node provides the "robot_move" action, handling goal requests, cancellations, and preemption with proper lifecycle state transitions.
// ----------------------------------------------------
class RobotMoveServerNode : public rclcpp_lifecycle::LifecycleNode
{
private:
    rclcpp_action::Server<RobotMove>::SharedPtr robot_move_;
    rclcpp::CallbackGroup::SharedPtr callback_group_;
    std::shared_ptr<GoalHandleRobotMove> multiple_goal_handle_;     // Handle to the currently active goal (used for preemption/cancellation)

    bool server_activated_ = false;     // Flag indicating if the action server is currently active

    // ----------------------------------------------------
    // Lifecycle callback: called when node transitions from "unconfigured" → "inactive".
    // Initializes resources and creates the action server.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_configure(const rclcpp_lifecycle::State &previous_state_)
    {
        (void)previous_state_;

        RCLCPP_INFO(this->get_logger(), "In on_configure state.");

        // Create a reentrant callback group to allow multiple callbacks to execute concurrently within this node.
        callback_group_ = create_callback_group(rclcpp::CallbackGroupType::Reentrant);

        // --- Create the Action Server ---
        // This sets up the "count_until" action server, registering three callbacks:
        // 1. goal_callback()    → to accept/reject incoming goals
        // 2. cancel_callback()  → to handle cancellation requests
        // 3. accepted_callback() → to start goal execution once accepted
        robot_move_ = rclcpp_action::create_server<RobotMove>(
            this,
            "robot_move",
            std::bind(&RobotMoveServerNode::goal_callback, this, _1, _2),
            std::bind(&RobotMoveServerNode::cancel_callback, this, _1),
            std::bind(&RobotMoveServerNode::accepted_callback, this, _1),
            rcl_action_server_get_default_options(),
            callback_group_
        );
        RCLCPP_INFO(this->get_logger(), "Action Server is ready and successfully configured.");

        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Lifecycle callback: "cleanup" state. Destroys created resources.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_cleanup(const rclcpp_lifecycle::State &previous_state_)
    {
        (void)previous_state_;

        RCLCPP_INFO(this->get_logger(), "In on_cleanup state.");

        robot_move_.reset();        // To destroy the action server: reset the shared pointer

        return LifecycleCallbackReturn::SUCCESS;
        
    }

    // ----------------------------------------------------
    // Lifecycle callback: "activate" state. Enables goal acceptance.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_activate(const rclcpp_lifecycle::State &previous_state_)
    {
        RCLCPP_INFO(this->get_logger(), "In on_activate state.");

        server_activated_ = true;

        rclcpp_lifecycle::LifecycleNode::on_activate(previous_state_);

        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Called when transitioning from "active" to "inactive".
    // Disables goal acceptance and Prevents new goals from being accepted and aborts running goals.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_deactivate(const rclcpp_lifecycle::State &previous_state_)
    {
        RCLCPP_INFO(this->get_logger(), "In on_deactivate state.");

        server_activated_ = false;

        if(multiple_goal_handle_ && multiple_goal_handle_->is_active())
        {
            RCLCPP_WARN(this->get_logger(), "A goal is running, aborting it for the new one.");

            multiple_goal_handle_.reset();
        }

        rclcpp_lifecycle::LifecycleNode::on_deactivate(previous_state_);

        return LifecycleCallbackReturn::SUCCESS;
    }

    // ----------------------------------------------------
    // Lifecycle callback: "shutdown" state. Cleans up before node termination.
    // ----------------------------------------------------
    LifecycleCallbackReturn on_shutdown(const rclcpp_lifecycle::State &previous_state_)
    {
        (void)previous_state_;

        RCLCPP_INFO(this->get_logger(), "In on_shutdown state.");

        robot_move_.reset();        // To destroy the action server: reset the shared pointer

        return LifecycleCallbackReturn::SUCCESS;
        
    }

    // ------------------------------------------------------------------------
    // Called when a client sends a new goal request.
    // Decide here whether to accept or reject the goal.
    // ------------------------------------------------------------------------
    rclcpp_action::GoalResponse goal_callback(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const RobotMove::Goal> goal_)
    {
        (void) uuid;
        (void) goal_;
        RCLCPP_INFO(this->get_logger(), "Received a new goal request.");

        // Validate server activates
        if(!server_activated_)
        {
            RCLCPP_WARN(this->get_logger(), "Node not activate yet.");

            return rclcpp_action::GoalResponse::REJECT;
        }

        if(goal_->goalposition < 0 || goal_->goalposition > 100)
        {
            RCLCPP_ERROR(this->get_logger(), "Rejecting the goal: Invalid Input.");

            return rclcpp_action::GoalResponse::REJECT;            
        }

        // Abort any currently running goal before accepting a new one.
        if(multiple_goal_handle_ && multiple_goal_handle_->is_active())
        {
            RCLCPP_WARN(this->get_logger(), "A goal is running, aborting it for the new one.");

            multiple_goal_handle_.reset();  // mark as no longer active            
        }

        RCLCPP_INFO(this->get_logger(), "Accepting the goal");

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;        
    }

    // ------------------------------------------------------------------------
    // Called when a client requests goal cancellation.
    // Decide whether to accept or reject the cancellation.
    // ------------------------------------------------------------------------
    rclcpp_action::CancelResponse cancel_callback(const std::shared_ptr<GoalHandleRobotMove> goal_handle_)
    {
        (void) goal_handle_;
        RCLCPP_INFO(this->get_logger(), "Received cancel request");
        
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    // ------------------------------------------------------------------------
    // Called once a goal has been accepted. This launches the goal execution in a separate thread.
    // ------------------------------------------------------------------------
    void accepted_callback(const std::shared_ptr<GoalHandleRobotMove> goal_handle_)
    {
        (void) goal_handle_;
        RCLCPP_INFO(this->get_logger(), "executing the goal");
        
        multiple_goal_handle_ = goal_handle_;

        execute_goal(goal_handle_);
    }

    // ------------------------------------------------------------------------
    // Main goal execution logic. Performs the counting process and sends feedback to the client.
    // ------------------------------------------------------------------------
    void execute_goal(const std::shared_ptr<GoalHandleRobotMove> goal_handle_)
    {
        uint8_t goalpos_ = goal_handle_->get_goal()->goalposition;
        uint8_t goalvel_ = goal_handle_->get_goal()->goalvelocity;

        auto feedback_ = std::make_shared<RobotMove::Feedback>();
        auto result_ = std::make_shared<RobotMove::Result>();

        const uint8_t init_position = 50;
        uint8_t position_ = init_position;
        const int direction = (goalpos_ >= init_position) ? 1 : -1;
        const uint8_t steps = std::abs(goalpos_ - init_position);

        rclcpp::Rate loop_rate_(1.0 / goalvel_);     // frequency of the rate

        for(uint8_t i = 0; i < steps; i++)
        {
            // Check for cancel request
            if(goal_handle_->is_canceling())
            {
                RCLCPP_WARN(this->get_logger(), "Goal canceled by client.");

                result_->position = position_;
                goal_handle_->canceled(result_);
                
                if(multiple_goal_handle_ == goal_handle_)
                {
                    multiple_goal_handle_.reset();
                }

                return;
            }

            // Handle preemption: if a new goal replaced this one
            if(multiple_goal_handle_ != goal_handle_)
            {
                RCLCPP_WARN(this->get_logger(), "Goal preempted by a new goal. Or server(node) deactivated");

                result_->position = position_;
                goal_handle_->abort(result_);

                return;
            }

            position_ += direction;
            feedback_->current_position = position_;
            goal_handle_->publish_feedback(feedback_);

            RCLCPP_INFO(this->get_logger(), "%d", position_);
            loop_rate_.sleep();
        }

        result_->position = position_;
        goal_handle_->succeed(result_);

        if(multiple_goal_handle_ == goal_handle_)
        {
            multiple_goal_handle_.reset();
        }
    }

public:
    RobotMoveServerNode() : LifecycleNode("robot_move_server")
    {
        RCLCPP_INFO(this->get_logger(), "In unconfigured state.");
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotMoveServerNode>();

    // Use a multithreaded executor to handle callbacks concurrently
    rclcpp::executors::MultiThreadedExecutor executor_;
    executor_.add_node(node->get_node_base_interface());
    executor_.spin();

    rclcpp::shutdown();

    return 0;
}


