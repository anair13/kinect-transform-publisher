#!/usr/bin/env python

import rospy
import tf

rospy.init_node("tf_listener_node")

listener = tf.TransformListener()

rospy.sleep(1)

# print listener.lookupTransform("/left_hand_camera", "/camera_link", rospy.Time(0))
listener.waitForTransform("/torso", "/camera_link", rospy.Time(0), rospy.Duration(5))
x = listener.lookupTransform("/torso", "/camera_link", rospy.Time(0))
print " ".join([str(y) for y in x[0]]) + " " + " ".join([str(y) for y in x[1]])