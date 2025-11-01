// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mobilebot_interfaces:msg/Int64.idl
// generated code does not contain a copyright notice

#ifndef MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__BUILDER_HPP_
#define MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mobilebot_interfaces/msg/detail/int64__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mobilebot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Int64_data
{
public:
  Init_Int64_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mobilebot_interfaces::msg::Int64 data(::mobilebot_interfaces::msg::Int64::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::msg::Int64 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::msg::Int64>()
{
  return mobilebot_interfaces::msg::builder::Init_Int64_data();
}

}  // namespace mobilebot_interfaces

#endif  // MOBILEBOT_INTERFACES__MSG__DETAIL__INT64__BUILDER_HPP_
