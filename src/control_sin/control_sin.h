//
// File: control_sin.h
//
// Code generated for Simulink model 'control_sin'.
//
// Model version                  : 1.55
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Thu Dec 20 16:33:27 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_control_sin_h_
#define RTW_HEADER_control_sin_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef control_sin_COMMON_INCLUDES_
# define control_sin_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // control_sin_COMMON_INCLUDES_

#include "control_sin_types.h"
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
  SL_Bus_control_sin_balldroid_msgs_Imu In1;// '<S7>/In1'
  SL_Bus_control_sin_balldroid_msgs_Imu b_varargout_2;
  SL_Bus_control_sin_balldroid_msgs_MoveWheel BusAssignment1;// '<Root>/Bus Assignment1' 
  char_T cv0[23];
} B_control_sin_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  int32_T counter;                     // '<Root>/Sine Wave Function'
  robotics_slros_internal_block_T obj; // '<S5>/SinkBlock'
  robotics_slros_internal_block_T obj_n;// '<S4>/SinkBlock'
  robotics_slros_internal_block_T obj_p;// '<S3>/SinkBlock'
  robotics_slros_internal_blo_a_T obj_e;// '<S6>/SourceBlock'
} DW_control_sin_T;

// Parameters (auto storage)
struct P_control_sin_T_ {
  SL_Bus_control_sin_balldroid_msgs_Imu Out1_Y0;// Computed Parameter: Out1_Y0
                                                //  Referenced by: '<S7>/Out1'

  SL_Bus_control_sin_balldroid_msgs_Imu Constant_Value;// Computed Parameter: Constant_Value
                                                       //  Referenced by: '<S6>/Constant'

  SL_Bus_control_sin_balldroid_msgs_MoveWheel Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                               //  Referenced by: '<S1>/Constant'

  SL_Bus_control_sin_balldroid_msgs_Dynamixel Constant_Value_l0;// Computed Parameter: Constant_Value_l0
                                                                //  Referenced by: '<S2>/Constant'

  real_T Constant6_Value;              // Expression: -1
                                       //  Referenced by: '<Root>/Constant6'

  real_T Constant3_Value;              // Expression: 180
                                       //  Referenced by: '<Root>/Constant3'

  real_T Constant4_Value;              // Expression: 11.38
                                       //  Referenced by: '<Root>/Constant4'

  real_T Constant5_Value;              // Expression: 50
                                       //  Referenced by: '<Root>/Constant5'

  real_T Constant_Value_m;             // Expression: 1
                                       //  Referenced by: '<Root>/Constant'

  real_T Constant7_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant7'

  real_T SineWaveFunction_Amp;         // Expression: 1
                                       //  Referenced by: '<Root>/Sine Wave Function'

  real_T SineWaveFunction_Bias;        // Expression: 0
                                       //  Referenced by: '<Root>/Sine Wave Function'

  real_T SineWaveFunction_NumSamp;     // Expression: 3000
                                       //  Referenced by: '<Root>/Sine Wave Function'

  real_T SineWaveFunction_Offset;      // Expression: 0
                                       //  Referenced by: '<Root>/Sine Wave Function'

  real_T Constant1_Value;              // Expression: 700
                                       //  Referenced by: '<Root>/Constant1'

  int32_T Constant2_Value;             // Computed Parameter: Constant2_Value
                                       //  Referenced by: '<Root>/Constant2'

};

// Real-time Model Data Structure
struct tag_RTM_control_sin_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_control_sin_T control_sin_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_control_sin_T control_sin_B;

// Block states (auto storage)
extern DW_control_sin_T control_sin_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void control_sin_initialize(void);
  extern void control_sin_step(void);
  extern void control_sin_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_control_sin_T *const control_sin_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion


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
//  '<Root>' : 'control_sin'
//  '<S1>'   : 'control_sin/Blank Message1'
//  '<S2>'   : 'control_sin/Blank Message2'
//  '<S3>'   : 'control_sin/Publish1'
//  '<S4>'   : 'control_sin/Publish2'
//  '<S5>'   : 'control_sin/Publish3'
//  '<S6>'   : 'control_sin/Subscribe'
//  '<S7>'   : 'control_sin/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_control_sin_h_

//
// File trailer for generated code.
//
// [EOF]
//
