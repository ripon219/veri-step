#ifndef __MAIN_H
#define __MAIN_H
/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  main.h                                                              |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  September 27, 2011                                            |
|                                                                             |
|  Description:                                                               |
|  This contains all global variables and settings.  By convention here,      |
|  "cur" means current as in at the present moment, and "i" means current as  |
|  in electron flow.                                                          |
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
#define BIPOLAR		0	//for driving a bipolar stepper motor
#define UNIPOLAR	1	//for driving a unipolar stepper motor
#define DUAL_H_I	2	//2 independent H-bridges in current mode
#define DUAL_H_V	3	//2 independent H-bridges in voltage mode
#define QUAD_LSD_I	4	//4 independent low-side drivers in current mode
#define QUAD_LSD_V	5	//4 independent low-side drivers in voltage mode

unsigned short faultILimit = 12000;  //(mA) maximum current for any channel in any mode 
									 //this is intended to be hardware protection and will
									 //disable the output when exceeded

unsigned short iLimit1 = 2100;  //(mA) bipolar or unipolar - maximum phase current
								//dual H-bridge - max current for bridge A
								//quad LSD - max current for A1

unsigned short iLimit2 = 2100;  //(mA) bipolar or unipolar - not used
								//dual H-bridge - max current for bridge B
								//quad LSD - max current for A2

unsigned short iLimit3 = 2100;  //(mA) bipolar or unipolar - not used
								//dual H-bridge - not used
								//quad LSD - max current for B1

unsigned short iLimit4 = 2100;  //(mA) bipolar or unipolar - not used
								//dual H-bridge - not used
								//quad LSD - max current for B2


// current decay mode
char iDecay = 0;  //the current decay mode in use
#define FAST_DECAY	0		//current is pushed up and pulled down
#define SLOW_DECAY	1		//current is pushed up and "freewheeled" down


// microstepping modes
char uStep = 1;  //the microstepping mode in use
#define USTEP1		64		//no microstepping
#define USTEP2		32		//(1/2) stepping
#define USTEP4		16		//(1/4) stepping
#define USTEP8		8		//(1/8) stepping
#define USTEP16		4		//(1/16) stepping
#define USTEP32		2		//(1/32) stepping
#define USTEP64		1		//(1/64) stepping


// IO names
#define DIR @RA6
#define STEP @RB4
#define STATUS_LED @LATA7
#define OVERLOAD_LED @LATB3


// sine table for microstepping currents
// 90 degrees - 65 steps - 8-bit precision
char sine = {0,6,13,19,25,31,38,44,50,56,62,68,74,80,86,92,98,104,109,
			115,121,126,132,137,142,147,152,157,162,167,172,177,181,
			185,190,194,198,202,206,209,213,216,220,223,226,229,231,
			234,237,239,241,243,245,247,248,250,251,252,253,254,255,
			255,256,256,256};

//


// function prototypes
void main(void);


#endif