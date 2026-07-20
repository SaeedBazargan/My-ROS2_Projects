#include <iostream>
#include <unistd.h>

#include "rclcpp/rclcpp.hpp"
#include "talk_to_mcu_interfaces/msg/num.hpp"
#include "talk_to_mcu_pkg/MySerial.hpp"

class SerialNode : public rclcpp::Node
{
private:
    SerialPort serial;
    std::string portname = "/dev/ttyUSB0";
    int baudrate = B9600;
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Time _timestamp;
    
    int8_t _state = 0;
    uint8_t left_speed, right_speed, left_dir, right_dir;

    void timer_callback()
    {
        rclcpp::Time now = this->get_clock()->now();
        rclcpp::Duration elapsed = now - _timestamp;
        
        if(elapsed.seconds() >= 1.0)
        {
            _timestamp = now;
            _state += 1;
            if(_state >= 3)
            {
                _state = 0;
            }

            RCLCPP_INFO(this->get_logger(), "State: %d", _state);
        }

        if(_state == 0)
        {
            left_speed = 25;
            right_speed = 50;
            left_dir = 0;
            right_dir = 0;
        }
        else if(_state == 1)
        {
            left_speed = 100;
            right_speed = 100;
            left_dir = 1;
            right_dir = 0;
        }
        else
        {
            left_speed = 0;
            right_speed = 0;
            left_dir = 1;
            right_dir = 0;
        }

        std::string data = std::to_string(left_speed) + ", " + 
                        std::to_string(right_speed) + ", " + 
                        std::to_string(left_dir) + ", " + 
                        std::to_string(right_dir);
        serial.serialWrite(data);

        // Wait for echo
        sleep(1);

        // Read
        std::string response = serial.serialRead(100);
        if(!response.empty())
        {
            std::cout << "Received: " << response << std::endl;
        }
    }

    void subCallback(const talk_to_mcu_interfaces::msg::Num::SharedPtr msg)
    {
        // Print to console
        std::cout << "Red circle found at: Bounding Box: x=" << msg->x << ", y=" << msg->y 
                    << ", w=" << msg->width << ", h=" << msg->height 
                    << std::endl;
    }
    
    rclcpp::Subscription<talk_to_mcu_interfaces::msg::Num>::SharedPtr sub_camera_;

public:
    SerialNode() : Node("serialDemo")
    {
        // Open port
        if(!serial.serialOpen("/dev/ttyUSB0", B9600))
        {
            std::cerr << "Failed to open serial port" << std::endl;
            rclcpp::shutdown();
            return;
        }

        std::cout << "Serial port opened!" << std::endl;

        _timestamp = this->get_clock()->now();

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(2000),
            std::bind(&SerialNode::timer_callback, this)
        );

        sub_camera_ = this->create_subscription<talk_to_mcu_interfaces::msg::Num>("ball_topic", 10,
        std::bind(&SerialNode::subCallback, this, std::placeholders::_1));
    }

    ~SerialNode()
    {
        if(serial.serial_isOpen())
        {
            serial.serialClose();
        }
    }
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SerialNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

