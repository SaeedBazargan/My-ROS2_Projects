# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target talk_to_mcu_interfaces::talk_to_mcu_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${talk_to_mcu_interfaces_TARGETS}.
if(talk_to_mcu_interfaces_TARGETS AND NOT TARGET talk_to_mcu_interfaces::talk_to_mcu_interfaces)
  add_library(talk_to_mcu_interfaces::talk_to_mcu_interfaces INTERFACE IMPORTED)
  set_target_properties(talk_to_mcu_interfaces::talk_to_mcu_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${talk_to_mcu_interfaces_TARGETS}")
endif()
