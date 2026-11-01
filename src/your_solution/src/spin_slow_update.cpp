#include "spin_slow_update.h"
#include <functional>

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SlowSolution>());
  rclcpp::shutdown();
  return 0;
}

SlowSolution::SlowSolution() : Node("slowsolution") {
  position_publisher_ =
      this->create_publisher<ArrayMsg>("/predictedpos", 10);

  position_subscription_ = this->create_subscription<ArrayMsg>(
      "/measuredpos", 10,
      std::bind(&SlowSolution::position_callback, this, std::placeholders::_1));
}

void SlowSolution::position_callback(ArrayMsg::ConstSharedPtr msg) {
  position_publisher_->publish(*msg);
}
