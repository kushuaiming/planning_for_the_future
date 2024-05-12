#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "planning");
  ros::NodeHandle node_handle;
  ros::Publisher chatter_pub =
      node_handle.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
