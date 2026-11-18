cmake_minimum_required(VERSION 3.8)
project(fusion_sensors)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

# Executable
add_executable(move_square src/move_square.cpp)

ament_target_dependencies(
  move_square
  rclcpp
  geometry_msgs
  nav_msgs
)

# Install executable
install(
  TARGETS move_square
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch and config directories
install(
  DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
