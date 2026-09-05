#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include "cv_bridge/cv_bridge.hpp"
#include <opencv2/opencv.hpp>

class LineFollowerNode : public rclcpp::Node
{
public:
    LineFollowerNode() : Node("line_follower_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera/image_raw",
            10,
            std::bind(&LineFollowerNode::listener_callback, this, std::placeholders::_1)
        );

        publisher_ = this->create_publisher<geometry_msgs::msg::TwistStamped>(
            "/omni_wheel_drive_controller/cmd_vel",
            10
        );

        RCLCPP_INFO(this->get_logger(), "Line follower started.");
    }

private:
    // Linear forward speed
    const double LINEAR_SPEED = 1.0;
    // Proportional gain
    const double KP = 1.5 / 100.0;
    
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr publisher_;

    // <---- ----- Get centroid of the largest contour ----- ---->
    bool get_contour_data(const cv::Mat &mask, cv::Point &centroid)
    {
        const double MIN_AREA_TRACK = 100.0;
        // Find contours 
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
        

        if(contours.empty())
        {
            return false;
        }

        // Find the largest contour
        double largest_area = 0.0;
        int largest_contour_index = -1;
        for(size_t i = 0; i < contours.size(); ++i)
        {
            double area = cv::contourArea(contours[i]);
            if(area > largest_area)
            {
                largest_area = area;
                largest_contour_index = static_cast<int>(i);
            }
        }

        // Ignore small contours
        if(largest_contour_index == -1 || largest_area < MIN_AREA_TRACK)
        {
            return false;
        }

        // Calculate moments of the largest contour
        cv::Moments M = cv::moments(contours[largest_contour_index]);

        // Avoid division by zero
        if(M.m00 == 0)
        {
            return false;
        }

        // Calculate centroid
        centroid.x = static_cast<int>(M.m10 / M.m00);
        centroid.y = static_cast<int>(M.m01 / M.m00);
        
        return true;
    }

    void listener_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        try
        {
            // Convert ROS Image message to OpenCV image
            cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
            cv::Mat current_frame = cv_ptr->image;

            // Convert BGR to HSV 
            cv::Mat hsv_image;
            cv::cvtColor(current_frame, hsv_image, cv::COLOR_BGR2HSV);

            // Define range of blue color in HSV 
            cv::Scalar lower_blue(100, 50, 50);
            cv::Scalar upper_blue(130, 255, 255);

            // Create a binary mask 
            cv::Mat blue_mask;
            cv::inRange(hsv_image, lower_blue, upper_blue, blue_mask);

            // Apply the mask to the original image
            cv::Mat blue_segmented_image;
            cv::bitwise_and(current_frame, current_frame, blue_segmented_image, blue_mask);

            // <---- ----- Detect line and get centroid ----- ---->
            cv::Point line_centroid;
            bool line_found = get_contour_data(blue_mask, line_centroid);

            // // Display centroid
            // if(line_found)
            // {
            //     cv::circle(blue_segmented_image, line_centroid, 5, cv::Scalar(0, 0, 255), 7);
            // }

            // <---- ----- Line following controller ----- ---->
            geometry_msgs::msg::TwistStamped cmd;
            cmd.header.stamp = this->get_clock()->now();
            cmd.header.frame_id = "base_link";

            int width = blue_segmented_image.cols;

            if(line_found)
            {
                int x = line_centroid.x;

                // Distance from image center
                int error = x - (width / 2);

                // Forward velocity
                cmd.twist.linear.x = LINEAR_SPEED;

                // Proportional steering controller
                cmd.twist.angular.z = -static_cast<double>(error) * KP;

                // Draw centroid
                cv::circle(blue_segmented_image, line_centroid, 5, cv::Scalar(0, 0, 255), 7);

                // Print controller information
                RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500, "Error: %d | Angular Z: %.3f", error, cmd.twist.angular.z);
            }
            else
            {
                // Line not detected
                cmd.twist.linear.x = 0.0;
                cmd.twist.angular.z = 1.0;

                RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Line not detected!");
            }

            // <---- ----- Publish velocity command ----- ---->
            publisher_->publish(cmd);

            // Display images
            cv::imshow("Blue Segmented Image", blue_segmented_image);
            cv::imshow("Blue Mask", blue_mask);
            cv::waitKey(1);
        }
        catch (const cv_bridge::Exception & e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
        }
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LineFollowerNode>();
    rclcpp::spin(node);
    cv::destroyAllWindows();
    rclcpp::shutdown();

    return 0;
}
