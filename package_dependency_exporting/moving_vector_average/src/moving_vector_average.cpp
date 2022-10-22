#include <geometry_msgs/msg/vector3.hpp>
#include <rclcpp/rclcpp.hpp>

#include <vector_arithmetic/vector_arithmetic.hpp>

class MovingVectorAverageNode : public rclcpp::Node {
 public:
  MovingVectorAverageNode()
      : rclcpp::Node("moving_vector_average"),
        vectors_{} {
    declare_parameter<int>("window_size", 3);

    publisher_ = create_publisher<geometry_msgs::msg::Vector3>("input", 1);
    subscription_ = create_subscription<geometry_msgs::msg::Vector3>(
        "average", 1,
        [this](const geometry_msgs::msg::Vector3& msg) {
          handle_msg(msg);
        });
  }

 private:
  void handle_msg(const geometry_msgs::msg::Vector3& msg) {
    vectors_.emplace_back(msg);

    while (vectors_.size() > get_parameter("window_size").get_value<int>()) {
      vectors_.pop_front();
    }

    publisher_->publish(mean(vectors_));
  }

  rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr publisher_;
  rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr subscription_;

  std::deque<geometry_msgs::msg::Vector3> vectors_;
}

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MovingVectorAverageNode>());
  rclcpp::shutdown();
}
