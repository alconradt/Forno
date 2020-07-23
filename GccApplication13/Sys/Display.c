/*




 * Display.c
 *
 *  Created on: 10/09/2017
 *      Author: MAASDN
 * alterado em 16/07/2019
 *   por Ana W.
 */


//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\C_Types.h>
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\Display.h>
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\Hal.h>
#include <util/delay.h>
//#include "LcdMgr.h"
//#include "Timer.h"
//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------

unsigned char value1, value2, value3;
//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------
#define NUM_OF_DIGITOS      4      // número de segmentos do Display 7 segmentos
#define NUM_EVENTS     		50
#define ACENDE_LED          0
#define APAGA_LED           1


//-------------------------------------- Global Variables ----------------------------------------------------------------

OVEN_DISPLAY_STATE_TYPE Oven_Display_State;      // variável global  de display

KEY_EVENT_TYPE Display_Keys_Map;                  // variável global  de keys

char ZERADO_DIGITO[NUM_OF_DIGITOS] = {0xC0,0xC0,0xC0,0xC0};   //# 0000
char MINIMO_DIGITO[NUM_OF_DIGITOS] = {0xC0,0xF9,0xA4,0xC0};   //# 0180
char MEDIO_DIGITO[NUM_OF_DIGITOS] =  {0xC0,0xA4,0x92,0xC0};   //# 0250 
char MAXIMO_DIGITO[NUM_OF_DIGITOS] = {0xC0,0xB0,0xA4,0xC0};   //# 0320
	
//-------------------------------------- PRIVATE (Function Prototypes) ---------------------------------------------------

void UpdateDisplayLeds(void);
void UpdateDisplaySevenSeg(void);
void ReadDisplayKeys(void);

//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/**
 *  
 */
void Display__Initialize(void)
{
	//LCD_Current_Oven_Display = 0xFF;  comentado ATYW 19/09/18
	Oven_Display_State = OVEN_INIT;
	Display_Keys_Map = KEY_OFF_EVENT;
}

//---------------------------------------------------------------------------------------------------------------------
/**
 *  
 */
void Display__Handler(void)
{
ReadDisplayKeys();          // lê os Keys!
	
#if (LED_DISPLAY == ENABLED)	
	UpdateDisplayLeds();
#endif	

#if (SEVEN_SEG_DISPLAY == ENABLED)
	UpdateDisplaySevenSeg();
#endif
}


//---------------------------------------------------------------------------------------------------------------------
/**
 *  
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
 *  
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
 *  Atualiza  Leds 
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
/**  PRIVATE QUE LE O VALOR DA CHAVE E ATUALIZA VARIÁVEL GLOBAL Display_Key_Map
 *  
 */
void ReadDisplayKeys(void)
{
	value1 = Hal__ReadKey(KEY_0);
	value2 = Hal__ReadKey(KEY_1);
	value3 = Hal__ReadKey(KEY_2);
	if (value1==0 && value3==0)
	{
		Display_Keys_Map = KEY_OFF_EVENT;
		_delay_ms(3000);
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

/**
 *  Atualiza  7 Segmentos chamando Hal__WriteValtoSegment() para cada segmento
 */

void UpdateDisplaySevenSeg(void)
{
	
switch(Oven_Display_State)
{
	case OVEN_OFF:
	{
		// coloca o valor no 7segmento = 0000
		Hal__WriteValtoSegment((char)0, (char)ZERADO_DIGITO[0]);
		Hal__WriteValtoSegment((char)1, (char)ZERADO_DIGITO[1]);
		Hal__WriteValtoSegment((char)2, (char)ZERADO_DIGITO[2]);
		Hal__WriteValtoSegment((char)3, (char)ZERADO_DIGITO[3]);
		break;
	}
	case OVEN_INIT:
	case OVEN_TIMEOUT:
	break;
	case OVEN_MIN:
	{
		// coloca o valor no 7segmento = 0080
		Hal__WriteValtoSegment((char)0, (char)MINIMO_DIGITO[0]);
		Hal__WriteValtoSegment((char)1, (char)MINIMO_DIGITO[1]);
		Hal__WriteValtoSegment((char)2, (char)MINIMO_DIGITO[2]);
		Hal__WriteValtoSegment((char)3, (char)MINIMO_DIGITO[3]);
		break;
	}
	case OVEN_MED:
	{
		// coloca o valor no 7segmento = 0280
		Hal__WriteValtoSegment((char)0, (char)MEDIO_DIGITO[0]);
		Hal__WriteValtoSegment((char)1, (char)MEDIO_DIGITO[1]);
		Hal__WriteValtoSegment((char)2, (char)MEDIO_DIGITO[2]);
		Hal__WriteValtoSegment((char)3, (char)MEDIO_DIGITO[3]);
		break;
	}
	case OVEN_MAX:
	{
		// coloca o valor no 7segmento = 0320
		Hal__WriteValtoSegment((char)0, (char)MAXIMO_DIGITO[0]);
		Hal__WriteValtoSegment((char)1, (char)MAXIMO_DIGITO[1]);
		Hal__WriteValtoSegment((char)2, (char)MAXIMO_DIGITO[2]);
		Hal__WriteValtoSegment((char)3, (char)MAXIMO_DIGITO[3]);
		break;
	}
	
	default:
	{
		break;
	}
}

}