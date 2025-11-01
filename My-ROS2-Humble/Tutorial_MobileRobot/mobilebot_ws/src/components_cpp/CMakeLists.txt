cmake_minimum_required(VERSION 3.8)
project(components_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# for composition 
include_directories(include)

add_executable(manual_composition src/manual_composition.cpp src/node1.cpp src/node2.cpp)
ament_target_dependencies(manual_composition rclcpp)

install(TARGETS
  manual_composition
  DESTINATION lib/${PROJECT_NAME}/
)

# for components
find_package(rclcpp_components REQUIRED)
find_package(example_interfaces REQUIRED)

# its not executable so: add_lib(custom_name SHARED src/number_publisher.cpp)
add_library(number_pub_components SHARED src/number_publisher.cpp)
ament_target_dependencies(number_pub_components rclcpp rclcpp_components example_interfaces)
rclcpp_components_register_nodes(number_pub_components "my_components_namespace_::NumberPub")

install(TARGETS
  number_pub_components
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_package()
