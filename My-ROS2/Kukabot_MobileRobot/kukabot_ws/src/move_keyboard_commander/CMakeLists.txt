cmake_minimum_required(VERSION 3.8)
project(move_keyboard_commander)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(move_keyboard src/move_keyboard.cpp)
ament_target_dependencies(move_keyboard rclcpp std_msgs)

install(TARGETS
  move_keyboard
  DESTINATION lib/${PROJECT_NAME})

ament_package()
