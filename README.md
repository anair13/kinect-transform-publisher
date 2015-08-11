# kinect-transform-publisher

ROS package that converts Kinect point cloud to robot's coordinates. It includes the little bit of C++ code to make the pcl and tf libraries work together, as well as some launch files for convenience.

## Baxter Calibration Guide

I used this code with the kinect calibration package from https://github.com/h2r/baxter_h2r_packages to make the process of using the Kinect sensor with the [Baxter](http://www.rethinkrobotics.com/baxter/) robot very easy. Steps to calibrate:

  1. Clone this repository, and follow the instructions at baxter_h2r_packages to set up that repository. I found I needed to also clone https://github.com/sniekum/ar_track_alvar_msgs to get their calibration package working.
  2. Run the [Baxter kinect calibration](https://github.com/h2r/baxter_h2r_packages/tree/indigo-devel/baxter_kinect_calibration) program and get the transform
  3. Copy the new transform (you can directly copy the output of `tf_look.py`) into the relevant args of the  kinect_startup_calibrated.launch file
  4. Run the launch file

You should now have a calibrated point cloud aligned with the robot on the `/transformed_points` topic.
