cmake_minimum_required(VERSION 3.8)
project(gpio_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(blinkLED_publisher src/blinkLED_publisher.cpp)
ament_target_dependencies(blinkLED_publisher rclcpp std_msgs)

install(TARGETS
  blinkLED_publisher
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
