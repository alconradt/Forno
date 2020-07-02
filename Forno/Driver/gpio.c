//-------------------------------------- Include Files ----------------------------------------------------------------
#include <avr/io.h> //definições do componente especificado
#include <util/delay.h> /*biblioteca para o uso das rotinas de
//_delay_ms() e _delay_us()*/

//Definições de macros - empregadas para o trabalho com os bits
#include <Z:\Forno\Forno\Header\gpio.h>
#include <Z:\Forno\Forno\Header\micro.h>
//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------
const unsigned char GPIO_PIN_SET_MASK[] = {0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};

const unsigned char GPIO_PIN_CLR_MASK[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};


volatile GPIO_DATA_TYPE *GPIO_DATA_LIST[NUM_OF_PORTS] = GPIO_DATA;   //está no Micro.h:  GPIO_DATA_TYPE  e #define GPIO_DATA {PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG};


//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================


/**
 * Configures a specific port pin
 */
void Gpio__PinConfig(GPIO_PORT port,unsigned char pin,GPIO_PIN_TYPE type)
{
	volatile GPIO_DATA_TYPE *pt_data;
	unsigned char set_bit_mask;
	unsigned char clr_bit_mask;
	
	set_bit_mask = GPIO_PIN_SET_MASK[pin];
	clr_bit_mask = GPIO_PIN_CLR_MASK[pin];
	
	
	switch(port)
	{
	case	PORT_B:
		pt_data = PORTB;   // Está no Micro.h: #define PORTA &GPIOA_DATA   => endereço 0x0000 00000
		break;
	case	PORT_C:
		pt_data = PORTC;
		break;
	case	PORT_D:
		pt_data = PORTD;
		break;
	default:
		break;
	}
	
if(type == OUTPUT_DIGITAL)    // setar 1 para saída
{
	//pt_data = GPIO_DATA_LIST[port];		 	
	pt_data->DIRECION_REG.byte |= set_bit_mask;	// Config Output
}

if(type == INPUT_DIGITAL_PULLUP)
{
	//pt_data = GPIO_DATA_LIST[port];		 	
	pt_data->DIRECION_REG.byte &= clr_bit_mask; 	// Config Input
	
	pt_data->DATA_OUT_PULL_REG.byte |= set_bit_mask;   // Config Input Pull up
}

}
	
/**
 * Writes a specific port pin
 */
void Gpio__PinWrite(GPIO_PORT port,unsigned char pin,unsigned char value)
{
	volatile GPIO_DATA_TYPE *pt_data;
	
	  if (value == 0)
        {
        	pt_data = GPIO_DATA_LIST[port];		 	
        	pt_data->DATA_OUT_PULL_REG.byte &= GPIO_PIN_CLR_MASK[pin];
        }
        else
        {
        	pt_data = GPIO_DATA_LIST[port];
        	pt_data->DATA_OUT_PULL_REG.byte |= GPIO_PIN_SET_MASK[pin];
        }
   

}

/**
 * Reads a specific port pin
 */
unsigned char Gpio__PinRead(GPIO_PORT port,unsigned char pin)
{
	volatile GPIO_DATA_TYPE *pt_data;
	unsigned char pin_state = ON;       // pin_state = 0x00  acionado  
	
		
	
    	pt_data = GPIO_DATA_LIST[port];
    	if (pt_data->DATA_IN_REG.byte & GPIO_PIN_SET_MASK[pin])     // if(leitura != 0)   ou if(leitura)
        {
    		pin_state = OFF;     // pin_state = 0x01   não acionado
        }
   
    return (pin_state);
    
}