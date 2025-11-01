import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/sbzrobot/ROS2-Projects/My-ROS2_Projects/My-ROS2-Humble/Tutorial_MobileRobot/mobilebot_ws/src/install/mobilebot_bringup'
