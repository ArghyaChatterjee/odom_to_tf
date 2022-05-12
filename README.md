# publish_odom_to_tf
This repository contains code for publishing odometry to tf tree.

## Clone & Compile
```
cd ~/catkin_ws/src
git clone https://github.com/ArghyaChatterjee/odom_to_tf.git
cd ..
catkin_make
```

## Launch
```
cd ~/catkin_ws
source devel/setup.bash
roslaunch odom_to_tf publish_odom_to_tf.launch
```

## Change the topic & frames
```
  <!-- Odometry topic to listen to -->
  <arg name="odometryTopic" default="/curiosity_mars_rover/odom" />
  <!-- Frame to publish -->
  <arg name="baseFrame" default="base_footprint" />
  <!-- Frame to translate from -->
  <arg name="odomFrame" default="world" />
```

