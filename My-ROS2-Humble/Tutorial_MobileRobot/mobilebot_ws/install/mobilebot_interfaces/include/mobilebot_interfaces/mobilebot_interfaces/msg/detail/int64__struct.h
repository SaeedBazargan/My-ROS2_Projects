// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mobilebot_interfaces:msg/Int64.idl
// generated code does not contain a copyright notice

#ifndef MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__STRUCT_H_
#define MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Int64 in the package mobilebot_interfaces.
typedef struct mobilebot_interfaces__msg__Int64
{
  int64_t data;
} mobilebot_interfaces__msg__Int64;

// Struct for a sequence of mobilebot_interfaces__msg__Int64.
typedef struct mobilebot_interfaces__msg__Int64__Sequence
{
  mobilebot_interfaces__msg__Int64 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mobilebot_interfaces__msg__Int64__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__STRUCT_H_
