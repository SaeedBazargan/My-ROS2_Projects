// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mobilebot_interfaces:action/RobotMove.idl
// generated code does not contain a copyright notice

#ifndef MOBILEBOT_INTERFACES__ACTION__DETAIL__ROBOT_MOVE__FUNCTIONS_H_
#define MOBILEBOT_INTERFACES__ACTION__DETAIL__ROBOT_MOVE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mobilebot_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mobilebot_interfaces/action/detail/robot_move__struct.h"

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_Goal
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Goal__init(mobilebot_interfaces__action__RobotMove_Goal * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Goal__fini(mobilebot_interfaces__action__RobotMove_Goal * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_Goal *
mobilebot_interfaces__action__RobotMove_Goal__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Goal__destroy(mobilebot_interfaces__action__RobotMove_Goal * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Goal__are_equal(const mobilebot_interfaces__action__RobotMove_Goal * lhs, const mobilebot_interfaces__action__RobotMove_Goal * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Goal__copy(
  const mobilebot_interfaces__action__RobotMove_Goal * input,
  mobilebot_interfaces__action__RobotMove_Goal * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Goal__Sequence__init(mobilebot_interfaces__action__RobotMove_Goal__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Goal__Sequence__fini(mobilebot_interfaces__action__RobotMove_Goal__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_Goal__Sequence *
mobilebot_interfaces__action__RobotMove_Goal__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Goal__Sequence__destroy(mobilebot_interfaces__action__RobotMove_Goal__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Goal__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_Goal__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_Goal__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Goal__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_Goal__Sequence * input,
  mobilebot_interfaces__action__RobotMove_Goal__Sequence * output);

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_Result
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Result__init(mobilebot_interfaces__action__RobotMove_Result * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Result__fini(mobilebot_interfaces__action__RobotMove_Result * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_Result *
mobilebot_interfaces__action__RobotMove_Result__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Result__destroy(mobilebot_interfaces__action__RobotMove_Result * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Result__are_equal(const mobilebot_interfaces__action__RobotMove_Result * lhs, const mobilebot_interfaces__action__RobotMove_Result * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Result__copy(
  const mobilebot_interfaces__action__RobotMove_Result * input,
  mobilebot_interfaces__action__RobotMove_Result * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Result__Sequence__init(mobilebot_interfaces__action__RobotMove_Result__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Result__Sequence__fini(mobilebot_interfaces__action__RobotMove_Result__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_Result__Sequence *
mobilebot_interfaces__action__RobotMove_Result__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Result__Sequence__destroy(mobilebot_interfaces__action__RobotMove_Result__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Result__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_Result__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_Result__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Result__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_Result__Sequence * input,
  mobilebot_interfaces__action__RobotMove_Result__Sequence * output);

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_Feedback
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Feedback__init(mobilebot_interfaces__action__RobotMove_Feedback * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Feedback__fini(mobilebot_interfaces__action__RobotMove_Feedback * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_Feedback *
mobilebot_interfaces__action__RobotMove_Feedback__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Feedback__destroy(mobilebot_interfaces__action__RobotMove_Feedback * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Feedback__are_equal(const mobilebot_interfaces__action__RobotMove_Feedback * lhs, const mobilebot_interfaces__action__RobotMove_Feedback * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Feedback__copy(
  const mobilebot_interfaces__action__RobotMove_Feedback * input,
  mobilebot_interfaces__action__RobotMove_Feedback * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__init(mobilebot_interfaces__action__RobotMove_Feedback__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__fini(mobilebot_interfaces__action__RobotMove_Feedback__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_Feedback__Sequence *
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__destroy(mobilebot_interfaces__action__RobotMove_Feedback__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_Feedback__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_Feedback__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_Feedback__Sequence * input,
  mobilebot_interfaces__action__RobotMove_Feedback__Sequence * output);

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__init(mobilebot_interfaces__action__RobotMove_SendGoal_Request * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Request * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_SendGoal_Request *
mobilebot_interfaces__action__RobotMove_SendGoal_Request__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Request * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Request * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Request * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Request * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Request * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__init(mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence *
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * output);

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__init(mobilebot_interfaces__action__RobotMove_SendGoal_Response * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Response * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_SendGoal_Response *
mobilebot_interfaces__action__RobotMove_SendGoal_Response__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Response * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Response * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Response * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Response * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Response * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__init(mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence *
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * output);

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_GetResult_Request
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__init(mobilebot_interfaces__action__RobotMove_GetResult_Request * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Request__fini(mobilebot_interfaces__action__RobotMove_GetResult_Request * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_GetResult_Request *
mobilebot_interfaces__action__RobotMove_GetResult_Request__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Request__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Request * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Request * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Request * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Request * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Request * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__init(mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__fini(mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence *
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * output);

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_GetResult_Response
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__init(mobilebot_interfaces__action__RobotMove_GetResult_Response * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Response__fini(mobilebot_interfaces__action__RobotMove_GetResult_Response * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_GetResult_Response *
mobilebot_interfaces__action__RobotMove_GetResult_Response__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Response__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Response * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Response * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Response * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Response * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Response * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__init(mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__fini(mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence *
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * output);

/// Initialize action/RobotMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage
 * )) before or use
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__init(mobilebot_interfaces__action__RobotMove_FeedbackMessage * msg);

/// Finalize action/RobotMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(mobilebot_interfaces__action__RobotMove_FeedbackMessage * msg);

/// Create action/RobotMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_FeedbackMessage *
mobilebot_interfaces__action__RobotMove_FeedbackMessage__create();

/// Destroy action/RobotMove message.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__destroy(mobilebot_interfaces__action__RobotMove_FeedbackMessage * msg);

/// Check for action/RobotMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__are_equal(const mobilebot_interfaces__action__RobotMove_FeedbackMessage * lhs, const mobilebot_interfaces__action__RobotMove_FeedbackMessage * rhs);

/// Copy a action/RobotMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__copy(
  const mobilebot_interfaces__action__RobotMove_FeedbackMessage * input,
  mobilebot_interfaces__action__RobotMove_FeedbackMessage * output);

/// Initialize array of action/RobotMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__init(mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__fini(mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * array);

/// Create array of action/RobotMove messages.
/**
 * It allocates the memory for the array and calls
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence *
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/RobotMove messages.
/**
 * It calls
 * mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__destroy(mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * array);

/// Check for action/RobotMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/RobotMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mobilebot_interfaces
bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * input,
  mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MOBILEBOT_INTERFACES__ACTION__DETAIL__ROBOT_MOVE__FUNCTIONS_H_
