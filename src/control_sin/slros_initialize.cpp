#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "control_sin";

// For Block control_sin/Subscribe
SimulinkSubscriber<balldroid_msgs::Imu, SL_Bus_control_sin_balldroid_msgs_Imu> Sub_control_sin_8;

// For Block control_sin/Publish1
SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_sin_balldroid_msgs_MoveWheel> Pub_control_sin_30;

// For Block control_sin/Publish2
SimulinkPublisher<balldroid_msgs::Dynamixel, SL_Bus_control_sin_balldroid_msgs_Dynamixel> Pub_control_sin_84;

// For Block control_sin/Publish3
SimulinkPublisher<balldroid_msgs::MoveWheel, SL_Bus_control_sin_balldroid_msgs_MoveWheel> Pub_control_sin_107;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

