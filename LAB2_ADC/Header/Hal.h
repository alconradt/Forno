/*
 * Hal.h
 *
 * Created: 11/04/2019 10:36:09
 *  Author: Ana Watanabe
 */ 


#ifndef HAL_H_
#define HAL_H_


//-------------------------------------- Include Files ----------------------------------------------------------------
 #include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Hal_prm.h>

//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------




typedef enum
{
	LED_0 = 0,
	LED_1,
	LED_2,
	LED_3,
	NUM_OF_LEDS
}LED_OUTPUT_TYPE;

typedef enum
{
	KEY_0 = 0,
	KEY_1,
	KEY_2,
	KEY_3,
	NUM_OF_KEYS
}KEY_INPUT_TYPE;



// define as entradas analógicas existentes POT_INT no canal 0 e POT_EXT no canal 5
typedef enum
{
	POT_INT = 0,
	ANALOG_INPUT_1,
	ANALOG_INPUT_2,
	ANALOG_INPUT_3,
	ANALOG_INPUT_4,
	POT_EXT,
	NUM_OF_ANALOG_INPUT,
	}ANALOG_INPUT_TYPE;

//=====================================================================================================================
//-------------------------------------- PUBLIC (Function Prototypes) -------------------------------------------------
//=====================================================================================================================
void Hal__Initialize(void);
void Hal__FastHandler(void);                // chamado por ALL_SLOTS_TASKS()  => IO
void Hal__BackgroundHandler(void);          // chamado por ALL_SLOTS_TASKS()  => ADC

void Hal__SetLed(LED_OUTPUT_TYPE output,unsigned char value);
void Hal__SetAllLeds(unsigned char value);
unsigned char Hal__ReadKey(KEY_INPUT_TYPE key);

// Escrever em Sete Segmentos
void Hal__WriteValtoSegment(char Segment, char *Value);

// Analog input read
unsigned short int Hal_GetAnalogInput(ANALOG_INPUT_TYPE input);


#endif /* HAL_H_ */



//unsigned char Hal__ReadKeyBuffer(void);
