#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block control/Subscribe
extern SimulinkSubscriber<balldroid_msgs::Imu, SL_Bus_control_balldroid_msgs_Imu> Sub_control_8;

// For Block control/Publish1
extern SimulinkPublisher<balldroid_msgs::Dynamixel, SL_Bus_control_balldroid_msgs_Dynamixel> Pub_control_141;

// For Block control/Publish2
extern SimulinkPublisher<balldroid_msgs::Dynamixel, SL_Bus_control_balldroid_msgs_Dynamixel> Pub_control_84;

// For Block control/Publish4
extern SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_balldroid_msgs_MoveWheel> Pub_control_124;

// For Block control/Publish5
extern SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_balldroid_msgs_MoveWheel> Pub_control_125;

void slros_node_init(int argc, char** argv);

#endif
