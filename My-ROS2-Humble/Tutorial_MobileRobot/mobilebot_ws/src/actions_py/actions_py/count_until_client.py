import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle, GoalStatus
from mobilebot_interfaces.action import CountUntil

class CountUntilClientNode(Node):
    def __init__(self):
        super().__init__("count_until_client")
        self.count_client_ = ActionClient(
            self,
            CountUntil,
            "count_until"
        )


    def send_goal(self, target_num_, period_):
        # wait for the server (ROS2 communicates with the server internally, and if it is OK.)
        self.count_client_.wait_for_server()
        self.get_logger().info("Server is ready")

        # create a goal (mobilebot_interfaces.action.CountUntil.action:Goal)
        goal_ = CountUntil.Goal()
        goal_.target_number = target_num_
        goal_.period = period_

        # send the goal
        self.get_logger().info("Sending goal: target -> " + str(target_num_) + " " + "period -> " + str(period_))
        self.count_client_.send_goal_async(goal_).add_done_callback(self.goal_response_callback)


    # we send the goal and the server is going to say accepted or not
    def goal_response_callback(self, future):
        self.goal_handle : ClientGoalHandle = future.result()
        if self.goal_handle.accepted:
            self.get_logger().info("the goal got accepted.")
            self.goal_handle.get_result_async().add_done_callback(self.goal_result_callback)
        else:
            self.get_logger().warn("the goal got rejected.")


    def goal_result_callback(self, future):
        status_ = future.result().status
        result_ = future.result().result
        
        if status_ == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Success.")
        elif status_ == GoalStatus.STATUS_ABORTED:
            self.get_logger().error("Abort.")

        self.get_logger().info("Result is: " + str(result_.reached_number))


def main(args=None):
    rclpy.init(args=args)
    node = CountUntilClientNode()
    node.send_goal(6, 1.0)      # Just for test
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()

