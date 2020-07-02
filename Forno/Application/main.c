#define F_CPU 16000000UL /*define a frequência do microcontrolador 16MHz(necessário para usar as rotinas de atraso)*/
#include <avr/io.h> //definições do componente especificado
#include <util/delay.h> /*biblioteca para o uso das rotinas de timer */

#include <Z:\Forno\Forno\Header\gpio.h>
#include <Z:\Forno\Forno\Header\micro.h>

#define ACESO   0
#define APAGADO 1
int main( )
{
	//Configuração Saída Digital
	Gpio__PinConfig(PORT_B,LED2,OUTPUT_DIGITAL);
	
	//Configuração Entrada Digital
	Gpio__PinConfig(PORT_C, SW1, INPUT_DIGITAL_PULLUP);
	
	//Variável SW1
	int Button; 	

	while(1) 
	{
		Button = Gpio__PinRead(PORT_C,SW1);
		
		if(Button == ON)	
		{	
			Gpio__PinWrite(PORT_B,LED2,ACESO);
			_delay_ms(1000);
			Gpio__PinWrite(PORT_B,LED2,APAGADO);
			_delay_ms(1000);
		}
	}
}
