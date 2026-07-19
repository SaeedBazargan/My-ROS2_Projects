// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from talk_to_mcu_interfaces:msg/Num.idl
// generated code does not contain a copyright notice
#ifndef TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "talk_to_mcu_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "talk_to_mcu_interfaces/msg/detail/num__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
bool cdr_serialize_talk_to_mcu_interfaces__msg__Num(
  const talk_to_mcu_interfaces__msg__Num * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
bool cdr_deserialize_talk_to_mcu_interfaces__msg__Num(
  eprosima::fastcdr::Cdr &,
  talk_to_mcu_interfaces__msg__Num * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
size_t get_serialized_size_talk_to_mcu_interfaces__msg__Num(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
size_t max_serialized_size_talk_to_mcu_interfaces__msg__Num(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
bool cdr_serialize_key_talk_to_mcu_interfaces__msg__Num(
  const talk_to_mcu_interfaces__msg__Num * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
size_t get_serialized_size_key_talk_to_mcu_interfaces__msg__Num(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
size_t max_serialized_size_key_talk_to_mcu_interfaces__msg__Num(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_talk_to_mcu_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, talk_to_mcu_interfaces, msg, Num)();

#ifdef __cplusplus
}
#endif

#endif  // TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
