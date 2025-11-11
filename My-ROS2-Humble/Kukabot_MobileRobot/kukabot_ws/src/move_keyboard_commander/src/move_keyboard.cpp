#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

using namespace std::placeholders;

class move_keyboardcommandNode : public rclcpp::Node
{
private:
    // Publisher to send wheel speed commands
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_;
    // Current wheel velocity command: [front_left, front_right, rear_left, rear_right]
    std::array<double, 4> wheel_cmd_{0.0, 0.0, 0.0, 0.0};

    // ------------------------------------------------------------------------
    // Send wheel velocity command to the robot
    // ------------------------------------------------------------------------    
    void set_velocity(double fl, double fr, double rl, double rr)
    {
        std_msgs::msg::Float64MultiArray msg;
        msg.data = {fl, fr, rl, rr};
        pub_->publish(msg);

        RCLCPP_INFO(this->get_logger(), "Sent: [%.2f %.2f %.2f %.2f]", fl, fr, rl, rr);
    }

    // ------------------------------------------------------------------------
    // Interpret key press and select matching wheel velocity pattern
    // ------------------------------------------------------------------------
    void handle_keypress(std::string &c)
    {
        if(c == "w" || c == "W")
        {
            wheel_cmd_ = {5.0, 5.0, 5.0, 5.0};
            set_velocity(wheel_cmd_[0], wheel_cmd_[1], wheel_cmd_[2], wheel_cmd_[3]);
            RCLCPP_INFO(this->get_logger(), "Forward (speed %.2f)", 5.0);
        }
        else if(c == "s" || c == "S")
        {
            wheel_cmd_ = {-5.0, -5.0, -5.0, -5.0};
            set_velocity(wheel_cmd_[0], wheel_cmd_[1], wheel_cmd_[2], wheel_cmd_[3]);
            RCLCPP_INFO(this->get_logger(), "Backward (speed %.2f)", 5.0);
        }
        else if(c == "a" || c == "A")
        {
            wheel_cmd_ = {-5.0, 5.0, -5.0, 5.0};
            set_velocity(wheel_cmd_[0], wheel_cmd_[1], wheel_cmd_[2], wheel_cmd_[3]);
            RCLCPP_INFO(this->get_logger(), "Rotate left (speed %.2f)", 5.0);
        }
        else if(c == "d" || c == "D")
        {
            wheel_cmd_ = {5.0, -5.0, 5.0, -5.0};
            set_velocity(wheel_cmd_[0], wheel_cmd_[1], wheel_cmd_[2], wheel_cmd_[3]);
            RCLCPP_INFO(this->get_logger(), "Rotate right (speed %.2f)", 5.0);
        }
        else if(c == "x" || c == "X")
        {
            wheel_cmd_ = {0.0, 0.0, 0.0, 0.0};
            set_velocity(wheel_cmd_[0], wheel_cmd_[1], wheel_cmd_[2], wheel_cmd_[3]);
            RCLCPP_INFO(this->get_logger(), "Stop");
        }
        else if(c == "q" || c == "Q")
        {
            RCLCPP_INFO(this->get_logger(), "Quit requested");
            rclcpp::shutdown();
        }
        else
        {
            RCLCPP_WARN(this->get_logger(), "Unknown command");
        }
    }

public:
    move_keyboardcommandNode() : Node("move_robot")
    {
        // Publisher queue depth = 10 messages
        pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
            "/forward_velocity_controller/commands",
            10);

        RCLCPP_INFO(this->get_logger(), "Keyboard Commander Started");
        RCLCPP_INFO(this->get_logger(), "w: forward, s: backward, a: left, d: right, x: stop, q: quit");

        // Blocking input loop
        run();
    }

    // ------------------------------------------------------------------------
    // Blocking input loop
    // Continuously reads user key input and sends robot commands
    // ------------------------------------------------------------------------
    void run()
    {
        std::string input;

        while(rclcpp::ok())
        {
            std::cout << "\n Command: ";
            std::cin >> input;

            handle_keypress(input);
    
            // sleep small amount so CPU not pegged
            usleep(20000); // 20 ms
        }
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<move_keyboardcommandNode>();
    // node->run();
    // rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
