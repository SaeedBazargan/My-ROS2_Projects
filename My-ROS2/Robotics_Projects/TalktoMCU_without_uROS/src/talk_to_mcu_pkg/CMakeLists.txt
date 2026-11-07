cmake_minimum_required(VERSION 3.8)
project(talk_to_mcu_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(talk_to_mcu_interfaces REQUIRED)

# serial --------------------------------
include_directories(include)

add_executable(serialDemo
  src/serialtest.cpp
  src/MySerial.cpp
)

ament_target_dependencies(serialDemo
  rclcpp
  talk_to_mcu_interfaces
)

# camera -------------------------------- 
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cameraDemo
  src/cameratest.cpp
)

ament_target_dependencies(cameraDemo
  rclcpp
  talk_to_mcu_interfaces
)

target_link_libraries(cameraDemo
  ${OpenCV_LIBS}
)

# all -------------------------------- 
install(TARGETS
  serialDemo
  cameraDemo
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
