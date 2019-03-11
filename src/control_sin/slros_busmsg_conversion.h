#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <balldroid_msgs/Dynamixel.h>
#include <balldroid_msgs/Imu.h>
#include <balldroid_msgs/MoveWheel.h>
#include <geometry_msgs/Vector3.h>
#include <ros/time.h>
#include <std_msgs/Header.h>
#include "control_sin_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(balldroid_msgs::Dynamixel* msgPtr, SL_Bus_control_sin_balldroid_msgs_Dynamixel const* busPtr);
void convertToBus(SL_Bus_control_sin_balldroid_msgs_Dynamixel* busPtr, balldroid_msgs::Dynamixel const* msgPtr);

void convertFromBus(balldroid_msgs::Imu* msgPtr, SL_Bus_control_sin_balldroid_msgs_Imu const* busPtr);
void convertToBus(SL_Bus_control_sin_balldroid_msgs_Imu* busPtr, balldroid_msgs::Imu const* msgPtr);

void convertFromBus(balldroid_msgs::MoveWheel* msgPtr, SL_Bus_control_sin_balldroid_msgs_MoveWheel const* busPtr);
void convertToBus(SL_Bus_control_sin_balldroid_msgs_MoveWheel* busPtr, balldroid_msgs::MoveWheel const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_control_sin_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_control_sin_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(ros::Time* msgPtr, SL_Bus_control_sin_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_control_sin_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_control_sin_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_control_sin_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
