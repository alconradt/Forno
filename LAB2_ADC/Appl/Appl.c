/*
 * Appl.c
 *
 *  Created on: 13/05/2019
 *      Author: MAASDN
 */

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\C_Types.h>
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Appl.h>
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Display.h>
//#include <alloca.h>
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Gpio.h>
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Adc.h>
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Hal.h>
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\OvenTempControl.h>

//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------
KEY_EVENT_TYPE User_Action;

//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------
#define EXP_ADC                ENABLED
#define EXP_OVEN               ENABLED

#define ACENDE_LED               0
#define APAGA_LED                1

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
{//unsigned short int ad_value;
	
#if (EXP_OVEN == ENABLED)	
	    User_Action = Display__GetEvent();
		if (User_Action != EVENTS_NO_EVENT)
		    {
			switch(User_Action)
			    {
			    case KEY_OFF_EVENT:
				   Display__SetState(OVEN_OFF);
				   OvenTempControl__SetLevel(TEMP_LEVEL_OVEN_OFF);
				   break;
				
			    case KEY_MIN_EVENT:
			          Display__SetState(OVEN_MIN);
					  OvenTempControl__SetLevel(TEMP_LEVEL_MIN);
				      break;
							
				 case KEY_MED_EVENT:
					  Display__SetState(OVEN_MED);
					  OvenTempControl__SetLevel(TEMP_LEVEL_MED);
					  break;
				
			     case KEY_MAX_EVENT:
				      Display__SetState(OVEN_MAX);
					  OvenTempControl__SetLevel(TEMP_LEVEL_MAX);
				      break;
			//case KEY_NONE:
			  //  Display__SetState(OVEN_INIT);
             //   break;
			     default:
				    break;

			}
		}
Display__Handler();
#endif   // (EXP_OVEN == ENABLED

#if (EXP_ADC == ENABLED)
//ad_value = Hal_GetAnalogInput(POT_EXT);
//if (ad_value > 512)
 //  Hal__SetLed(LED_3, 0);
// else
 //   Hal__SetLed(LED_3, 1);
#endif // (EXP_ADC == ENABLED)
}
//---------------------------------------------------------------------------------------------------------------------



