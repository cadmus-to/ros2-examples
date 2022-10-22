#include "geometry_msgs_arithmetic/geometry_msgs_arithmetic.hpp"

geometry_msgs::msg::Vector3 operator+(const geometry_msgs::msg::Vector3& v1,
                                      const geometry_msgs::msg::Vector3& v2) {
  auto result = v1;
  result.x += v2.x;
  result.y += v2.y;
  result.z += v2.z;
  return result;
}
