/*
 * Appl.c
 *
 * Created: 02/04/2019 21:29:10
 *  Author: Ana Watanabe
 */ 

//-------------------------------------- Include Files ----------------------------------------------------------------
//#include "C_Types.h"    ainda não...
#include <avr/io.h> //definições do componente especificado
#include <util/delay.h> /*biblioteca para o uso das rotinas de _delay_ms() e _delay_us()*/
#include <Z:\Forno\Forno\Header\appl.h>
#include <Z:\Forno\Forno\Header\gpio.h>
#include <Z:\Forno\Forno\Header\hal.h>
//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------


//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------
#define ACESO       0
#define APAGADO     1
//-------------------------------------- Global Variables ----------------------------------------------------------------

unsigned char Timer_Counter;
unsigned char Toggle;
unsigned char Trigger;
KEYS_READ tab;

//-------------------------------------- PRIVATE (Function Prototypes) ---------------------------------------------------


//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================


void Appl__Initialize(void)
{
Hal__Initialize();
Hal__SetAllLeds(APAGADO);
}


//****************************************************
// PODE-SE FAZER ESTE TESTE DE DUAS FORMAS: LER CADA BOTÃO OU LER TODOS DE UMA VEZ!!!


//1) LER UMA DE CADA VEZ
void Appl__Handler(void)
{
KEY_INPUT_TYPE index;
for (index = 0; index < NUM_OF_KEYS; index++)
{
	tab.key[index] = Hal__ReadAllKey();
}

if (tab.key[0]== ON && tab.key[2]== ON)
  {
  Hal__SetAllLeds(APAGADO);
  _delay_ms(1000); 
  }
else
  {
  if(tab.key[0] == ON)    //reads key 1 (at SW1)
	{
	Hal__SetLed(LED_0,ACESO);
	Hal__SetLed(LED_1,APAGADO);
	Hal__SetLed(LED_2,APAGADO);	  
	}
 if(tab.key[1] == ON)           //reads key 2 (at SW2)
	{
    Hal__SetLed(LED_0,ACESO);	 
    Hal__SetLed(LED_1,ACESO);
    Hal__SetLed(LED_2,APAGADO);		 
    }
if(tab.key[2] == ON)   //reads key 3 (at SW3)
	{
	Hal__SetLed(LED_0,ACESO);
	Hal__SetLed(LED_1,ACESO);  
	Hal__SetLed(LED_2,ACESO);	  
	}
 }
}

// LER TODOS DE UMA VEZ....tarefa para entregar

	
	