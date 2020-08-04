/*
 * Appl.c
 *
 *  Created on: 13/05/2019
 *      Author: MAASDN
 */

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\Forno\Header\C_Types.h>
#include <Z:\Forno\Header\Appl.h>
#include <Z:\Forno\Header\Display.h>
//#include <alloca.h>
#include <Z:\Forno\Header\Gpio.h>


//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------
KEY_EVENT_TYPE User_Action;

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
			//case KEY_NONE:
			  //  Display__SetState(OVEN_INIT);
             //   break;
			default:
				break;

			}
		}
//Display__Handler();
}
//---------------------------------------------------------------------------------------------------------------------



