//
// File: control_sin.cpp
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
#include "control_sin.h"
#include "control_sin_private.h"
#define control_sin_MessageQueueLen    (1)

// Block signals (auto storage)
B_control_sin_T control_sin_B;

// Block states (auto storage)
DW_control_sin_T control_sin_DW;

// Real-time model
RT_MODEL_control_sin_T control_sin_M_;
RT_MODEL_control_sin_T *const control_sin_M = &control_sin_M_;

// Model step function
void control_sin_step(void)
{
  boolean_T b_varargout_1;
  SL_Bus_control_sin_balldroid_msgs_Dynamixel rtb_BusAssignment2;
  real_T rtb_Product3;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S7>/In1'

  b_varargout_1 = Sub_control_sin_8.getLatestMessage
    (&control_sin_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (b_varargout_1) {
    control_sin_B.In1 = control_sin_B.b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   Constant: '<Root>/Constant2'

  rtb_BusAssignment2.Id = control_sin_P.Constant2_Value;
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

  rtb_Product3 = floor((control_sin_B.In1.Euler.Y *
                        control_sin_P.Constant6_Value +
                        control_sin_P.Constant3_Value) *
                       control_sin_P.Constant4_Value +
                       control_sin_P.Constant5_Value);
  if (rtIsNaN(rtb_Product3) || rtIsInf(rtb_Product3)) {
    rtb_Product3 = 0.0;
  } else {
    rtb_Product3 = fmod(rtb_Product3, 4.294967296E+9);
  }

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion2'

  rtb_BusAssignment2.TargetPos = rtb_Product3 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product3 : (int32_T)(uint32_T)rtb_Product3;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S4>/SinkBlock'
  Pub_control_sin_84.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // Product: '<Root>/Product3' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Sin: '<Root>/Sine Wave Function'

  rtb_Product3 = (sin(((real_T)control_sin_DW.counter +
                       control_sin_P.SineWaveFunction_Offset) * 2.0 *
                      3.1415926535897931 /
                      control_sin_P.SineWaveFunction_NumSamp) *
                  control_sin_P.SineWaveFunction_Amp +
                  control_sin_P.SineWaveFunction_Bias) *
    control_sin_P.Constant1_Value;

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant7'
  //   Constant: '<S1>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  control_sin_B.BusAssignment1 = control_sin_P.Constant_Value_l;
  control_sin_B.BusAssignment1.NoWheel = (control_sin_P.Constant_Value_m != 0.0);
  control_sin_B.BusAssignment1.Direction = (control_sin_P.Constant7_Value != 0.0);
  control_sin_B.BusAssignment1.Velocity = rtb_Product3;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S3>/SinkBlock'
  Pub_control_sin_30.publish(&control_sin_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment3' incorporates:
  //   Constant: '<Root>/Constant7'
  //   Constant: '<S1>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  control_sin_B.BusAssignment1 = control_sin_P.Constant_Value_l;
  control_sin_B.BusAssignment1.NoWheel = (control_sin_P.Constant7_Value != 0.0);
  control_sin_B.BusAssignment1.Direction = (control_sin_P.Constant7_Value != 0.0);
  control_sin_B.BusAssignment1.Velocity = rtb_Product3;

  // Outputs for Atomic SubSystem: '<Root>/Publish3'
  // Start for MATLABSystem: '<S5>/SinkBlock'
  Pub_control_sin_107.publish(&control_sin_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish3'

  // Update for Sin: '<Root>/Sine Wave Function'
  control_sin_DW.counter++;
  if (control_sin_DW.counter == control_sin_P.SineWaveFunction_NumSamp) {
    control_sin_DW.counter = 0;
  }

  // End of Update for Sin: '<Root>/Sine Wave Function'
}

// Model initialize function
void control_sin_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(control_sin_M, (NULL));

  // block I/O
  (void) memset(((void *) &control_sin_B), 0,
                sizeof(B_control_sin_T));

  // states (dwork)
  (void) memset((void *)&control_sin_DW, 0,
                sizeof(DW_control_sin_T));

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
    // Start for MATLABSystem: '<S6>/SourceBlock'
    control_sin_DW.obj_e.isInitialized = 0;
    control_sin_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_5[i] = tmp_2[i];
    }

    tmp_5[8] = '\x00';
    Sub_control_sin_8.createSubscriber(tmp_5, control_sin_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    control_sin_DW.obj_n.isInitialized = 0;
    control_sin_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[14] = '\x00';
    Pub_control_sin_84.createPublisher(tmp_4, control_sin_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish2'

    // Start for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    control_sin_DW.obj_p.isInitialized = 0;
    control_sin_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      control_sin_B.cv0[i] = tmp_0[i];
    }

    control_sin_B.cv0[22] = '\x00';
    Pub_control_sin_30.createPublisher(control_sin_B.cv0,
      control_sin_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish1'

    // Start for Atomic SubSystem: '<Root>/Publish3'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    control_sin_DW.obj.isInitialized = 0;
    control_sin_DW.obj.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      tmp_3[i] = tmp[i];
    }

    tmp_3[21] = '\x00';
    Pub_control_sin_107.createPublisher(tmp_3, control_sin_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish3'

    // InitializeConditions for Sin: '<Root>/Sine Wave Function'
    control_sin_DW.counter = 0;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S7>/Out1'
    control_sin_B.In1 = control_sin_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'
  }
}

// Model terminate function
void control_sin_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (control_sin_DW.obj_e.isInitialized == 1) {
    control_sin_DW.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S4>/SinkBlock'
  if (control_sin_DW.obj_n.isInitialized == 1) {
    control_sin_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S3>/SinkBlock'
  if (control_sin_DW.obj_p.isInitialized == 1) {
    control_sin_DW.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish3'
  // Start for MATLABSystem: '<S5>/SinkBlock'
  if (control_sin_DW.obj.isInitialized == 1) {
    control_sin_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish3'
}

//
// File trailer for generated code.
//
// [EOF]
//
