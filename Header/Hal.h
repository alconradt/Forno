/*
 * Hal.h
 *
 * Created: 11/04/2019 10:36:09
 *  Author: Ana Watanabe
 */ 


#ifndef HAL_H_
#define HAL_H_


//-------------------------------------- Include Files ----------------------------------------------------------------
 #include <Z:\Forno\Header\Hal_prm.h>

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

//=====================================================================================================================
//-------------------------------------- PUBLIC (Function Prototypes) -------------------------------------------------
//=====================================================================================================================
void Hal__Initialize(void);
void Hal__BackgroundHandler(void);
void Hal__FastHandler(void);

void Hal__SetLed(LED_OUTPUT_TYPE output,unsigned char value);
void Hal__SetAllLeds(unsigned char value);
unsigned char Hal__ReadKey(KEY_INPUT_TYPE key);

void Hal__WriteValtoSegment(char Segment, char Value);


#endif /* HAL_H_ */



//unsigned char Hal__ReadKeyBuffer(void);
