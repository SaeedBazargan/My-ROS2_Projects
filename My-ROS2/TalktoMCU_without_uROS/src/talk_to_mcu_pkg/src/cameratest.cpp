#include <iostream>
#include <vector>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include <opencv2/opencv.hpp>

class CameraNode : public rclcpp::Node
{
private:
    cv::VideoCapture cam;
    cv::Mat frame, hsv, mask, mask1, mask2;
    rclcpp::TimerBase::SharedPtr timer_;

    // Get the default frame width and height
    int frame_width;
    int frame_height;

    // Red color range in HSV (two ranges because red wraps around 0/180)
    cv::Scalar lower_color1{0, 100, 50};    // Lower HSV bounds for RED (range 1)
    cv::Scalar upper_color1{10, 255, 255};  // Upper HSV bounds for RED (range 1)

    cv::Scalar lower_color2{160, 100, 50};  // Lower HSV bounds for RED (range 2)
    cv::Scalar upper_color2{179, 255, 255}; // Upper HSV bounds for RED (range 2)


    // Minimum circularity threshold (1.0 = perfect circle)
    const double MIN_CIRCULARITY = 0.7;

    // Minimum area to detect (to ignore small noise)
    const double MIN_AREA = 100; // pixels


    // Function to check if a contour is circular
    bool isCircular(const std::vector<cv::Point>& contour, double& circularity, double min_circularity = 0.7)
    {
        // Calculate area and perimeter
        double area = cv::contourArea(contour);
        double perimeter = cv::arcLength(contour, true);
        
        if(perimeter <= 0 || area <= 0)
            return false;
        
        // Calculate circularity: 4*pi*area / (perimeter^2)
        // Perfect circle = 1.0, square ≈ 0.78, line ≈ 0
        circularity = 4 * CV_PI * area / (perimeter * perimeter);
        
        return circularity >= min_circularity;
    }

    void timer_callback()
    {
        // Capture frame
        cam >> frame;
        if(frame.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "Error: Blank frame captured");
            return;
        }
        
        // Convert to HSV
        cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        
        // Create masks for red (two ranges to handle red wrap-around)
        cv::inRange(hsv, lower_color1, upper_color1, mask1);
        cv::inRange(hsv, lower_color2, upper_color2, mask2);
        
        // Combine both masks
        cv::bitwise_or(mask1, mask2, mask);
        
        // Find contours
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // If any contours are found
        if(!contours.empty())
        {
            // Filter contours by area and circularity
            std::vector<std::vector<cv::Point>> circular_contours;
            
            for(const auto& contour : contours)
            {
                double area = cv::contourArea(contour);
                if(area < MIN_AREA)
                    continue;
                
                double circularity = 0;
                if(isCircular(contour, circularity, MIN_CIRCULARITY))
                {
                    circular_contours.push_back(contour);
                    
                    // Print circularity for debugging
                    std::cout << "Circularity: " << circularity << ", Area: " << area << std::endl;
                }
            }
            
            // If we found circular contours
            if(!circular_contours.empty())
            {
                // Get the largest circular contour
                auto largest_contour = std::max_element(circular_contours.begin(), circular_contours.end(),
                    [](const std::vector<cv::Point>& c1, const std::vector<cv::Point>& c2)
                    {
                        return cv::contourArea(c1) < cv::contourArea(c2);
                    });
                
                // Get bounding rectangle
                cv::Rect bounding_rect = cv::boundingRect(*largest_contour);
                int x = bounding_rect.x;
                int y = bounding_rect.y;
                int w = bounding_rect.width;
                int h = bounding_rect.height;
                
                // Calculate center of the circle
                cv::Point center(x + w/2, y + h/2);
                int radius = std::max(w, h) / 2;
                
                // Draw the circle
                cv::circle(frame, center, radius, cv::Scalar(0, 255, 0), 2);
                
                // Draw bounding rectangle (optional)
                cv::rectangle(frame, bounding_rect, cv::Scalar(255, 0, 0), 2);
                
                // Display center point
                cv::circle(frame, center, 3, cv::Scalar(0, 0, 255), -1);
                
                // Put text with information
                std::string text = "Red Circle Detected!";
                cv::putText(frame, text, cv::Point(10, 30), 
                           cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0, 255, 0), 2);
                                
                // Print to console
                std::cout << "Red circle found at: Center=(" << center.x << ", " << center.y 
                          << "), Radius=" << radius 
                          << ", Bounding Box: x=" << x << ", y=" << y 
                          << ", w=" << w << ", h=" << h 
                          << std::endl;
            }
        }
        
        // Display the captured frame
        cv::imshow("Camera", frame);
        cv::imshow("Mask", mask); // Show the mask for debugging
        
        // Check for 'q' key press
        if(cv::waitKey(1) == 'q')
        {
            RCLCPP_INFO(this->get_logger(), "Quit key pressed, shutting down...");
            rclcpp::shutdown();
        }
    }    
public:
    CameraNode() : Node("cameraDemo")
    {
        // Open camera
        cam.open(0);
        
        // Check if camera opened successfully
        if(!cam.isOpened())
        {
            RCLCPP_ERROR(this->get_logger(), "Error: Could not open camera");
            rclcpp::shutdown();
            return;
        }
        // Get the default frame width and height
        frame_width = static_cast<int>(cam.get(cv::CAP_PROP_FRAME_WIDTH));
        frame_height = static_cast<int>(cam.get(cv::CAP_PROP_FRAME_HEIGHT));
        
        RCLCPP_INFO(this->get_logger(), "Camera opened: %dx%d", frame_width, frame_height);
                
        // Create timer to read camera at ~30 FPS
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(33),  // ~30 fps
            std::bind(&CameraNode::timer_callback, this)
        );
    }

    ~CameraNode()
    {
        // Release the camera and destroy windows
        if(cam.isOpened())
        {
            cam.release();
        }
        cv::destroyAllWindows();
        RCLCPP_INFO(this->get_logger(), "Camera node shutting down");
    }    
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CameraNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

