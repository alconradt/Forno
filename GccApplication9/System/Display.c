/*
 * Display.c
 *
 *  Created on: 10/09/2017
 *      Author: MAASDN
 */

#define F_CPU 16000000UL

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\Forno\GccApplication9\Header\C_types.h>
#include <Z:\Forno\GccApplication9\Header\Display.h>
#include <Z:\Forno\GccApplication9\Header\Hal.h>
//#include "LcdMgr.h"
//#include "Timer.h"
#include <util/delay.h> /*biblioteca para o uso das rotinas de _delay_ms() e _delay_us()*/

//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------


//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------

#define NUM_EVENTS     		50
#define ACENDE_LED          0
#define APAGA_LED           1


//-------------------------------------- Global Variables ----------------------------------------------------------------

OVEN_DISPLAY_STATE_TYPE Oven_Display_State;      // variável global  de display

KEY_EVENT_TYPE Display_Keys_Map;                  // variável global  de keys

unsigned char value1, value2, value3;

//-------------------------------------- PRIVATE (Function Prototypes) ---------------------------------------------------

void UpdateDisplayLeds(void);
void UpdateDisplayLCD(void);
void ReadDisplayKeys(void);

//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/**
 *  Inicializa variáveis referente ao estado inicial do forno e das chaves
 */
void Display__Initialize(void)
	{
	Oven_Display_State = OVEN_INIT;
	Display_Keys_Map = KEY_OFF_EVENT;
	}

//---------------------------------------------------------------------------------------------------------------------
/**
 *   Faz o display(leds) do estado do forno
 */
void Display__Handler(void)
	{
	ReadDisplayKeys();          // lê os Keys!
	
	#if (LED_DISPLAY == ENABLED)	
	UpdateDisplayLeds();        // atualização dos leds
	#endif	

}

//---------------------------------------------------------------------------------------------------------------------
/**
 *  A função atualiza a variável global:
 *  Oven_Display_State que indica o estado do forno  
 */
void Display__SetState(OVEN_DISPLAY_STATE_TYPE state)
{
	if(state < NUM_OF_OVEN_STATES)
	{
		Oven_Display_State = state;
	}
	
}

//---------------------------------------------------------------------------------------------------------------------
/**
 *      Lê as chaves e coloca valor na variável global:
 *      Display_Keys_Map e retorna o  mesmo na função

 */


KEY_EVENT_TYPE Display__GetEvent(void)
{
	KEY_EVENT_TYPE event;
	ReadDisplayKeys();    // Lê as chaves e coloca valor na variável global Display_Keys_Map
	event = Display_Keys_Map;
	return (event);
}

//---------------------------------------------------------------------------------------------------------------------
/**
 *  
 */
//=====================================================================================================================
//-------------------------------------- PRIVATE Functions -------------------------------------------------------------
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/**
 *   Atualiza os estados dos leds  
 */
void UpdateDisplayLeds(void)
{
	
	switch(Oven_Display_State)
	{
	case OVEN_OFF:
	{
	       Hal__SetAllLeds(APAGA_LED);
		   break;
	}
	case OVEN_INIT:
	case OVEN_TIMEOUT:
	   		
		break;

	case OVEN_MIN:
	{
		Hal__SetLed(LED_0, ACENDE_LED);
		Hal__SetLed(LED_1, APAGA_LED);
		Hal__SetLed(LED_2, APAGA_LED);
		break;
	}
	case OVEN_MED:
	{
		Hal__SetLed(LED_0, ACENDE_LED);
		Hal__SetLed(LED_1, ACENDE_LED);
		Hal__SetLed(LED_2, APAGA_LED);
		break;
	}
	case OVEN_MAX:
	{
		Hal__SetLed(LED_0, ACENDE_LED);
		Hal__SetLed(LED_1, ACENDE_LED);
		Hal__SetLed(LED_2, ACENDE_LED);
		break;
	}
		
	default:
	{
	break;
	}
 }
}


//---------------------------------------------------------------------------------------------------------------------
/**
 *  Atualiza a variável global (Display_Keys_Map) das chaves
 *  chamando Hal_ReadKey()
 */
void ReadDisplayKeys(void)
{
	value1 = Hal__ReadKey(KEY_0);
	value2 = Hal__ReadKey(KEY_1);
	value3 = Hal__ReadKey(KEY_2);
		
	if (value1==0 && value3==0)
	{
		Display_Keys_Map = KEY_OFF_EVENT;
		_delay_ms(1000);
	}
	else
	{
		if(value1 == 0)    //reads key 1 (at SW1)
		{
			Display_Keys_Map = KEY_MIN_EVENT;
		}
		if(value2 == 0)           //reads key 2 (at SW2)
		{
			Display_Keys_Map = KEY_MED_EVENT;
		}
		if(value3 == 0)   //reads key 3 (at SW3)
		{
			Display_Keys_Map = KEY_MAX_EVENT;
		}
	}
}