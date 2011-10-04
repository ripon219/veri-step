/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  mainScan.c                                                          |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  September 29, 2011                                            |
|                                                                             |
|  Description:                                                               |
|  The main scan handles nearly all functioning of the controller.  It's      |
|  primary purpose is to control current and PWM duty cycle according to the  |
|  mode and settings.  It also performs periodic checks of input buffers from |
|  communication peripherals (USB and I2C) and triggers the appropriate       |
|  functions.                                                                 |
+----------------------------------------------------------------------------*/


#include "mainScan.h"


void mainScan(void){

}


/*----------------------------------------------------------------------------+
|  Description:                                                               |
|  Initializes the timer to trigger the main scan every T seconds.            |
+----------------------------------------------------------------------------*/
void mainScanInit(void){

}

