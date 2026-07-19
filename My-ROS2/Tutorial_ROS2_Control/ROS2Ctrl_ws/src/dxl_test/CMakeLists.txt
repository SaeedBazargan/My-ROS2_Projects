cmake_minimum_required(VERSION 3.8)
project(dxl_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(dynamixel_sdk REQUIRED)

include_directories(include)

add_executable(mx64_test src/mx64_test.cpp)
ament_target_dependencies(mx64_test rclcpp dynamixel_sdk)

install(TARGETS
  mx64_test
  DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
