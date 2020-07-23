/*
 * Appl.c
 
 *
 *  Created on: 13/05/2019
 *      Author: MAASDN
 */

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\C_types.h>
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\Appl.h>
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\Display.h>
//#include <alloca.h>
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\Gpio.h>


//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------
KEY_EVENT_TYPE User_Action;   // tipo no Display.h

//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------


//-------------------------------------- Global Variables ----------------------------------------------------------------

unsigned char Timer_Counter;
unsigned char Toggle;
unsigned char Trigger;
//-------------------------------------- PRIVATE (Function Prototypes) ---------------------------------------------------


//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================


void Appl__Initialize(void)
{
	User_Action = EVENTS_NO_EVENT;
}


void Appl__Handler(void)
{
User_Action = Display__GetEvent();
		if (User_Action != EVENTS_NO_EVENT)
		{
			switch(User_Action)
			{
			case KEY_OFF_EVENT:
				Display__SetState(OVEN_OFF);
				break;
				
			case KEY_MIN_EVENT:
			{
				Display__SetState(OVEN_MIN);
				break;
			}
				
			case KEY_MED_EVENT:
				Display__SetState(OVEN_MED);
				break;
				
			case KEY_MAX_EVENT:
				Display__SetState(OVEN_MAX);
				break;

			default:
				break;

			}
		}
//Display__Handler();     // retirado 19/09/19 atualiza as entradas (keys) e saidas
}
//---------------------------------------------------------------------------------------------------------------------



