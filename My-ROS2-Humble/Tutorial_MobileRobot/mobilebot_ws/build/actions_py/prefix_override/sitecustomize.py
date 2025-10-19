import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/saeedbazargan/Desktop/ROS2-Humble/My-ROS2_Projects/My-ROS2-Humble/Tutorial_MobileRobot/mobilebot_ws/install/actions_py'
