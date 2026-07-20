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

class Init_Num_height
{
public:
  explicit Init_Num_height(::talk_to_mcu_interfaces::msg::Num & msg)
  : msg_(msg)
  {}
  ::talk_to_mcu_interfaces::msg::Num height(::talk_to_mcu_interfaces::msg::Num::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::talk_to_mcu_interfaces::msg::Num msg_;
};

class Init_Num_width
{
public:
  explicit Init_Num_width(::talk_to_mcu_interfaces::msg::Num & msg)
  : msg_(msg)
  {}
  Init_Num_height width(::talk_to_mcu_interfaces::msg::Num::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_Num_height(msg_);
  }

private:
  ::talk_to_mcu_interfaces::msg::Num msg_;
};

class Init_Num_y
{
public:
  explicit Init_Num_y(::talk_to_mcu_interfaces::msg::Num & msg)
  : msg_(msg)
  {}
  Init_Num_width y(::talk_to_mcu_interfaces::msg::Num::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Num_width(msg_);
  }

private:
  ::talk_to_mcu_interfaces::msg::Num msg_;
};

class Init_Num_x
{
public:
  Init_Num_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Num_y x(::talk_to_mcu_interfaces::msg::Num::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Num_y(msg_);
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
  return talk_to_mcu_interfaces::msg::builder::Init_Num_x();
}

}  // namespace talk_to_mcu_interfaces

#endif  // TALK_TO_MCU_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
