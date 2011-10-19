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
#include "main.h"

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

	// set OSCTUNE bits
	INTSRC = 1;  //set low frequency clock source
	PLLEN = 1;  //enable frequency multiplier
	
	// set OSCCON bits
	IRCF2 = 1;  //set internal oscillator to 4 MHz, as required by PLL
	IRCF1 = 1;

	//SET_BITS(OSCTUNE,INTSRC & PLLEN);  //set low frequency clock source and enable PLL
	//SET_BITS(OSCCON, IRCF2 & IRCF1);  //set internal oscillator to 4 MHz
}


void ioInit(void){
	
	// set pin directions (1=input, 0=output)
	TRISA = 0b01000011;  
	TRISB = 0b11110011;
	TRISC = 0b00111100;

	// set analog functionality (1=digital, 0=analog)
	//ADCON1 = TODO
	ANCON0 = 0b11111111;  //turn off all analog channels
	ANCON1 = 0b00011111;
	PCFG2 = 0;  //turn on analog channels 2, 3, 4, and 11
	PCFG3 = 0;
	PCFG4 = 0;
	PCFG11 = 0;

	// set peripheral pins
	RPOR18 = 14;  //P1A
	RPOR17 = 15;  //P1B
	RPOR11 = 16;  //P1C
	RPOR12 = 17;  //P1D
	RPOR8 = 18;  //P2A
	RPOR5 = 19;  //P2B
	RPOR0 = 20;  //P2C
	RPOR1 = 21;  //P2D
	RPINR1 = 7;  //interrupt on step pin
	
}


//void usbInit(void);
