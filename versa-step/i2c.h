/*----------------------------------------------------------------------------+
|  Project:  Versa Step                                                       |
|  File:  i2c.h                                                               |
|  Author:  Jonathan L Breen                                                  |
|  Created on:  September 29, 2011                                            |
|                                                                             |
|  Description:                                                               |
|                                                                             |
+----------------------------------------------------------------------------*/


// function prototypes
void i2cInit(void);
void i2cSendByte(char);
void i2cInterrupt(void);