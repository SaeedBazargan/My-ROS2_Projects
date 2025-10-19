import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse
from rclpy.action.server import ServerGoalHandle
from mobilebot_interfaces.action import CountUntil
import time

class CountUntilServerNode(Node):
    def __init__(self):
        super().__init__("count_until_server")
        self.count_server_ = ActionServer(
            self, 
            CountUntil, 
            "count_until",
            goal_callback=self.goal_callback,
            execute_callback=self.execute_callback)
        self.get_logger().info("Action server is ready!")

    # We only get the target in this function for evaluation.
    def goal_callback(self, goal_request : CountUntil.Goal):
        self.get_logger().info("Received a goal")
        
        # validate the goal request
        if goal_request.target_number <= 0:
            self.get_logger().info("the goal is invalid.")
            return GoalResponse.REJECT
        
        self.get_logger().info("the goal is valid.")
        return GoalResponse.ACCEPT

    # If the evaluation is positive, we receive the goal and execute it.
    def execute_callback(self, goal_handle: ServerGoalHandle):
        # get request from goal (mobilebot_interfaces.action.CountUntil.action:Goal) 
        target_ = goal_handle.request.target_number
        period_ = goal_handle.request.period

        # execute the action
        self.get_logger().info("Executing the goal")
        counter_ = 0
        for i in range(target_):
            counter_ += 1
            self.get_logger().info(str(counter_))
            time.sleep(period_)

        goal_handle.succeed()

        # send the result (mobilebot_interfaces.action.CountUntil.action:Result)
        result_ = CountUntil.Result()
        result_.reached_number = counter_

        return result_


def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
