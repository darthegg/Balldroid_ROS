//
// File: control_types.h
//
// Code generated for Simulink model 'control'.
//
// Model version                  : 1.56
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Thu Dec 27 13:51:21 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_control_types_h_
#define RTW_HEADER_control_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_control_balldroid_msgs_Dynamixel_
#define DEFINED_TYPEDEF_FOR_SL_Bus_control_balldroid_msgs_Dynamixel_

// MsgType=balldroid_msgs/Dynamixel
typedef struct {
  int32_T Id;
  int32_T CurrentPos;
  int32_T TargetPos;
} SL_Bus_control_balldroid_msgs_Dynamixel;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_control_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_control_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_control_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_control_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_control_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_control_ros_time_Time Stamp;
} SL_Bus_control_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_control_balldroid_msgs_MoveWheel_
#define DEFINED_TYPEDEF_FOR_SL_Bus_control_balldroid_msgs_MoveWheel_

// MsgType=balldroid_msgs/MoveWheel
typedef struct {
  boolean_T NoWheel;
  boolean_T Direction;

  // Int64Type=int64
  real_T Velocity;

  // MsgType=std_msgs/Header
  SL_Bus_control_std_msgs_Header Header;
} SL_Bus_control_balldroid_msgs_MoveWheel;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_control_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_control_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_control_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_control_balldroid_msgs_Imu_
#define DEFINED_TYPEDEF_FOR_SL_Bus_control_balldroid_msgs_Imu_

// MsgType=balldroid_msgs/Imu
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_control_std_msgs_Header Header;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_control_geometry_msgs_Vector3 Euler;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_control_geometry_msgs_Vector3 Gyro;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_control_geometry_msgs_Vector3 Accel;
} SL_Bus_control_balldroid_msgs_Imu;

#endif

#ifndef typedef_robotics_slros_internal_block_T
#define typedef_robotics_slros_internal_block_T

typedef struct {
  int32_T isInitialized;
} robotics_slros_internal_block_T;

#endif                                 //typedef_robotics_slros_internal_block_T

#ifndef typedef_robotics_slros_internal_blo_m_T
#define typedef_robotics_slros_internal_blo_m_T

typedef struct {
  int32_T isInitialized;
} robotics_slros_internal_blo_m_T;

#endif                                 //typedef_robotics_slros_internal_blo_m_T

// Parameters (auto storage)
typedef struct P_control_T_ P_control_T;

// Forward declaration for rtModel
typedef struct tag_RTM_control_T RT_MODEL_control_T;

#endif                                 // RTW_HEADER_control_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
