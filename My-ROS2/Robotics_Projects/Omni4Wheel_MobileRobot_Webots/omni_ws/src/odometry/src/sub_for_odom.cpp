
#include <cmath>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"

using std::placeholders::_1;

class OdomDistanceCalculator : public rclcpp::Node
{
public:
    OdomDistanceCalculator() : Node("odom_distance_calculator_node")
    {
        subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/diff_drive_controller/odom",
            10,
            std::bind(&OdomDistanceCalculator::odom_callback, this, _1));

        RCLCPP_INFO(this->get_logger(), "Odometry subscriber is ready. Listening on /diff_drive_controller/odom");

        total_distance_ = 0.0;
        first_message_ = true;
    }

    double get_total_distance() const
    {
        return total_distance_;
    }

private:
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;

    double previous_x_ = 0.0;
    double previous_y_ = 0.0;
    double total_distance_, distance_step_;
    bool first_message_;

    void odom_callback(const nav_msgs::msg::Odometry::ConstSharedPtr msg)
    {
        const double x = msg->pose.pose.position.x;
        const double y = msg->pose.pose.position.y;
        const double z = msg->pose.pose.position.z;

        const double qx = msg->pose.pose.orientation.x;
        const double qy = msg->pose.pose.orientation.y;
        const double qz = msg->pose.pose.orientation.z;
        const double qw = msg->pose.pose.orientation.w;

        const double linear_velocity = msg->twist.twist.linear.x;
        const double angular_velocity = msg->twist.twist.angular.z;

        // Calculate cumulative 2D distance
        if(first_message_)
        {
            previous_x_ = x;
            previous_y_ = y;
            first_message_ = false;
        }
        else
        {
            // Calculate distance from the previous position
            const double dx = x - previous_x_;
            const double dy = y - previous_y_;

            distance_step_ = std::sqrt((dx * dx) + (dy * dy));
            total_distance_ += distance_step_;

            previous_x_ = x;
            previous_y_ = y;
        }

        RCLCPP_INFO(this->get_logger(), "Frame ID: %s", msg->header.frame_id.c_str());
        RCLCPP_INFO(this->get_logger(), "Position: x=%.3f, y=%.3f, z=%.3f", x, y, z);
        RCLCPP_INFO(this->get_logger(), "Orientation: x=%.3f, y=%.3f, z=%.3f, w=%.3f", qx, qy, qz, qw);
        RCLCPP_INFO(this->get_logger(), "Velocity: linear=%.3f m/s, angular=%.3f rad/s", linear_velocity, angular_velocity);
        RCLCPP_INFO(this->get_logger(), "Total traveled distance: %.3f meters", total_distance_);
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<OdomDistanceCalculator>();
    rclcpp::spin(node);
    RCLCPP_INFO(node->get_logger(), "Final Distance Traveled: %.2f meters", node->get_total_distance());
    rclcpp::shutdown();

    return 0;
}
