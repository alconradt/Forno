/*
 * Display.h
 *
 *  Created on: 10/09/2017
 *      Author: MAASDN
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Display_prm.h>


//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------


typedef enum
{
	OVEN_OFF = 0,
	OVEN_MIN,
	OVEN_MED,
	OVEN_MAX,
	OVEN_INIT,
	OVEN_TIMEOUT,
	NUM_OF_OVEN_STATES
}OVEN_DISPLAY_STATE_TYPE;

typedef enum
{
	KEY_OFF_EVENT = 0,
	KEY_MIN_EVENT,
	KEY_MED_EVENT,
	KEY_MAX_EVENT,
	NUM_OF_KEYS_EVENTS
}KEY_EVENT_TYPE;

#define KEY_NONE		0xAA
#define EVENTS_NO_EVENT 0xFF
//=====================================================================================================================
//-------------------------------------- PUBLIC (Function Prototypes) -------------------------------------------------
//=====================================================================================================================
void Display__Initialize(void);
void Display__Handler(void);
void Display__SetState(OVEN_DISPLAY_STATE_TYPE state);
//unsigned char Display__GetUserKeyMap(void);
KEY_EVENT_TYPE Display__GetEvent(void);



#endif /* DISPLAY_H_ */
