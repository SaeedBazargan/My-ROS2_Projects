// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from talk_to_mcu_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "talk_to_mcu_interfaces/msg/num.h"


#ifndef TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
#define TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Num in the package talk_to_mcu_interfaces.
typedef struct talk_to_mcu_interfaces__msg__Num
{
  int32_t data;
} talk_to_mcu_interfaces__msg__Num;

// Struct for a sequence of talk_to_mcu_interfaces__msg__Num.
typedef struct talk_to_mcu_interfaces__msg__Num__Sequence
{
  talk_to_mcu_interfaces__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} talk_to_mcu_interfaces__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
