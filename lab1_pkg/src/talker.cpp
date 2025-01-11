#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <memory>
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"

class TalkerNode : public rclcpp::Node
{
public:
    TalkerNode() : Node("talker")
    {

        this->declare_parameter<double>("v", 0.0);
        this->declare_parameter<double>("d", 0.0);

        drive_publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("drive", 10);

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1),  // 1 ms interval
            std::bind(&TalkerNode::publishDriveMessage, this));
    }

private:
    void publishDriveMessage()
    {

        double v = this->get_parameter("v").as_double();
        double d = this->get_parameter("d").as_double();

        auto drive_msg = ackermann_msgs::msg::AckermannDriveStamped();
        drive_msg.drive.speed = v;
        drive_msg.drive.steering_angle = d;

        drive_publisher_->publish(drive_msg);
    }

    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr drive_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TalkerNode>());
    rclcpp::shutdown();
    return 0;
}
