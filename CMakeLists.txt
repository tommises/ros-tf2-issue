cmake_minimum_required(VERSION 2.8.3)
project(tf2_test)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  tf2
  tf2_bullet
  tf2_eigen
  tf2_geometry_msgs
  tf2_kdl
  tf2_msgs
  tf2_py
  tf2_ros
  tf2_sensor_msgs
  tf2_tools
  tf
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(tf2_test_tf2_point src/tf2_test_tf2_point.cpp)
add_executable(tf2_test_tf1_point src/tf2_test_tf1_point.cpp)

target_link_libraries(tf2_test_tf2_point
  ${catkin_LIBRARIES}
)
target_link_libraries(tf2_test_tf1_point
  ${catkin_LIBRARIES}
)