/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  control.c                                                           |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  October 16, 2011                                              |
|                                                                             |
|  Description:                                                               |
|  This contains all code for control: step control, current control, etc...  |
+----------------------------------------------------------------------------*/


// includes
#include control.h


/*----------------------------------------------------------------------------+
|  Description:                                                               |
|  When a pulse is received on the STEP line, new current commands are set    |
|  for each phase.  These current commands are based on a sinusoidal stepping |
|  pattern and the peak current.  To accomplish this, there is a sine table   |
|  in memory with one quarter of a full sine wave (90 degrees).  To get a     |
|  full sine wave, we walk up and down that table and multiply by -1 when     |
|  necessary.  Phase one leads phase two by 90 degrees, so they start on      |
|  opposite sides of the table.  The sinusoidal stepping pattern is necessary |
|  only for microstepping.  If the microstepping mode (uStep) is set to       |
|  USTEP1 (64), the current will only be full, zero or negative full.  The    |
|  sine table has 65 steps in it, making it ideal for microstepping down to   |
|  step sizes of 1/64 of a full step.                                         |
+----------------------------------------------------------------------------*/
void stepInterrupt(void){
// TODO: set interrupt vector
// TODO: add code for other stepper types (right now just bipolar)

	// check direction
	if(DIR==1){  //forward
		curStep += uStep;  
	} else {  //backward
		curStep -= uStep;
		// TODO: make sure subtraction from zero rolls over the way I think it should
	}

	// set new current commands
	if(curStep<64){  //less than 90 degrees
		iCommand1 = iLimit1/255*sine(curStep);
		iCommand2 = iLimit1/255*sine(64-curStep);
	} else if(curStep<128){  //less than 180 degrees
		iCommand1 = iLimit1/255*sine(128-curStep);
		iCommand2 = -iLimit1/255*sine(curStep-64);
	} else if(curStep<192){  //less than 270 degrees
		iCommand1 = -iLimit1/255*sine(curStep-128);
		iCommand2 = -iLimit1/255*sine(192-curStep);
	} else{  //less than 360 degrees
		iCommand1 = -iLimit1/255*sine(256-curStep);
		iCommand2 = iLimit1/255*sine(curStep-192);
	}
}


void iControl(void){
	
}


void initControlTimer(void){
	
}


