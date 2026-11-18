#include <cmath>
#include <chrono>
#include <functional>
#include <memory>
#include <algorithm>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "nav_msgs/msg/odometry.hpp"

class SquareMover : public rclcpp::Node
{
public:
    SquareMover() : Node("square_mover_node")
    {
        // Publisher: TwistStamped
        cmd_pub_ = this->create_publisher<geometry_msgs::msg::TwistStamped>(
            "/diff_drive_controller/cmd_vel", 10);

        // Odometry subscriber
        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odometry/filtered",
            10,
            std::bind(&SquareMover::odom_callback, this, std::placeholders::_1));

        // Control loop timer: 50 Hz
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20),
            std::bind(&SquareMover::control_loop, this));

        // Parameters
        side_length_ = 1.0;
        linear_speed_ = 0.2;

        // Coarse turn
        angular_speed_coarse_ = 0.4;
        angle_coarse_thresh_ = 6.0 * PI / 180.0;

        // Fine turn
        angular_speed_fine_ = 0.15;
        angle_tolerance_fine_ = 0.5 * PI / 180.0;

        dist_tolerance_ = 0.01;

        // Internal state
        state_ = State::WAIT_FOR_ODOM;

        sides_completed_ = 0;
        total_sides_ = 4;

        RCLCPP_INFO(this->get_logger(), "SquareMover node started. Waiting for odometry...");
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr cmd_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    static constexpr double PI = 3.14159;

    // State machine
    enum class State
    {
        WAIT_FOR_ODOM,
        FORWARD,
        TURN_COARSE,
        TURN_FINE,
        STOP
    };

    double side_length_;
    double linear_speed_;

    double angular_speed_coarse_;
    double angle_coarse_thresh_;

    double angular_speed_fine_;
    double angle_tolerance_fine_;

    double dist_tolerance_;

    // Internal state
    double current_x_{0.0};
    double current_y_{0.0};
    double current_yaw_{0.0};

    double start_x_{0.0};
    double start_y_{0.0};

    double turn_start_yaw_{0.0};
    double turn_target_yaw_{0.0};

    State state_;

    int sides_completed_;
    int total_sides_;

    bool odom_received_{false};

    double yaw_from_quaternion(const geometry_msgs::msg::Quaternion &q)
    {
        const double siny_cosp = 2.0 * (q.w * q.z + q.x * q.y);
        const double cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z);

        return std::atan2(siny_cosp, cosy_cosp);
    }

    double normalize_angle(double angle)
    {
        while(angle > PI)
        {
            angle -= 2.0 * PI;
        }

        while(angle < -PI)
        {
            angle += 2.0 * PI;
        }

        return angle;
    }

    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        // Update current pose
        current_x_ = msg->pose.pose.position.x;
        current_y_ = msg->pose.pose.position.y;
        current_yaw_ = yaw_from_quaternion(msg->pose.pose.orientation);

        odom_received_ = true;

        // Initialize start pose once
        if(state_ == State::WAIT_FOR_ODOM)
        {
            start_x_ = current_x_;
            start_y_ = current_y_;

            state_ = State::FORWARD;

            RCLCPP_INFO(this->get_logger(), "Received first odom. Starting square motion.");
        }
    }

    void publish_cmd(const geometry_msgs::msg::Twist &twist)
    {
        geometry_msgs::msg::TwistStamped msg;

        msg.header.stamp = this->now();
        msg.header.frame_id = "base_link";

        msg.twist = twist;

        cmd_pub_->publish(msg);
    }

    void start_turn()
    {
        turn_start_yaw_ = current_yaw_;
        turn_target_yaw_ = normalize_angle(turn_start_yaw_ + PI / 2.0);

        state_ = State::TURN_COARSE;

        RCLCPP_INFO(this->get_logger(), "Starting turn. Target yaw: %.2f degrees", turn_target_yaw_ * 180.0 / PI);
    }

    geometry_msgs::msg::Twist control_turn(bool coarse)
    {
        geometry_msgs::msg::Twist twist;

        // Calculate angular error
        const double error = normalize_angle(turn_target_yaw_ - current_yaw_);
        if(coarse)
        {
            // Coarse turning
            if(std::abs(error) < angle_coarse_thresh_)
            {
                state_ = State::TURN_FINE;

                RCLCPP_INFO(this->get_logger(), "Coarse turn done. Switching to fine control.");

                return twist;
            }

            const double k_ang = 1.2;
            double ang_cmd = k_ang * error;

            ang_cmd = std::clamp(ang_cmd, -angular_speed_coarse_, angular_speed_coarse_);
            twist.angular.z = ang_cmd;

            return twist;
        }
        else
        {
            // Fine turning
            if(std::abs(error) < angle_tolerance_fine_)
            {
                twist.angular.z = 0.0;
                sides_completed_++;

                RCLCPP_INFO(this->get_logger(), "Turn completed. Sides done: %d/%d", sides_completed_, total_sides_);

                if(sides_completed_ >= total_sides_)
                {
                    state_ = State::STOP;

                    RCLCPP_INFO(this->get_logger(), "Square completed. Stopping.");
                }
                else
                {
                    // Prepare for the next side
                    start_x_ = current_x_;
                    start_y_ = current_y_;

                    state_ = State::FORWARD;
                }

                return twist;
            }

            const double k_ang = 1.0;
            double ang_cmd = k_ang * error;

            ang_cmd = std::clamp(ang_cmd, -angular_speed_fine_, angular_speed_fine_);
            twist.angular.z = ang_cmd;

            return twist;
        }
    }

    void control_loop()
    {
        if(!odom_received_)
        {
            return;
        }

        geometry_msgs::msg::Twist twist;

        switch(state_)
        {
            case State::FORWARD:
            {
                // Distance from starting point
                const double dx = current_x_ - start_x_;
                const double dy = current_y_ - start_y_;
                const double dist = std::sqrt(dx * dx + dy * dy);

                if(dist >= side_length_ - dist_tolerance_)
                {
                    // Stop and start turning
                    twist.linear.x = 0.0;
                    twist.angular.z = 0.0;

                    publish_cmd(twist);

                    start_turn();

                    return;
                }

                // Drive straight
                twist.linear.x = linear_speed_;
                twist.angular.z = 0.0;

                break;
            }

            case State::TURN_COARSE:
            {
                twist = control_turn(true);
                break;
            }

            case State::TURN_FINE:
            {
                twist = control_turn(false);
                break;
            }

            case State::STOP:
            {
                twist.linear.x = 0.0;
                twist.angular.z = 0.0;
                break;
            }

            case State::WAIT_FOR_ODOM:
            default:
            {
                twist.linear.x = 0.0;
                twist.angular.z = 0.0;
                break;
            }
        }

        publish_cmd(twist);
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SquareMover>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}