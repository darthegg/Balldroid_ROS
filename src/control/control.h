//
// File: control.h
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
#ifndef RTW_HEADER_control_h_
#define RTW_HEADER_control_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef control_COMMON_INCLUDES_
# define control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // control_COMMON_INCLUDES_

#include "control_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_control_balldroid_msgs_Imu In1;// '<S9>/In1'
  SL_Bus_control_balldroid_msgs_Imu b_varargout_2;
  SL_Bus_control_balldroid_msgs_MoveWheel BusAssignment4;// '<Root>/Bus Assignment4' 
  char_T cv0[23];
} B_control_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  robotics_slros_internal_block_T obj; // '<S7>/SinkBlock'
  robotics_slros_internal_block_T obj_a;// '<S6>/SinkBlock'
  robotics_slros_internal_block_T obj_n;// '<S5>/SinkBlock'
  robotics_slros_internal_block_T obj_j;// '<S4>/SinkBlock'
  robotics_slros_internal_blo_m_T obj_e;// '<S8>/SourceBlock'
} DW_control_T;

// Parameters (auto storage)
struct P_control_T_ {
  SL_Bus_control_balldroid_msgs_Imu Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S9>/Out1'

  SL_Bus_control_balldroid_msgs_Imu Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S8>/Constant'

  SL_Bus_control_balldroid_msgs_MoveWheel Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                           //  Referenced by: '<S3>/Constant'

  SL_Bus_control_balldroid_msgs_Dynamixel Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                           //  Referenced by: '<S1>/Constant'

  SL_Bus_control_balldroid_msgs_Dynamixel Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                           //  Referenced by: '<S2>/Constant'

  real_T Constant11_Value;             // Expression: 1
                                       //  Referenced by: '<Root>/Constant11'

  real_T Constant8_Value;              // Expression: 180
                                       //  Referenced by: '<Root>/Constant8'

  real_T Constant9_Value;              // Expression: 11.38
                                       //  Referenced by: '<Root>/Constant9'

  real_T Constant10_Value;             // Expression: 40
                                       //  Referenced by: '<Root>/Constant10'

  real_T Constant6_Value;              // Expression: -1
                                       //  Referenced by: '<Root>/Constant6'

  real_T Constant3_Value;              // Expression: 180
                                       //  Referenced by: '<Root>/Constant3'

  real_T Constant4_Value;              // Expression: 11.38
                                       //  Referenced by: '<Root>/Constant4'

  real_T Constant5_Value;              // Expression: 50
                                       //  Referenced by: '<Root>/Constant5'

  real_T Constant13_Value;             // Expression: 1
                                       //  Referenced by: '<Root>/Constant13'

  real_T Constant15_Value;             // Expression: 0
                                       //  Referenced by: '<Root>/Constant15'

  real_T Constant14_Value;             // Expression: 100
                                       //  Referenced by: '<Root>/Constant14'

  real_T Constant1_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant1'

  int32_T Constant7_Value;             // Computed Parameter: Constant7_Value
                                       //  Referenced by: '<Root>/Constant7'

  int32_T Constant2_Value;             // Computed Parameter: Constant2_Value
                                       //  Referenced by: '<Root>/Constant2'

};

// Real-time Model Data Structure
struct tag_RTM_control_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_control_T control_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_control_T control_B;

// Block states (auto storage)
extern DW_control_T control_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void control_initialize(void);
  extern void control_step(void);
  extern void control_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_control_T *const control_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Data Type Conversion6' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'control'
//  '<S1>'   : 'control/Blank Message1'
//  '<S2>'   : 'control/Blank Message2'
//  '<S3>'   : 'control/Blank Message4'
//  '<S4>'   : 'control/Publish1'
//  '<S5>'   : 'control/Publish2'
//  '<S6>'   : 'control/Publish4'
//  '<S7>'   : 'control/Publish5'
//  '<S8>'   : 'control/Subscribe'
//  '<S9>'   : 'control/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_control_h_

//
// File trailer for generated code.
//
// [EOF]
//
