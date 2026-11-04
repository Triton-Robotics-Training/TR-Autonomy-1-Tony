#include "spin_slow_update.h"

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<SlowSolution>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}

SlowSolution::SlowSolution() : Node("slowsolution") {

    position_publisher_ =
        create_publisher<ArrayMsg>("/predictedpos", 10);

    position_subscription_ =
        create_subscription<ArrayMsg>(
            "/measuredpos", 10,
            [this](ArrayMsg::ConstSharedPtr msg) {
                position_callback(msg);
            }
        );
}

void SlowSolution::position_callback(ArrayMsg::ConstSharedPtr msg) {
    position_publisher_->publish(*msg);
}