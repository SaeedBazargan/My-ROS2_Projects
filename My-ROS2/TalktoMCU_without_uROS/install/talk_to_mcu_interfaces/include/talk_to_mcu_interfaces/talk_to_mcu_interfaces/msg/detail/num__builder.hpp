// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from talk_to_mcu_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "talk_to_mcu_interfaces/msg/num.hpp"


#ifndef TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
#define TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "talk_to_mcu_interfaces/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace talk_to_mcu_interfaces
{

namespace msg
{

namespace builder
{

class Init_Num_data
{
public:
  Init_Num_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::talk_to_mcu_interfaces::msg::Num data(::talk_to_mcu_interfaces::msg::Num::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::talk_to_mcu_interfaces::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::talk_to_mcu_interfaces::msg::Num>()
{
  return talk_to_mcu_interfaces::msg::builder::Init_Num_data();
}

}  // namespace talk_to_mcu_interfaces

#endif  // TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
