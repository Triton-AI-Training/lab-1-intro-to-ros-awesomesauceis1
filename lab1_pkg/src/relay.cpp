#include "rclcpp/rclcpp.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"

class RelayNode : public rclcpp::Node {
public:
    RelayNode() : Node("relay") {

        drive_subscriber_ = this->create_subscription<ackermann_msgs::msg::AckermannDriveStamped>(
            "drive", 
            10, 
            std::bind(&RelayNode::driveCallback, this, std::placeholders::_1)
        );

        drive_relay_publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("drive_relay", 10);
    }

private:
    void driveCallback(const ackermann_msgs::msg::AckermannDriveStamped::SharedPtr msg) {

        auto relay_msg = ackermann_msgs::msg::AckermannDriveStamped();

        relay_msg.drive.speed = msg->drive.speed * 3.0;
        relay_msg.drive.steering_angle = msg->drive.steering_angle * 3.0;

        relay_msg.header = msg->header;

        drive_relay_publisher_->publish(relay_msg);
    }

    rclcpp::Subscription<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr drive_subscriber_;
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr drive_relay_publisher_;
};

int main(int argc, char **argv) {

    rclcpp::init(argc, argv);
    auto node = std::make_shared<RelayNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
