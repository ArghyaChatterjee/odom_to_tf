cmake_minimum_required(VERSION 2.8.3)
project(odom_to_tf)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  nav_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(CATKIN_DEPENDS roscpp tf nav_msgs)

add_executable(odom_to_tf src/odom_to_tf.cpp)
target_link_libraries(odom_to_tf ${catkin_LIBRARIES})
