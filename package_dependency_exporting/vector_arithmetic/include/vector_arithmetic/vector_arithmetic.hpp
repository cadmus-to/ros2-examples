#pragma once

#include <deque>

#include <geometry_msgs/msg/vector3.hpp>

#include "vector_arithmetic/visibility_control.h"

geometry_msgs::msg::Vector3 mean(
    const std::deque<geometry_msgs::msg::Vector3>&);
