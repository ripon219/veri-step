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

void initialize(){

    // initialize clock

	// initialize io

    // initialize USB

    // initialize I2C
	i2cInit();

    // load settings
	loadSettings();

    // initialize main scan interrupt
	mainScanInit();

}

void clockInit(void){

}


void ioInit(void){

}


//void usbInit(void);
