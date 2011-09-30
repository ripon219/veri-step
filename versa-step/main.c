/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  main.c                                                              |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  September 27, 2011                                            |
|                                                                             |
|  Description:                                                               |
|                                                                             |
+----------------------------------------------------------------------------*/


#include "main.h"

// set configuration words
__CONFIG(1,DEBUG_OFF&XINST_OFF&STVREN_ON&PLLDIV_1&WDTEN_OFF&CP0_OFF&CPUDIV_OSC2_PLL2);
__CONFIG(2,IESO_OFF&FCMEN_ON&LPT1OSC_OFF&T1DIG_OFF&OSC_INTOSCPLL&WDTPS_64);
__CONFIG(3,MSSP7B_EN_MSK7&IOL1WAY_OFF);
//__CONFIG(4,x);



void main(void) {

    // initialize
    initialize();

	while(1){  //loop continuously and wait for interrupts
		
	}

    return;
} 