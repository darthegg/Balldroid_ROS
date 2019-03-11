#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_control_sin_balldroid_msgs_Dynamixel and balldroid_msgs::Dynamixel

void convertFromBus(balldroid_msgs::Dynamixel* msgPtr, SL_Bus_control_sin_balldroid_msgs_Dynamixel const* busPtr)
{
  const std::string rosMessageType("balldroid_msgs/Dynamixel");

  msgPtr->current_pos =  busPtr->CurrentPos;
  msgPtr->id =  busPtr->Id;
  msgPtr->target_pos =  busPtr->TargetPos;
}

void convertToBus(SL_Bus_control_sin_balldroid_msgs_Dynamixel* busPtr, balldroid_msgs::Dynamixel const* msgPtr)
{
  const std::string rosMessageType("balldroid_msgs/Dynamixel");

  busPtr->CurrentPos =  msgPtr->current_pos;
  busPtr->Id =  msgPtr->id;
  busPtr->TargetPos =  msgPtr->target_pos;
}


// Conversions between SL_Bus_control_sin_balldroid_msgs_Imu and balldroid_msgs::Imu

void convertFromBus(balldroid_msgs::Imu* msgPtr, SL_Bus_control_sin_balldroid_msgs_Imu const* busPtr)
{
  const std::string rosMessageType("balldroid_msgs/Imu");

  convertFromBus(&msgPtr->accel, &busPtr->Accel);
  convertFromBus(&msgPtr->euler, &busPtr->Euler);
  convertFromBus(&msgPtr->gyro, &busPtr->Gyro);
  convertFromBus(&msgPtr->header, &busPtr->Header);
}

void convertToBus(SL_Bus_control_sin_balldroid_msgs_Imu* busPtr, balldroid_msgs::Imu const* msgPtr)
{
  const std::string rosMessageType("balldroid_msgs/Imu");

  convertToBus(&busPtr->Accel, &msgPtr->accel);
  convertToBus(&busPtr->Euler, &msgPtr->euler);
  convertToBus(&busPtr->Gyro, &msgPtr->gyro);
  convertToBus(&busPtr->Header, &msgPtr->header);
}


// Conversions between SL_Bus_control_sin_balldroid_msgs_MoveWheel and balldroid_msgs::MoveWheel

void convertFromBus(balldroid_msgs::MoveWheel* msgPtr, SL_Bus_control_sin_balldroid_msgs_MoveWheel const* busPtr)
{
  const std::string rosMessageType("balldroid_msgs/MoveWheel");

  msgPtr->direction =  busPtr->Direction;
  convertFromBus(&msgPtr->header, &busPtr->Header);
  msgPtr->no_wheel =  busPtr->NoWheel;
  msgPtr->velocity = (int64_t) busPtr->Velocity;
}

void convertToBus(SL_Bus_control_sin_balldroid_msgs_MoveWheel* busPtr, balldroid_msgs::MoveWheel const* msgPtr)
{
  const std::string rosMessageType("balldroid_msgs/MoveWheel");

  busPtr->Direction =  msgPtr->direction;
  convertToBus(&busPtr->Header, &msgPtr->header);
  busPtr->NoWheel =  msgPtr->no_wheel;
  busPtr->Velocity = (real_T) msgPtr->velocity;
}


// Conversions between SL_Bus_control_sin_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_control_sin_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_control_sin_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_control_sin_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_control_sin_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convertToBus(SL_Bus_control_sin_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_control_sin_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_control_sin_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_control_sin_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}

