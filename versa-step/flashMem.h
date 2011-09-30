/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  flashMem.h                                                          |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  September 29, 2011                                            |
|                                                                             |
|  Description:                                                               |
|  This code handles all non volatile memory reads and writes.  The primary   |
|  function is saving settings between power cycles.                          |
+----------------------------------------------------------------------------*/


// includes
#include "main.h"  //this is where settings variables are defined


// function prototypes
void saveSettings(void);
void loadSettings(void);