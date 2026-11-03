# ROS 2 My-Mobile Robot
A ROS 2 C++ project implementing camera-based line following and odometry-based distance calculation for a mobile robot.

## Features

### Line Follower
- Subscribes to `/camera/image_raw`.
- Uses OpenCV to detect a blue line in the camera image.
- Converts the image from BGR to HSV for color segmentation.
- Detects the largest contour and calculates its centroid.
- Uses a proportional (P) controller to adjust the robot's angular velocity.
- Publishes velocity commands to `/omni_wheel_drive_controller/cmd_vel`.
- Supports optional debugging and callback frequency measurement through ROS 2 parameters.

### Odometry Distance Calculator
- Subscribes to `/diff_drive_controller/odom`.
- Reads robot position, orientation, and velocity.
- Calculates the distance between consecutive odometry positions.
- Accumulates the total traveled distance in meters.
- Displays the final traveled distance when the node shuts down.

The first received odometry message establishes the initial position.

For every subsequent message, the node calculates the distance between the current and previous positions using the Euclidean distance formula:

\[
d = \sqrt{(x-x_{prev})^2+(y-y_{prev})^2}
\]

The total traveled distance is updated by accumulating each distance step:

\[
D_{total} = \sum_{i=1}^{n} d_i
\]

The calculation uses only the X and Y coordinates.

## Notes
- Line detection is based on HSV color thresholding and the largest detected contour.
- The line follower uses a proportional controller for steering.
- Debugging and callback frequency measurement can be enabled through ROS 2 parameters.
- The calculated distance is based on estimated odometry, not independent ground-truth measurements.
- Odometry drift and position estimation errors can affect the distance calculation.
- Consecutive odometry positions must be expressed in the same coordinate frame.
- Only planar movement (X and Y) is considered; vertical movement is ignored.