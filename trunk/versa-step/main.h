/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  main.h                                                              |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  September 27, 2011                                            |
|                                                                             |
|  Description:                                                               |
|  This contains all global variables and settings.                           |
+----------------------------------------------------------------------------*/


// defines for USB library's use
//#define __18CXX
//#define __18F46J50
//#define DEMO_BOARD

// includes
#include "HardwareProfile.h"
#include <htc.h>
#include "init.h"


// global settings variables
char curMode = 0;  //the current mode the VersaStep is in (use MODE enum)
const char BIPOLAR = 0;		//for driving a bipolar stepper motor
const char UNIPOLAR = 1;	//for driving a unipolar stepper motor
const char DUAL_H_I = 2;	//2 independent H-bridges in current mode
const char DUAL_H_V = 3;	//2 independent H-bridges in voltage mode
const char QUAD_LSD_I = 4;	//4 independent low-side drivers in current mode
const char QUAD_LSD_V = 5;	//4 independent low-side drivers in voltage mode

unsigned short faultCurLimit = 12000;  //(mA) maximum current for any channel in any mode 
									   //this is intended to be hardware protection and will
									   //disable the output when exceeded

unsigned short curLimit1 = 2100;  //(mA) bipolar or unipolar - maximum phase current
								  //dual H-bridge - max current for bridge A
								  //quad LSD - max current for A1

unsigned short curLimit2 = 2100;  //(mA) bipolar or unipolar - not used
								  //dual H-bridge - max current for bridge B
								  //quad LSD - max current for A2

unsigned short curLimit3 = 2100;  //(mA) bipolar or unipolar - not used
								  //dual H-bridge - not used
								  //quad LSD - max current for B1

unsigned short curLimit4 = 2100;  //(mA) bipolar or unipolar - not used
								  //dual H-bridge - not used
								  //quad LSD - max current for B2

// motor physical parameters (used for control parameter estimation)
long R_load = 1000;  //(mOhms) the winding resistance of the motor or load
int L_load = 100;  //(uH) the winding inductance of the motor or load


// function prototypes
void main(void);