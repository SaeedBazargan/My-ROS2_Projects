// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mobilebot_interfaces:msg/Int64.idl
// generated code does not contain a copyright notice

#ifndef MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__TRAITS_HPP_
#define MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mobilebot_interfaces/msg/detail/int64__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mobilebot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Int64 & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Int64 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Int64 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace mobilebot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mobilebot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mobilebot_interfaces::msg::Int64 & msg,
  std::ostream & out, size_t indentation = 0)
{
  mobilebot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mobilebot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mobilebot_interfaces::msg::Int64 & msg)
{
  return mobilebot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mobilebot_interfaces::msg::Int64>()
{
  return "mobilebot_interfaces::msg::Int64";
}

template<>
inline const char * name<mobilebot_interfaces::msg::Int64>()
{
  return "mobilebot_interfaces/msg/Int64";
}

template<>
struct has_fixed_size<mobilebot_interfaces::msg::Int64>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mobilebot_interfaces::msg::Int64>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mobilebot_interfaces::msg::Int64>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__TRAITS_HPP_
