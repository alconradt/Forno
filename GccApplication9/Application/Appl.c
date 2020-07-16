/*
 * Appl.c
 *
 *  Created on: 04/09/2017
 *      Author: MAASDN
 */

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\Forno\GccApplication9\Header\C_types.h>
#include <Z:\Forno\GccApplication9\Header\Appl.h>
#include <Z:\Forno\GccApplication9\Header\Display.h>
//#include <alloca.h>
#include <Z:\Forno\GccApplication9\Header\Gpio.h>


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

/**
 *  Inicializa variável referente a ação do user
 */

void Appl__Initialize(void)
{
	User_Action = EVENTS_NO_EVENT;
}

/**
 *  Muda o estado do forno em função da ação do user pelas chaves 
 */

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
Display__Handler();  //Faz o display(leds) do estado do forno
}

//---------------------------------------------------------------------------------------------------------------------



