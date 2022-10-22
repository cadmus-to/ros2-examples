cmake_minimum_required(VERSION 3.8)
project(moving_vector_average)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp)
find_package(vector_arithmetic REQUIRED)

add_executable(moving_vector_average src/moving_vector_average.cpp)
target_include_directories(moving_vector_average PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(moving_vector_average PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(moving_vector_average
  rclcpp
  vector_arithmetic
)

install(TARGETS moving_vector_average
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
