/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Arduino_h
#define Arduino_h

// Useful C libraries
#include <math.h>
#include <time.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mbed.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include "wiring_constants.h"

#define F_CPU SystemCoreClock //To be compatible with Arduino delay

#define clockCyclesPerMicrosecond() ( SystemCoreClock / 1000000L )
#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (SystemCoreClock / 1000L) )
#define microsecondsToClockCycles(a) ( (a) * (SystemCoreClock / 1000000L) )

void yield(void);

/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;


/* Types used for the tables below */
typedef struct _PinDescription
{
  uint32_t arduino_id;
  uint32_t ulPin ;
  GPIO_TypeDef  * ulPort;
  uint32_t mode;
  bool configured;
} PinDescription ;

#define NB_PIN_DESCRIPTIONS (16*3)

/* Pins table to be instanciated into variant.cpp */
extern const PinDescription g_APinDescription[] ;


/* Define attribute */
#if defined   ( __CC_ARM   ) /* Keil uVision 4 */
    #define WEAK (__attribute__ ((weak)))
#elif defined ( __ICCARM__ ) /* IAR Ewarm 5.41+ */
    #define WEAK __weak
#elif defined (  __GNUC__  ) /* GCC CS */
    #define WEAK __attribute__ ((weak))
#endif
#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#include "wiring.h"
#include "wiring_digital.h"
#include "WMath.h"
#include "wiring_analog.h"

#include "variant.h"

#include "WString.h"
#include "WCharacter.h"
#include "Stream.h"
#include "AudioClass.h"	

#include "app_httpd.h"
#include "HTS221Sensor.h"
#include "lis2mdlSensor.h"
#include "RGB_LED.h"
#include "LSM6DSLSensor.h"
#include "lps22hbSensor.h"
#include "IrDASensor.h"
#include "version.h"

#endif