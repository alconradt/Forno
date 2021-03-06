/*
 * Display.c
 *
 *  Created on: 10/09/2017
 *      Author: MAASDN
 *      Modificado: Ana Watanabe    02/10/19
 */


//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\Forno\Header\C_Types.h>
#include <Z:\Forno\Header\Display.h>
#include <Z:\Forno\Header\Hal.h>
//#include "LcdMgr.h"
//#include "Timer.h"
//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------


//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------
#define NUM_OF_DIGITOS      4      // n�mero de segmentos do Display 7 segmentos
#define NUM_EVENTS     		50
#define ACENDE_LED          0
#define APAGA_LED           1


#define TRUE               1


//-------------------------------------- Global Variables ----------------------------------------------------------------

OVEN_DISPLAY_STATE_TYPE Oven_Display_State;      // vari�vel global  de display

KEY_EVENT_TYPE Display_Keys_Map;                  // vari�vel global  de keys

const char ZERADO_DIGITO[NUM_OF_DIGITOS] = {0xC0,0xC0,0xC0,0xC0};   //# 0000
const char MINIMO_DIGITO[NUM_OF_DIGITOS] = {0xC0,0xF9,0xA4,0xC0};   //# 0180
const char MEDIO_DIGITO[NUM_OF_DIGITOS] =  {0xC0,0xA4,0x92,0xC0};   //# 0250
const char MAXIMO_DIGITO[NUM_OF_DIGITOS] = {0xC0,0xB0,0xA4,0xC0};   //# 0320


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
	Oven_Display_State = OVEN_INIT;
	Display_Keys_Map = KEY_OFF_EVENT;
}

//---------------------------------------------------------------------------------------------------------------------
/**
 *  
 */
void Display__Handler(void)
{
ReadDisplayKeys();
	
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
  
/*unsigned char Display__GetUserKeyMap(void)
{
	return (Display_Keys_Map);
}*/
//---------------------------------------------------------------------------------------------------------------------
/**
 *  
 */


KEY_EVENT_TYPE Display__GetEvent(void)
{
	KEY_EVENT_TYPE event;
	ReadDisplayKeys();    // L� as chaves e coloca valor na vari�vel global Display_Keys_Map
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
/**
 *  
 */
void ReadDisplayKeys(void)
{
        unsigned char leitura;
        //Display_Keys_Map = KEY_NONE;
		
		leitura = Hal__ReadKey(KEY_0);
		if(leitura  == TRUE)
		     {
			Display_Keys_Map = KEY_MIN_EVENT;
			 }
		leitura = Hal__ReadKey(KEY_1);
		if(leitura == TRUE)
		    {
			Display_Keys_Map = KEY_MED_EVENT;
			}
		leitura = Hal__ReadKey(KEY_2);
		if(leitura == TRUE)
		    {
			Display_Keys_Map =  KEY_MAX_EVENT;
			}
		leitura = Hal__ReadKey(KEY_3);
		if(leitura == TRUE)
			{
			Display_Keys_Map =  KEY_OFF_EVENT; 
			}
}

/**
 *  Atualiza  7 Segmentos
 */
void UpdateDisplaySevenSeg(void)
{
	switch(Oven_Display_State)
	{
		const char *pt;
		char i;
		case OVEN_OFF:
		{
			pt = ZERADO_DIGITO;
			for(i=0;i<4;i++,pt++)
			{
				// coloca o valor no 7segmento = 0000
				Hal__WriteValtoSegment(i, *pt);
			}
			break;
		}
		case OVEN_INIT:
		case OVEN_TIMEOUT:
		break;
		case OVEN_MIN:
		{
			pt = MINIMO_DIGITO;
			for(i=0;i<4;i++,pt++)
			{
				// coloca o valor no 7segmento = 0080
				Hal__WriteValtoSegment(i, *pt);
			}
			break;
		}
		case OVEN_MED:
		{
			pt = MEDIO_DIGITO;
			for(i=0;i<4;i++,pt++)
			{
				// coloca o valor no 7segmento = 0280
				Hal__WriteValtoSegment(i, *pt);
			}
			break;
		}
		case OVEN_MAX:
		{
			pt = MAXIMO_DIGITO;
			for(i=0;i<4;i++,pt++)
			{
				// coloca o valor no 7segmento = 0320
				Hal__WriteValtoSegment(i, *pt);
			}
			break;
		}
		
		default:
		{
			break;
		}
	}
}

		

		
