cmake_minimum_required(VERSION 3.8)
project(lifecycle_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(mobilebot_interfaces REQUIRED)

add_executable(number_publisher src/number_publisher.cpp)
ament_target_dependencies(number_publisher rclcpp rclcpp_lifecycle mobilebot_interfaces)

add_executable(lifecycle_node_manager src/lifecycle_node_manager.cpp)
ament_target_dependencies(lifecycle_node_manager rclcpp lifecycle_msgs)

add_executable(robot_move_server src/robot_move_server.cpp)
ament_target_dependencies(robot_move_server rclcpp rclcpp_action rclcpp_lifecycle mobilebot_interfaces)

add_executable(robot_move_startup src/robot_move_startup.cpp)
ament_target_dependencies(robot_move_startup rclcpp lifecycle_msgs)

install(TARGETS
  number_publisher
  lifecycle_node_manager
  robot_move_server
  robot_move_startup
  DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
