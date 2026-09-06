# Make sure it is executable!
# sudo chmod +x killall_Project.sh

# !/bin/bash

ps aux | grep gz | grep -v grep | awk '{print $2}' | xargs -r kill -9
pkill -f "line_follower"


echo "ROS2 + Gazebo processes stopped."

