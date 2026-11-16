cmake_minimum_required(VERSION 3.8)
project(omnirobot_bringup)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

install(DIRECTORY
  launch
  config
  src

  DESTINATION 
  share/${PROJECT_NAME}
)

# these are for fix lidar
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(fix_lidar src/fix_lidar.cpp)

ament_target_dependencies(fix_lidar
  rclcpp
  sensor_msgs
)

install(TARGETS
  fix_lidar
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
