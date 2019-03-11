#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "control";

// For Block control/Subscribe
SimulinkSubscriber<balldroid_msgs::Imu, SL_Bus_control_balldroid_msgs_Imu> Sub_control_8;

// For Block control/Publish1
SimulinkPublisher<balldroid_msgs::Dynamixel, SL_Bus_control_balldroid_msgs_Dynamixel> Pub_control_141;

// For Block control/Publish2
SimulinkPublisher<balldroid_msgs::Dynamixel, SL_Bus_control_balldroid_msgs_Dynamixel> Pub_control_84;

// For Block control/Publish4
SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_balldroid_msgs_MoveWheel> Pub_control_124;

// For Block control/Publish5
SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_balldroid_msgs_MoveWheel> Pub_control_125;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

