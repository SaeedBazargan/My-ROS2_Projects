cmake_minimum_required(VERSION 3.8)
project(line_follower_with_opencv)

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

add_executable(line_follower_with_opencv src/line_follower.cpp)

ament_target_dependencies(
  line_follower_with_opencv
  rclcpp
  sensor_msgs
  geometry_msgs
  cv_bridge
)

target_link_libraries(
  line_follower_with_opencv
  ${OpenCV_LIBS}
)

install(
  TARGETS
    line_follower_with_opencv
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
