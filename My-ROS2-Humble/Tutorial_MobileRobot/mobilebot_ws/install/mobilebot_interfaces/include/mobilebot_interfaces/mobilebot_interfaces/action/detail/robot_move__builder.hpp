// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mobilebot_interfaces:action/RobotMove.idl
// generated code does not contain a copyright notice

#ifndef MOBILEBOT_INTERFACES__ACTION__DETAIL__ROBOT_MOVE__BUILDER_HPP_
#define MOBILEBOT_INTERFACES__ACTION__DETAIL__ROBOT_MOVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mobilebot_interfaces/action/detail/robot_move__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_Goal_goalvelocity
{
public:
  explicit Init_RobotMove_Goal_goalvelocity(::mobilebot_interfaces::action::RobotMove_Goal & msg)
  : msg_(msg)
  {}
  ::mobilebot_interfaces::action::RobotMove_Goal goalvelocity(::mobilebot_interfaces::action::RobotMove_Goal::_goalvelocity_type arg)
  {
    msg_.goalvelocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_Goal msg_;
};

class Init_RobotMove_Goal_goalposition
{
public:
  Init_RobotMove_Goal_goalposition()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMove_Goal_goalvelocity goalposition(::mobilebot_interfaces::action::RobotMove_Goal::_goalposition_type arg)
  {
    msg_.goalposition = std::move(arg);
    return Init_RobotMove_Goal_goalvelocity(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_Goal>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_Goal_goalposition();
}

}  // namespace mobilebot_interfaces


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_Result_position
{
public:
  Init_RobotMove_Result_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mobilebot_interfaces::action::RobotMove_Result position(::mobilebot_interfaces::action::RobotMove_Result::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_Result>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_Result_position();
}

}  // namespace mobilebot_interfaces


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_Feedback_current_position
{
public:
  Init_RobotMove_Feedback_current_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mobilebot_interfaces::action::RobotMove_Feedback current_position(::mobilebot_interfaces::action::RobotMove_Feedback::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_Feedback>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_Feedback_current_position();
}

}  // namespace mobilebot_interfaces


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_SendGoal_Request_goal
{
public:
  explicit Init_RobotMove_SendGoal_Request_goal(::mobilebot_interfaces::action::RobotMove_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::mobilebot_interfaces::action::RobotMove_SendGoal_Request goal(::mobilebot_interfaces::action::RobotMove_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_SendGoal_Request msg_;
};

class Init_RobotMove_SendGoal_Request_goal_id
{
public:
  Init_RobotMove_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMove_SendGoal_Request_goal goal_id(::mobilebot_interfaces::action::RobotMove_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotMove_SendGoal_Request_goal(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_SendGoal_Request>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_SendGoal_Request_goal_id();
}

}  // namespace mobilebot_interfaces


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_SendGoal_Response_stamp
{
public:
  explicit Init_RobotMove_SendGoal_Response_stamp(::mobilebot_interfaces::action::RobotMove_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::mobilebot_interfaces::action::RobotMove_SendGoal_Response stamp(::mobilebot_interfaces::action::RobotMove_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_SendGoal_Response msg_;
};

class Init_RobotMove_SendGoal_Response_accepted
{
public:
  Init_RobotMove_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMove_SendGoal_Response_stamp accepted(::mobilebot_interfaces::action::RobotMove_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RobotMove_SendGoal_Response_stamp(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_SendGoal_Response>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_SendGoal_Response_accepted();
}

}  // namespace mobilebot_interfaces


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_GetResult_Request_goal_id
{
public:
  Init_RobotMove_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mobilebot_interfaces::action::RobotMove_GetResult_Request goal_id(::mobilebot_interfaces::action::RobotMove_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_GetResult_Request>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_GetResult_Request_goal_id();
}

}  // namespace mobilebot_interfaces


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_GetResult_Response_result
{
public:
  explicit Init_RobotMove_GetResult_Response_result(::mobilebot_interfaces::action::RobotMove_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::mobilebot_interfaces::action::RobotMove_GetResult_Response result(::mobilebot_interfaces::action::RobotMove_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_GetResult_Response msg_;
};

class Init_RobotMove_GetResult_Response_status
{
public:
  Init_RobotMove_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMove_GetResult_Response_result status(::mobilebot_interfaces::action::RobotMove_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RobotMove_GetResult_Response_result(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_GetResult_Response>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_GetResult_Response_status();
}

}  // namespace mobilebot_interfaces


namespace mobilebot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotMove_FeedbackMessage_feedback
{
public:
  explicit Init_RobotMove_FeedbackMessage_feedback(::mobilebot_interfaces::action::RobotMove_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::mobilebot_interfaces::action::RobotMove_FeedbackMessage feedback(::mobilebot_interfaces::action::RobotMove_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_FeedbackMessage msg_;
};

class Init_RobotMove_FeedbackMessage_goal_id
{
public:
  Init_RobotMove_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMove_FeedbackMessage_feedback goal_id(::mobilebot_interfaces::action::RobotMove_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotMove_FeedbackMessage_feedback(msg_);
  }

private:
  ::mobilebot_interfaces::action::RobotMove_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mobilebot_interfaces::action::RobotMove_FeedbackMessage>()
{
  return mobilebot_interfaces::action::builder::Init_RobotMove_FeedbackMessage_goal_id();
}

}  // namespace mobilebot_interfaces

#endif  // MOBILEBOT_INTERFACES__ACTION__DETAIL__ROBOT_MOVE__BUILDER_HPP_
