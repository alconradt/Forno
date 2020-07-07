/*
 * Hal.h
 *
 * Created: 11/04/2019 10:36:09
 *  Author: Ana Watanabe
 */ 


#ifndef HAL_H_
#define HAL_H_


//-------------------------------------- Include Files ----------------------------------------------------------------
// #include <C:\Users\Ana Watanabe\Documents\Atmel Studio\7.0\GccApplication8\GccApplication8\Header\Hal_prm.h>

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
	NUM_OF_KEYS
}KEY_INPUT_TYPE;

typedef struct  
{
unsigned char key[3];	
}KEYS_READ;

//=====================================================================================================================
//-------------------------------------- PUBLIC (Function Prototypes) -------------------------------------------------
//=====================================================================================================================
void Hal__Initialize(void);
void Hal__SetLed(LED_OUTPUT_TYPE output,unsigned char value);
void Hal__SetAllLeds(unsigned char value);
unsigned char Hal__ReadKey(KEY_INPUT_TYPE key);
KEYS_READ* Hal__ReadAllKey(void);             // alunos escreverem!!


#endif /* HAL_H_ */








