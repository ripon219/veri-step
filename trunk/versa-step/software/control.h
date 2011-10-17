/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  control.h                                                           |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  October 16, 2011                                              |
|                                                                             |
|  Description:                                                               |
|  This contains parameters for the control routines, including physical      |
|  motor parameters and the speed of the control loop.                        |
+----------------------------------------------------------------------------*/


// includes
#include main.h


// function prototypes
void stepInterrupt(void);
void iControl(void);
void initControlTimer(void);


// parameters
#define CONTROL_FREQ 24000	//(Hz) the frequency for the closed-loop current control
char curStep = 0;  //keeps track of microstepping position
short iCommand1 = 0;  //(mA) Current command for H-bridge 1 (can be negative)
short iCommand2 = 0;  //(mA) Current command for H-bridge 2 (can be negative)

// motor physical parameters (used for control parameter estimation)
long R_load = 1000;  //(mOhms) the winding resistance of the motor or load
int L_load = 100;  //(uH) the winding inductance of the motor or load