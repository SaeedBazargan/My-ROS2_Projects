#include "rclcpp/rclcpp.hpp"
#include "lifecycle_msgs/msg/transition.hpp"
#include "lifecycle_msgs/srv/change_state.hpp"
#include <thread>

class RobotMoveStartup : public rclcpp::Node
{
private:
    std::vector<std::string> node_name_list;
    std::string service_change_state_name;

    rclcpp::Client<lifecycle_msgs::srv::ChangeState>::SharedPtr client_;
    std::vector<rclcpp::Client<lifecycle_msgs::srv::ChangeState>::SharedPtr> client_list_;

public:
    RobotMoveStartup() : Node("lifecycle_manager")
    {
        // Declare and read parameter: the name of the managed lifecycle node
        this->declare_parameter<std::vector<std::string>>("managed_node_names", std::vector<std::string>{});
        node_name_list = this->get_parameter("managed_node_names").as_string_array();

        for(auto &node_name : node_name_list)
        {
            // Construct the service name: /<node_name>/change_state
            service_change_state_name = "/" + node_name + "/change_state";

            // Create a client to the ChangeState service of the target lifecycle node
            client_ = this->create_client<lifecycle_msgs::srv::ChangeState>(service_change_state_name);
            client_list_.push_back(client_);

            RCLCPP_INFO(this->get_logger(), "Lifecycle Manager started for node: %s", node_name.c_str());
        }
    }

    // ----------------------------------------------
    // Executes a basic lifecycle initialization sequence.
    // transition The desired transition to perform (configure, activate, etc.).
    // ----------------------------------------------
    void initialization_sequence(void)
    {
        // Step 1: Configure
        RCLCPP_INFO(this->get_logger(), "Trying to switch to configuring");

        lifecycle_msgs::msg::Transition transition_;

        transition_.id = lifecycle_msgs::msg::Transition::TRANSITION_CONFIGURE;
        transition_.label = "configure";

        change_state(transition_);

        RCLCPP_INFO(this->get_logger(), "Configuring OK, now inactive");

        // delay for 3 seconds
        std::this_thread::sleep_for(std::chrono::seconds(3));

        // Step 2: Activate
        RCLCPP_INFO(this->get_logger(), "Trying to switch to activating");

        transition_.id = lifecycle_msgs::msg::Transition::TRANSITION_ACTIVATE;
        transition_.label = "activate";

        change_state(transition_);

        RCLCPP_INFO(this->get_logger(), "Configuring OK, now inactive");        
    }

    // ----------------------------------------------
    // Sends a ChangeState request to the target lifecycle node.
    // transition The desired transition to perform (configure, activate, etc.).
    // ----------------------------------------------
    void change_state(const lifecycle_msgs::msg::Transition &transition_)
    {
        // auto node_name : node_name_list
        for(auto &client : client_list_)
        {
            // Wait for the target node's service to be available
            client->wait_for_service();

            // Prepare the request
            auto request_ = std::make_shared<lifecycle_msgs::srv::ChangeState::Request>();
            request_->transition = transition_;

            // Call the service asynchronously and wait for the result
            auto result_ = client->async_send_request(request_);
            rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_);

            RCLCPP_INFO(this->get_logger(), "Transition request '%s' (id: %d) sent.", transition_.label.c_str(), transition_.id);
        }
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotMoveStartup>();
    node->initialization_sequence();
    rclcpp::shutdown();

    return 0;
}

