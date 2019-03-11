//
// File: control.cpp
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
#include "control.h"
#include "control_private.h"
#define control_MessageQueueLen        (1)

// Block signals (auto storage)
B_control_T control_B;

// Block states (auto storage)
DW_control_T control_DW;

// Real-time model
RT_MODEL_control_T control_M_;
RT_MODEL_control_T *const control_M = &control_M_;

// Model step function
void control_step(void)
{
  boolean_T b_varargout_1;
  SL_Bus_control_balldroid_msgs_Dynamixel rtb_BusAssignment2;
  SL_Bus_control_balldroid_msgs_Dynamixel rtb_BusAssignment1;
  real_T rtb_Product5;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  b_varargout_1 = Sub_control_8.getLatestMessage(&control_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (b_varargout_1) {
    control_B.In1 = control_B.b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<Root>/Constant7'

  rtb_BusAssignment1.Id = control_P.Constant7_Value;
  rtb_BusAssignment1.CurrentPos = 0;

  // DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
  //   Constant: '<Root>/Constant10'
  //   Constant: '<Root>/Constant11'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<Root>/Constant9'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Sum: '<Root>/Add2'
  //   Sum: '<Root>/Add3'

  rtb_Product5 = floor((control_B.In1.Euler.Z * control_P.Constant11_Value +
                        control_P.Constant8_Value) * control_P.Constant9_Value +
                       control_P.Constant10_Value);
  if (rtIsNaN(rtb_Product5) || rtIsInf(rtb_Product5)) {
    rtb_Product5 = 0.0;
  } else {
    rtb_Product5 = fmod(rtb_Product5, 4.294967296E+9);
  }

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion4'

  rtb_BusAssignment1.TargetPos = rtb_Product5 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product5 : (int32_T)(uint32_T)rtb_Product5;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S4>/SinkBlock'
  Pub_control_141.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   Constant: '<Root>/Constant2'

  rtb_BusAssignment2.Id = control_P.Constant2_Value;
  rtb_BusAssignment2.CurrentPos = 0;

  // DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<Root>/Constant6'
  //   Product: '<Root>/Product1'
  //   Product: '<Root>/Product2'
  //   Sum: '<Root>/Add'
  //   Sum: '<Root>/Add1'

  rtb_Product5 = floor((control_B.In1.Euler.X * control_P.Constant6_Value +
                        control_P.Constant3_Value) * control_P.Constant4_Value +
                       control_P.Constant5_Value);
  if (rtIsNaN(rtb_Product5) || rtIsInf(rtb_Product5)) {
    rtb_Product5 = 0.0;
  } else {
    rtb_Product5 = fmod(rtb_Product5, 4.294967296E+9);
  }

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion2'

  rtb_BusAssignment2.TargetPos = rtb_Product5 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product5 : (int32_T)(uint32_T)rtb_Product5;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S5>/SinkBlock'
  Pub_control_84.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  rtb_Product5 = floor(control_B.In1.Euler.Y);
  if (rtIsNaN(rtb_Product5) || rtIsInf(rtb_Product5)) {
    rtb_Product5 = 0.0;
  } else {
    rtb_Product5 = fmod(rtb_Product5, 4.294967296E+9);
  }

  // Product: '<Root>/Product5' incorporates:
  //   Constant: '<Root>/Constant14'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  rtb_Product5 = (real_T)(rtb_Product5 < 0.0 ? -(int32_T)(uint32_T)-rtb_Product5
    : (int32_T)(uint32_T)rtb_Product5) * control_P.Constant14_Value;

  // BusAssignment: '<Root>/Bus Assignment4' incorporates:
  //   Constant: '<Root>/Constant13'
  //   Constant: '<Root>/Constant15'
  //   Constant: '<S3>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion5'
  //   DataTypeConversion: '<Root>/Data Type Conversion7'

  control_B.BusAssignment4 = control_P.Constant_Value_i;
  control_B.BusAssignment4.NoWheel = (control_P.Constant13_Value != 0.0);
  control_B.BusAssignment4.Direction = (control_P.Constant15_Value != 0.0);
  control_B.BusAssignment4.Velocity = rtb_Product5;

  // Outputs for Atomic SubSystem: '<Root>/Publish4'
  // Start for MATLABSystem: '<S6>/SinkBlock'
  Pub_control_124.publish(&control_B.BusAssignment4);

  // End of Outputs for SubSystem: '<Root>/Publish4'

  // BusAssignment: '<Root>/Bus Assignment5' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant15'
  //   Constant: '<S3>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion3'
  //   DataTypeConversion: '<Root>/Data Type Conversion7'

  control_B.BusAssignment4 = control_P.Constant_Value_i;
  control_B.BusAssignment4.NoWheel = (control_P.Constant1_Value != 0.0);
  control_B.BusAssignment4.Direction = (control_P.Constant15_Value != 0.0);
  control_B.BusAssignment4.Velocity = rtb_Product5;

  // Outputs for Atomic SubSystem: '<Root>/Publish5'
  // Start for MATLABSystem: '<S7>/SinkBlock'
  Pub_control_125.publish(&control_B.BusAssignment4);

  // End of Outputs for SubSystem: '<Root>/Publish5'
}

// Model initialize function
void control_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(control_M, (NULL));

  // block I/O
  (void) memset(((void *) &control_B), 0,
                sizeof(B_control_T));

  // states (dwork)
  (void) memset((void *)&control_DW, 0,
                sizeof(DW_control_T));

  {
    static const char_T tmp[21] = { '/', 'e', 'p', 'o', 's', '/', 'm', 'o', 'v',
      'e', '_', 'w', 'h', 'e', 'e', 'l', '/', 'l', 'e', 'f', 't' };

    static const char_T tmp_0[22] = { '/', 'e', 'p', 'o', 's', '/', 'm', 'o',
      'v', 'e', '_', 'w', 'h', 'e', 'e', 'l', '/', 'r', 'i', 'g', 'h', 't' };

    static const char_T tmp_1[14] = { '/', 'd', 'y', 'n', 'a', 'm', 'i', 'x',
      'e', 'l', '/', 'c', 'm', 'd' };

    static const char_T tmp_2[8] = { '/', 'i', 'm', 'u', '_', 'u', 's', 'b' };

    char_T tmp_3[22];
    char_T tmp_4[15];
    char_T tmp_5[9];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    control_DW.obj_e.isInitialized = 0;
    control_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_5[i] = tmp_2[i];
    }

    tmp_5[8] = '\x00';
    Sub_control_8.createSubscriber(tmp_5, control_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    control_DW.obj_j.isInitialized = 0;
    control_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[14] = '\x00';
    Pub_control_141.createPublisher(tmp_4, control_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish1'

    // Start for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    control_DW.obj_n.isInitialized = 0;
    control_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[14] = '\x00';
    Pub_control_84.createPublisher(tmp_4, control_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish2'

    // Start for Atomic SubSystem: '<Root>/Publish4'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    control_DW.obj_a.isInitialized = 0;
    control_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      control_B.cv0[i] = tmp_0[i];
    }

    control_B.cv0[22] = '\x00';
    Pub_control_124.createPublisher(control_B.cv0, control_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish4'

    // Start for Atomic SubSystem: '<Root>/Publish5'
    // Start for MATLABSystem: '<S7>/SinkBlock'
    control_DW.obj.isInitialized = 0;
    control_DW.obj.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      tmp_3[i] = tmp[i];
    }

    tmp_3[21] = '\x00';
    Pub_control_125.createPublisher(tmp_3, control_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish5'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S9>/Out1'
    control_B.In1 = control_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'
  }
}

// Model terminate function
void control_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (control_DW.obj_e.isInitialized == 1) {
    control_DW.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S4>/SinkBlock'
  if (control_DW.obj_j.isInitialized == 1) {
    control_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S5>/SinkBlock'
  if (control_DW.obj_n.isInitialized == 1) {
    control_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish4'
  // Start for MATLABSystem: '<S6>/SinkBlock'
  if (control_DW.obj_a.isInitialized == 1) {
    control_DW.obj_a.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish4'

  // Terminate for Atomic SubSystem: '<Root>/Publish5'
  // Start for MATLABSystem: '<S7>/SinkBlock'
  if (control_DW.obj.isInitialized == 1) {
    control_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish5'
}

//
// File trailer for generated code.
//
// [EOF]
//
