// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mobilebot_interfaces:action/RobotMove.idl
// generated code does not contain a copyright notice
#include "mobilebot_interfaces/action/detail/robot_move__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mobilebot_interfaces__action__RobotMove_Goal__init(mobilebot_interfaces__action__RobotMove_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // goalposition
  // goalvelocity
  return true;
}

void
mobilebot_interfaces__action__RobotMove_Goal__fini(mobilebot_interfaces__action__RobotMove_Goal * msg)
{
  if (!msg) {
    return;
  }
  // goalposition
  // goalvelocity
}

bool
mobilebot_interfaces__action__RobotMove_Goal__are_equal(const mobilebot_interfaces__action__RobotMove_Goal * lhs, const mobilebot_interfaces__action__RobotMove_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goalposition
  if (lhs->goalposition != rhs->goalposition) {
    return false;
  }
  // goalvelocity
  if (lhs->goalvelocity != rhs->goalvelocity) {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_Goal__copy(
  const mobilebot_interfaces__action__RobotMove_Goal * input,
  mobilebot_interfaces__action__RobotMove_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // goalposition
  output->goalposition = input->goalposition;
  // goalvelocity
  output->goalvelocity = input->goalvelocity;
  return true;
}

mobilebot_interfaces__action__RobotMove_Goal *
mobilebot_interfaces__action__RobotMove_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Goal * msg = (mobilebot_interfaces__action__RobotMove_Goal *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_Goal));
  bool success = mobilebot_interfaces__action__RobotMove_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_Goal__destroy(mobilebot_interfaces__action__RobotMove_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_Goal__Sequence__init(mobilebot_interfaces__action__RobotMove_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Goal * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_Goal *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_Goal__Sequence__fini(mobilebot_interfaces__action__RobotMove_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_Goal__Sequence *
mobilebot_interfaces__action__RobotMove_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Goal__Sequence * array = (mobilebot_interfaces__action__RobotMove_Goal__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_Goal__Sequence__destroy(mobilebot_interfaces__action__RobotMove_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_Goal__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_Goal__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_Goal__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_Goal__Sequence * input,
  mobilebot_interfaces__action__RobotMove_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_Goal * data =
      (mobilebot_interfaces__action__RobotMove_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mobilebot_interfaces__action__RobotMove_Result__init(mobilebot_interfaces__action__RobotMove_Result * msg)
{
  if (!msg) {
    return false;
  }
  // position
  return true;
}

void
mobilebot_interfaces__action__RobotMove_Result__fini(mobilebot_interfaces__action__RobotMove_Result * msg)
{
  if (!msg) {
    return;
  }
  // position
}

bool
mobilebot_interfaces__action__RobotMove_Result__are_equal(const mobilebot_interfaces__action__RobotMove_Result * lhs, const mobilebot_interfaces__action__RobotMove_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (lhs->position != rhs->position) {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_Result__copy(
  const mobilebot_interfaces__action__RobotMove_Result * input,
  mobilebot_interfaces__action__RobotMove_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  output->position = input->position;
  return true;
}

mobilebot_interfaces__action__RobotMove_Result *
mobilebot_interfaces__action__RobotMove_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Result * msg = (mobilebot_interfaces__action__RobotMove_Result *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_Result));
  bool success = mobilebot_interfaces__action__RobotMove_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_Result__destroy(mobilebot_interfaces__action__RobotMove_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_Result__Sequence__init(mobilebot_interfaces__action__RobotMove_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Result * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_Result *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_Result__Sequence__fini(mobilebot_interfaces__action__RobotMove_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_Result__Sequence *
mobilebot_interfaces__action__RobotMove_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Result__Sequence * array = (mobilebot_interfaces__action__RobotMove_Result__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_Result__Sequence__destroy(mobilebot_interfaces__action__RobotMove_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_Result__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_Result__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_Result__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_Result__Sequence * input,
  mobilebot_interfaces__action__RobotMove_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_Result * data =
      (mobilebot_interfaces__action__RobotMove_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mobilebot_interfaces__action__RobotMove_Feedback__init(mobilebot_interfaces__action__RobotMove_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_position
  return true;
}

void
mobilebot_interfaces__action__RobotMove_Feedback__fini(mobilebot_interfaces__action__RobotMove_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_position
}

bool
mobilebot_interfaces__action__RobotMove_Feedback__are_equal(const mobilebot_interfaces__action__RobotMove_Feedback * lhs, const mobilebot_interfaces__action__RobotMove_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_position
  if (lhs->current_position != rhs->current_position) {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_Feedback__copy(
  const mobilebot_interfaces__action__RobotMove_Feedback * input,
  mobilebot_interfaces__action__RobotMove_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_position
  output->current_position = input->current_position;
  return true;
}

mobilebot_interfaces__action__RobotMove_Feedback *
mobilebot_interfaces__action__RobotMove_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Feedback * msg = (mobilebot_interfaces__action__RobotMove_Feedback *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_Feedback));
  bool success = mobilebot_interfaces__action__RobotMove_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_Feedback__destroy(mobilebot_interfaces__action__RobotMove_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__init(mobilebot_interfaces__action__RobotMove_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Feedback * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_Feedback *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__fini(mobilebot_interfaces__action__RobotMove_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_Feedback__Sequence *
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_Feedback__Sequence * array = (mobilebot_interfaces__action__RobotMove_Feedback__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__destroy(mobilebot_interfaces__action__RobotMove_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_Feedback__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_Feedback__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_Feedback__Sequence * input,
  mobilebot_interfaces__action__RobotMove_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_Feedback * data =
      (mobilebot_interfaces__action__RobotMove_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "mobilebot_interfaces/action/detail/robot_move__functions.h"

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__init(mobilebot_interfaces__action__RobotMove_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!mobilebot_interfaces__action__RobotMove_Goal__init(&msg->goal)) {
    mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  mobilebot_interfaces__action__RobotMove_Goal__fini(&msg->goal);
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Request * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!mobilebot_interfaces__action__RobotMove_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Request * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!mobilebot_interfaces__action__RobotMove_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

mobilebot_interfaces__action__RobotMove_SendGoal_Request *
mobilebot_interfaces__action__RobotMove_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_SendGoal_Request * msg = (mobilebot_interfaces__action__RobotMove_SendGoal_Request *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Request));
  bool success = mobilebot_interfaces__action__RobotMove_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__init(mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_SendGoal_Request * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_SendGoal_Request *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence *
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * array = (mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_SendGoal_Request * data =
      (mobilebot_interfaces__action__RobotMove_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__init(mobilebot_interfaces__action__RobotMove_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Response * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Response * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

mobilebot_interfaces__action__RobotMove_SendGoal_Response *
mobilebot_interfaces__action__RobotMove_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_SendGoal_Response * msg = (mobilebot_interfaces__action__RobotMove_SendGoal_Response *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Response));
  bool success = mobilebot_interfaces__action__RobotMove_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__init(mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_SendGoal_Response * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_SendGoal_Response *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__fini(mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence *
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * array = (mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__destroy(mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * input,
  mobilebot_interfaces__action__RobotMove_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_SendGoal_Response * data =
      (mobilebot_interfaces__action__RobotMove_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__init(mobilebot_interfaces__action__RobotMove_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mobilebot_interfaces__action__RobotMove_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Request__fini(mobilebot_interfaces__action__RobotMove_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Request * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Request * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

mobilebot_interfaces__action__RobotMove_GetResult_Request *
mobilebot_interfaces__action__RobotMove_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_GetResult_Request * msg = (mobilebot_interfaces__action__RobotMove_GetResult_Request *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Request));
  bool success = mobilebot_interfaces__action__RobotMove_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Request__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__init(mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_GetResult_Request * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_GetResult_Request *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__fini(mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence *
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * array = (mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_GetResult_Request * data =
      (mobilebot_interfaces__action__RobotMove_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "mobilebot_interfaces/action/detail/robot_move__functions.h"

bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__init(mobilebot_interfaces__action__RobotMove_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!mobilebot_interfaces__action__RobotMove_Result__init(&msg->result)) {
    mobilebot_interfaces__action__RobotMove_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Response__fini(mobilebot_interfaces__action__RobotMove_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  mobilebot_interfaces__action__RobotMove_Result__fini(&msg->result);
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Response * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!mobilebot_interfaces__action__RobotMove_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Response * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!mobilebot_interfaces__action__RobotMove_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

mobilebot_interfaces__action__RobotMove_GetResult_Response *
mobilebot_interfaces__action__RobotMove_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_GetResult_Response * msg = (mobilebot_interfaces__action__RobotMove_GetResult_Response *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Response));
  bool success = mobilebot_interfaces__action__RobotMove_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Response__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__init(mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_GetResult_Response * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_GetResult_Response *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__fini(mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence *
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * array = (mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__destroy(mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * input,
  mobilebot_interfaces__action__RobotMove_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_GetResult_Response * data =
      (mobilebot_interfaces__action__RobotMove_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "mobilebot_interfaces/action/detail/robot_move__functions.h"

bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__init(mobilebot_interfaces__action__RobotMove_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!mobilebot_interfaces__action__RobotMove_Feedback__init(&msg->feedback)) {
    mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(mobilebot_interfaces__action__RobotMove_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  mobilebot_interfaces__action__RobotMove_Feedback__fini(&msg->feedback);
}

bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__are_equal(const mobilebot_interfaces__action__RobotMove_FeedbackMessage * lhs, const mobilebot_interfaces__action__RobotMove_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mobilebot_interfaces__action__RobotMove_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__copy(
  const mobilebot_interfaces__action__RobotMove_FeedbackMessage * input,
  mobilebot_interfaces__action__RobotMove_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mobilebot_interfaces__action__RobotMove_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

mobilebot_interfaces__action__RobotMove_FeedbackMessage *
mobilebot_interfaces__action__RobotMove_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_FeedbackMessage * msg = (mobilebot_interfaces__action__RobotMove_FeedbackMessage *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mobilebot_interfaces__action__RobotMove_FeedbackMessage));
  bool success = mobilebot_interfaces__action__RobotMove_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__destroy(mobilebot_interfaces__action__RobotMove_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__init(mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_FeedbackMessage * data = NULL;

  if (size) {
    data = (mobilebot_interfaces__action__RobotMove_FeedbackMessage *)allocator.zero_allocate(size, sizeof(mobilebot_interfaces__action__RobotMove_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mobilebot_interfaces__action__RobotMove_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__fini(mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence *
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * array = (mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence *)allocator.allocate(sizeof(mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__destroy(mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__are_equal(const mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * lhs, const mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence__copy(
  const mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * input,
  mobilebot_interfaces__action__RobotMove_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mobilebot_interfaces__action__RobotMove_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mobilebot_interfaces__action__RobotMove_FeedbackMessage * data =
      (mobilebot_interfaces__action__RobotMove_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mobilebot_interfaces__action__RobotMove_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mobilebot_interfaces__action__RobotMove_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mobilebot_interfaces__action__RobotMove_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
