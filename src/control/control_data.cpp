//
// File: control_data.cpp
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

// Block parameters (auto storage)
P_control_T control_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S9>/Out1'

  {
    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    },                                 // Header

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Euler

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Gyro

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Accel
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S8>/Constant'

  {
    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    },                                 // Header

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Euler

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Gyro

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Accel
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S3>/Constant'

  {
    false,                             // NoWheel
    false,                             // Direction
    0.0,                               // Velocity

    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0.0,                           // Sec
        0.0                            // Nsec
      }                                // Stamp
    }                                  // Header
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S1>/Constant'

  {
    0,                                 // Id
    0,                                 // CurrentPos
    0                                  // TargetPos
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S2>/Constant'

  {
    0,                                 // Id
    0,                                 // CurrentPos
    0                                  // TargetPos
  },

  // Expression: 1
  //  Referenced by: '<Root>/Constant11'

  1.0,

  // Expression: 180
  //  Referenced by: '<Root>/Constant8'

  180.0,

  // Expression: 11.38
  //  Referenced by: '<Root>/Constant9'

  11.38,

  // Expression: 40
  //  Referenced by: '<Root>/Constant10'

  40.0,

  // Expression: -1
  //  Referenced by: '<Root>/Constant6'

  -1.0,

  // Expression: 180
  //  Referenced by: '<Root>/Constant3'

  180.0,

  // Expression: 11.38
  //  Referenced by: '<Root>/Constant4'

  11.38,

  // Expression: 50
  //  Referenced by: '<Root>/Constant5'

  50.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant13'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant15'

  0.0,

  // Expression: 100
  //  Referenced by: '<Root>/Constant14'

  100.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant1'

  0.0,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<Root>/Constant7'

  0,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
