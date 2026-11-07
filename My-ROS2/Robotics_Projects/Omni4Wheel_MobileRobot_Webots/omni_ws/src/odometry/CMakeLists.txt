cmake_minimum_required(VERSION 3.8)
project(odometry)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)

add_executable(sub_for_odom src/sub_for_odom.cpp)

ament_target_dependencies(
  sub_for_odom
  rclcpp
  nav_msgs
)

target_link_libraries(
  sub_for_odom
)

install(
  TARGETS
    sub_for_odom
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
