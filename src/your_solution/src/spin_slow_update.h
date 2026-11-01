#ifndef YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
#define YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;

class SlowSolution : public rclcpp::Node {
 public:
  SlowSolution();
 private:
  void position_callback(ArrayMsg::ConstSharedPtr msg);

  rclcpp::Publisher<ArrayMsg>::SharedPtr position_publisher_;
  rclcpp::Subscription<ArrayMsg>::SharedPtr position_subscription_;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
