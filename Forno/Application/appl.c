/*
 * Appl.c
 *
 * Created: 02/04/2019 21:29:10
 *  Author: Ana Watanabe
 */ 

//-------------------------------------- Include Files ----------------------------------------------------------------
//#include "C_Types.h"    ainda não...
#include <avr/io.h> //definições do componente especificado
#include <util/delay.h> /*biblioteca para o uso das rotinas de
//_delay_ms() e _delay_us()*/
#include <Z:\Forno\Forno\Header\appl.h>
#include <Z:\Forno\Forno\Header\gpio.h>
//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------


//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------
#define ACESO       0
#define APAGADO     1
//-------------------------------------- Global Variables ----------------------------------------------------------------

unsigned char Timer_Counter;
unsigned char Toggle;
unsigned char Trigger;
unsigned char SW1_Button, SW2_Button, SW3_Button;
//-------------------------------------- PRIVATE (Function Prototypes) ---------------------------------------------------


//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================


void Appl__Initialize(void)
{
	Gpio_PinConfig(); // Configuração das entradas e saídas digitais 
}


void Appl__Handler(void)
{	
	// Leitura dos botoes 
	SW1_Button = Gpio__PinRead(PORT_C, SW1);
	SW2_Button = Gpio__PinRead(PORT_C, SW2);
	SW3_Button = Gpio__PinRead(PORT_C, SW3);
	
	if(SW1_Button == ON && SW3_Button == ON)
	{
		// Se SW1 e SW3 foram clicadas ao mesmo tempo entra nesa condicao
		Gpio__PinWrite(PORT_B, LED1, APAGADO);
		Gpio__PinWrite(PORT_B, LED2, APAGADO);
		Gpio__PinWrite(PORT_B, LED3, APAGADO);
		Gpio__PinWrite(PORT_B, LED4, APAGADO);
		_delay_ms(3000); // Este delay serve para resolver o problema de mal contato dos push buttons 
	}
	else
	{
		if(SW1_Button == ON)
		{
			Gpio__PinWrite(PORT_B, LED1, ACESO);
			Gpio__PinWrite(PORT_B, LED2, APAGADO);
			Gpio__PinWrite(PORT_B, LED3, APAGADO);
			Gpio__PinWrite(PORT_B, LED4, APAGADO);
		}
		
		if(SW2_Button == ON)
		{
			Gpio__PinWrite(PORT_B, LED1, ACESO);
			Gpio__PinWrite(PORT_B, LED2, ACESO);
			Gpio__PinWrite(PORT_B, LED3, APAGADO);
			Gpio__PinWrite(PORT_B, LED4, APAGADO);
		}
		
		if(SW3_Button == ON)
		{
			Gpio__PinWrite(PORT_B, LED1, ACESO);
			Gpio__PinWrite(PORT_B, LED2, ACESO);
			Gpio__PinWrite(PORT_B, LED3, ACESO);
			Gpio__PinWrite(PORT_B, LED4, APAGADO);
		}	
	}
}

void Gpio_PinConfig(void)
{
	// Configurando as saídas digitais 
	Gpio__PinConfig(PORT_B, LED1, OUTPUT_DIGITAL);
	Gpio__PinConfig(PORT_B, LED2, OUTPUT_DIGITAL);
	Gpio__PinConfig(PORT_B, LED3, OUTPUT_DIGITAL);
	Gpio__PinConfig(PORT_B, LED4, OUTPUT_DIGITAL);
	
	// Configurando as entradas digitais
	Gpio__PinConfig(PORT_C, SW1, INPUT_DIGITAL_PULLUP);
	Gpio__PinConfig(PORT_C, SW2, INPUT_DIGITAL_PULLUP);
	Gpio__PinConfig(PORT_C, SW3, INPUT_DIGITAL_PULLUP); 
	
	// Tornando todos os LEDs apagados 
	Gpio__PinWrite(PORT_B, LED1, APAGADO);
	Gpio__PinWrite(PORT_B, LED2, APAGADO);
	Gpio__PinWrite(PORT_B, LED3, APAGADO);
	Gpio__PinWrite(PORT_B, LED4, APAGADO);
}