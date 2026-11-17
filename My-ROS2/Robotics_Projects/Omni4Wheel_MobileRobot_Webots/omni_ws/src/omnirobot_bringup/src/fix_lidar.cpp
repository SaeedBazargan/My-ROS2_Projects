#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

#include <algorithm>
#include <memory>

class FixLIDAR : public rclcpp::Node
{
public:
    FixLIDAR() : Node("fix_lidar_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/myscan",
            rclcpp::SensorDataQoS(),
            std::bind(&FixLIDAR::topic_callback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<sensor_msgs::msg::LaserScan>(
            "/scan",
            rclcpp::SensorDataQoS());

        RCLCPP_INFO(get_logger(), "LiDAR correction node started.");
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr publisher_;

    void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        auto corrected_scan = *msg;
        // const int resolution = corrected_scan.ranges.size();
        // if(resolution < 2)
        // {
        //     return;
        // }

        // // Reverse LiDAR measurements
        // std::reverse(corrected_scan.ranges.begin(), corrected_scan.ranges.end());

        // // Reverse intensities if available
        // if(!corrected_scan.intensities.empty())
        // {
        //     std::reverse(corrected_scan.intensities.begin(), corrected_scan.intensities.end());
        // }

        // // Correct angular parameters
        // const double fov = std::abs(corrected_scan.angle_max - corrected_scan.angle_min);
        // corrected_scan.angle_increment = fov / (resolution - 1);
        // corrected_scan.angle_min = -fov / 2.0;
        // corrected_scan.angle_max = fov / 2.0;

        publisher_->publish(corrected_scan);
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FixLIDAR>());
    rclcpp::shutdown();

    return 0;
}