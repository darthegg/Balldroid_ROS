#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block control_sin/Subscribe
extern SimulinkSubscriber<balldroid_msgs::Imu, SL_Bus_control_sin_balldroid_msgs_Imu> Sub_control_sin_8;

// For Block control_sin/Publish1
extern SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_sin_balldroid_msgs_MoveWheel> Pub_control_sin_30;

// For Block control_sin/Publish2
extern SimulinkPublisher<balldroid_msgs::Dynamixel, SL_Bus_control_sin_balldroid_msgs_Dynamixel> Pub_control_sin_84;

// For Block control_sin/Publish3
extern SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_sin_balldroid_msgs_MoveWheel> Pub_control_sin_107;

void slros_node_init(int argc, char** argv);

#endif
