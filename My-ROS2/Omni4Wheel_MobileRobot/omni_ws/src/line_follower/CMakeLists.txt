cmake_minimum_required(VERSION 3.8)
project(line_follower)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(line_follower src/line_follower.cpp)

ament_target_dependencies(
  line_follower
  rclcpp
  sensor_msgs
  cv_bridge
)

target_link_libraries(
  line_follower
  ${OpenCV_LIBS}
)

install(
  TARGETS
    line_follower
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
