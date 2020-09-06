/*
 * Appl.c
 *
 *  Created on: 13/05/2019
 *      Author: MAASDN
 */

//-------------------------------------- Include Files ----------------------------------------------------------------

#include <Z:\AAM_EXP3\LAB3_PWM\Header\C_Types.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Appl.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Display.h>
//#include <alloca.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Gpio.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Adc.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Hal.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\OvenTempControl.h>

#include <Z:\AAM_EXP3\LAB3_PWM\Header\Pwm.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Sounds.h>

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
	Sounds__PlaySounds(SOUND_POWER_ON);    //buzzer de power on
}


void Appl__Handler(void)
{//unsigned short int ad_value;
	
#if (EXP_OVEN == ENABLED)
        Sounds__PlaySounds(PLAY_NO_SOUND); 	
	    User_Action = Display__GetEvent();
		if (User_Action != EVENTS_NO_EVENT)
		    {
			switch(User_Action)
			    {
			    case KEY_OFF_EVENT:
				   Display__SetState(OVEN_OFF);
				   OvenTempControl__SetLevel(TEMP_LEVEL_OVEN_OFF);
				   Hal__SetBuzzerFreq(4000);
				   Sounds__PlaySounds(SOUND_KEY_PRESS);    //buzzer de key press
				   break;
				
			    case KEY_MIN_EVENT:
			          Display__SetState(OVEN_MIN);
					  OvenTempControl__SetLevel(TEMP_LEVEL_MIN);
					  Hal__SetBuzzerFreq(2000);
					  Sounds__PlaySounds(SOUND_KEY_PRESS);    //buzzer de key press
				      break;
							
				 case KEY_MED_EVENT:
					  Display__SetState(OVEN_MED);
					  OvenTempControl__SetLevel(TEMP_LEVEL_MED);
					  Hal__SetBuzzerFreq(3000);
				      Sounds__PlaySounds(SOUND_KEY_PRESS);    //buzzer de key press
					  break;
				
			     case KEY_MAX_EVENT:
				      Display__SetState(OVEN_MAX);
					  OvenTempControl__SetLevel(TEMP_LEVEL_MAX);
					  Hal__SetBuzzerFreq(5000);
					  Sounds__PlaySounds(SOUND_KEY_PRESS);    //buzzer de key press
				      break;
			case KEY_NONE:
			  		Sounds__PlaySounds(PLAY_NO_SOUND);    //buzzer de key press
			  		break;
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



