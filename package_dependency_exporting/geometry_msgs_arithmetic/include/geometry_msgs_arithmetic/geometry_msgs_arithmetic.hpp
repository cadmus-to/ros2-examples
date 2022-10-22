#pragma once

#include <geometry_msgs/msg/vector3.hpp>

#include "geometry_msgs_arithmetic/visibility_control.h"

geometry_msgs::msg::Vector3 operator+(const geometry_msgs::msg::Vector3&,
                                      const geometry_msgs::msg::Vector3&);

template<class T>
geometry_msgs::msg::Vector3 operator/(
    const geometry_msgs::msg::Vector3& numerator, T denominator) {
  auto result = numerator;
  result.x /= denominator;
  result.y /= denominator;
  result.z /= denominator;
  return result;
}
