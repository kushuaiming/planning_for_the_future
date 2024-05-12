cmake_minimum_required(VERSION 2.8.3)
project(planning)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(planning_node planning_node.cc)
target_link_libraries(planning_node ${catkin_LIBRARIES})
add_dependencies(planning_node planning_generate_messages_cpp)