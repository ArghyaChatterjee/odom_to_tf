#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>


std::string odomFrame;
std::string baseFrame;


void odomCallback(const nav_msgs::OdometryPtr& msg) {
  if ((msg->pose.pose.position.x != 0) &&
      (msg->pose.pose.position.y != 0) &&
      (msg->pose.pose.position.z != 0)) {
    
    static tf::TransformBroadcaster br;
    
    tf::Transform tr;
    
    tr.setOrigin(tf::Vector3(msg->pose.pose.position.x,
                                    msg->pose.pose.position.y,
                                    msg->pose.pose.position.z));
    
    tf::Quaternion q = tf::Quaternion(msg->pose.pose.orientation.x,
             msg->pose.pose.orientation.y,
             msg->pose.pose.orientation.z,
             msg->pose.pose.orientation.w);
    
    tr.setRotation(q);
    
    br.sendTransform(tf::StampedTransform(tr, ros::Time::now(), odomFrame, baseFrame));
  }
}

int main(int argc, char** argv) {
  
  ros::init(argc, argv, "odom_to_tf", ros::init_options::AnonymousName);
  
  ros::NodeHandle nh("~");

  std::string odometryTopic;
  
  nh.param<std::string>("odomTopic", odometryTopic, "/curiosity_mars_rover/odom");
  nh.param<std::string>("baseFrame", baseFrame, "base_footprint");
  nh.param<std::string>("odomFrame", odomFrame, "world");
  
  ros::Subscriber sub_odom = nh.subscribe(odometryTopic, 10, &odomCallback);

  ros::spin();
  return 0;
}
