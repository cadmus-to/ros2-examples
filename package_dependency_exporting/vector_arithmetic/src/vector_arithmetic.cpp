#include "vector_arithmetic/vector_arithmetic.hpp"

#include <numeric>

#include <geometry_msgs/msg/vector3.hpp>
#include <geometry_msgs_arithmetic/geometry_msgs_arithmetic.hpp>

geometry_msgs::msg::Vector3 mean(
    const std::deque<geometry_msgs::msg::Vector3>& vectors) {
  const auto sum = std::accumulate(vectors.begin(), vectors.end(),
                                   geometry_msgs::msg::Vector3{}, operator+);
  return sum / vectors.size();
}
