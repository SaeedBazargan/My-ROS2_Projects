#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

using namespace std::placeholders;

class move_keyboardcommandNode : public rclcpp::Node
{
private:
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_;
    std::thread input_thread_;
    bool running_;

    // Publish wheel speeds
    void sendCommand(const std::array<double, 4> &cmd)
    {
        std_msgs::msg::Float64MultiArray msg;

        msg.data = {cmd[0], cmd[1], cmd[2], cmd[3]};
        pub_->publish(msg);

        RCLCPP_INFO(this->get_logger(), "Sent: [%.2f %.2f %.2f %.2f]", cmd[0], cmd[1], cmd[2], cmd[3]);
    }

    // Handle keyboard input and send movement commands
    void handleKey(const std::string &key)
    {
        std::array<double, 4> cmd;

        if(key == "w" || key == "W")
        {
            cmd = {0.5,  0.5,  0.5,  0.5};
            RCLCPP_INFO(this->get_logger(), "Forward");
        }
        else if(key == "s" || key == "S")
        {
            cmd = {-0.5, -0.5, -0.5, -0.5};
            RCLCPP_INFO(this->get_logger(), "Backward");
        }
        else if(key == "a" || key == "A")
        {
            cmd = {-0.5, 0.5, -0.5, 0.5};
            RCLCPP_INFO(this->get_logger(), "Rotate Left");
        }
        else if(key == "d" || key == "D")
        {
            cmd = {0.5, -0.5, 0.5, -0.5};
            RCLCPP_INFO(this->get_logger(), "Rotate Right");
        }
        else if(key == "x" || key == "X")
        {
            cmd = {0.0, 0.0, 0.0, 0.0};
            RCLCPP_INFO(this->get_logger(), "Stop");
        }
        else if(key == "q" || key == "Q")
        {
            RCLCPP_INFO(this->get_logger(), "Quit requested");
            running_ = false;    // signal thread stop
            rclcpp::shutdown();  // allow clean exit

            return;
        }
        else
        {
            RCLCPP_WARN(this->get_logger(), "Unknown command");

            return;
        }

        sendCommand(cmd);
    }

    // Separate thread for keyboard input (blocking)
    void keyboardLoop()
    {
        std::string key;
        while(running_ && rclcpp::ok())
        {
            std::cout << "Command: ";
            std::cin >> key;
            handleKey(key);
        }
    }    

public:
    move_keyboardcommandNode() : Node("move_robot")
    {
        running_ = true;
        pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
            "/forward_velocity_controller/commands",
            10);
        
        RCLCPP_INFO(this->get_logger(), "Keyboard Teleop Started (w/s/a/d for move, x stop, q quit)");

        // Start keyboard input thread (non-blocking to ROS)
        input_thread_ = std::thread(&move_keyboardcommandNode::keyboardLoop, this);
    }

    ~move_keyboardcommandNode()
    {
        running_ = false;
        if(input_thread_.joinable())
        {
            input_thread_.join();
        }
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<move_keyboardcommandNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
