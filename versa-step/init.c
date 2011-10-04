/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  init.c                                                              |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  September 27, 2011                                            |
|                                                                             |
|  Description:                                                               |
|                                                                             |
+----------------------------------------------------------------------------*/

#include "init.h"
#include "i2c.h"
#include "flashMem.h"
#include "mainScan.h"
#include "pwm.h"

void initialize(){

    // initialize clock
	clockInit();

	// initialize io
	ioInit();

    // initialize USB
	//usbInit();

    // initialize I2C
	i2cInit();

    // load settings
	loadSettings();

	// initialize PWM modules
	pwmInit();

    // initialize main scan interrupt
	mainScanInit();

}


void clockInit(void){
	
	OSCTUNE |= INTSRC & PLLEN;  //set low frequency clock source and enable PLL
	OSCCON |= IRCF2 & IRCF1;  //set internal oscillator to 4 MHz
}


void ioInit(void){
	
}


//void usbInit(void);
