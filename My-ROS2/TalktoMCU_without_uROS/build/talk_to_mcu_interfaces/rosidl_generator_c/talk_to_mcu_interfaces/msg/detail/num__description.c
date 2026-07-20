// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from talk_to_mcu_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#include "talk_to_mcu_interfaces/msg/detail/num__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_talk_to_mcu_interfaces
const rosidl_type_hash_t *
talk_to_mcu_interfaces__msg__Num__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7a, 0xd8, 0xab, 0x70, 0xd3, 0x0e, 0xde, 0x52,
      0xa8, 0x2a, 0xa8, 0x33, 0xcf, 0xa6, 0x87, 0x50,
      0x19, 0x73, 0x0e, 0xf4, 0x0c, 0xcf, 0xfc, 0x0b,
      0x08, 0x51, 0xb5, 0x74, 0xe5, 0xb3, 0x26, 0x15,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char talk_to_mcu_interfaces__msg__Num__TYPE_NAME[] = "talk_to_mcu_interfaces/msg/Num";

// Define type names, field names, and default values
static char talk_to_mcu_interfaces__msg__Num__FIELD_NAME__x[] = "x";
static char talk_to_mcu_interfaces__msg__Num__FIELD_NAME__y[] = "y";
static char talk_to_mcu_interfaces__msg__Num__FIELD_NAME__width[] = "width";
static char talk_to_mcu_interfaces__msg__Num__FIELD_NAME__height[] = "height";

static rosidl_runtime_c__type_description__Field talk_to_mcu_interfaces__msg__Num__FIELDS[] = {
  {
    {talk_to_mcu_interfaces__msg__Num__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {talk_to_mcu_interfaces__msg__Num__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {talk_to_mcu_interfaces__msg__Num__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {talk_to_mcu_interfaces__msg__Num__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
talk_to_mcu_interfaces__msg__Num__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {talk_to_mcu_interfaces__msg__Num__TYPE_NAME, 30, 30},
      {talk_to_mcu_interfaces__msg__Num__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 x\n"
  "int32 y\n"
  "int32 width\n"
  "int32 height";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
talk_to_mcu_interfaces__msg__Num__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {talk_to_mcu_interfaces__msg__Num__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 41, 41},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
talk_to_mcu_interfaces__msg__Num__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *talk_to_mcu_interfaces__msg__Num__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
