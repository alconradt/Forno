/*
 * Hal.c
 *
 * Created: 11/04/2019 10:11:08
 *  Author: Ana Watanabe
 */ 

//-------------------------------------- Include Files ----------------------------------------------------------------
//#include "C_Types.h"
#include <avr/io.h>
#include <Z:\Forno\Header\Gpio.h>
//#include "ADC.h"
//#include "PWM.h"
#include <Z:\Forno\Header\Hal.h>
#include <Z:\Forno\Header\SevenSeg.h>
//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------

const unsigned char Leds_Enable_Table[NUM_OF_LEDS]= {USE_LED_0, USE_LED_1, USE_LED_2, USE_LED_3};
const unsigned char Keys_Enable_Table[NUM_OF_KEYS]= {USE_KEY_0, USE_KEY_1, USE_KEY_2, USE_KEY_3};

//const unsigned char AD_Enable_Table[NUM_OF_ANALOG_INPUT]= {USE_POT_INPUT_0, USE_POT_INPUT_1, USE_ACCEL_AXIS_X, USE_ACCEL_AXIS_Y, USE_ACCEL_AXIS_Z};
//const unsigned char AD_Channel_Table[NUM_OF_ANALOG_INPUT] = HAL_ANALOG_CHANNEL_CONFIG;
//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------
#define LED_ON 			FALSE //LEDs use Inverse logic
#define LED_OFF 		TRUE  //LEDs use Inverse logic
#define KEY_PRESSED 	FALSE //Value read in the pin when key is pressed

#define  ON             1
#define  OFF            0

#define  TRUE           1
#define  FALSE          0
#define  ENABLED        1

#define ACENDE_LED      0

typedef struct
{
	GPIO_PORT port;
    unsigned char pin;
}HAL_GPIO_TYPE;

HAL_GPIO_TYPE LED_GPIO[NUM_OF_LEDS] =
{
  {PORT_B,LED1},    //! LED1
  {PORT_B,LED2},    //! LED2
  {PORT_B,LED3},    //! LED3
  {PORT_B,LED4},    //! LED4
};


HAL_GPIO_TYPE KEYS_GPIO[NUM_OF_KEYS] =
{
  {PORT_C,SW1},    //!SW1
  {PORT_C,SW2},    //!SW2
  {PORT_C,SW3},    //!SW3
  {PORT_C,SW4},    //!SW4 acrescido externamente 20/05/19  Ana
 };


//-------------------------------------- Global Variables ----------------------------------------------------------------

unsigned char Hal_Leds_Buffer[NUM_OF_LEDS];   // não chama mais direto no Gpio, mas escreve nesta variável
unsigned char Hal_Keys_Buffer;                // testa esta variável global


//-------------------------------------- PRIVATE (Function Prototypes) ---------------------------------------------------
void LEDsUpdate(void);
void KeysRead(void);



//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================

/*
 * Call this function on initialize tasks before use any function of this module
 * This function will properly configure all pins before use it
 */
void Hal__Initialize(void)
{
	LED_OUTPUT_TYPE led_index;
	KEY_INPUT_TYPE key_index;
	//ANALOG_INPUT_TYPE analog_index;
	
	
	// LEDs Configuration
	for(led_index = 0; led_index < NUM_OF_LEDS; led_index++)
	{
	Gpio__PinConfig(LED_GPIO[led_index].port, LED_GPIO[led_index].pin, OUTPUT_DIGITAL);
	}
	
	
	// Keys Configuration
	for(key_index = 0; key_index < NUM_OF_KEYS; key_index++)
	{
	Gpio__PinConfig(KEYS_GPIO[key_index].port, KEYS_GPIO[key_index].pin, INPUT_DIGITAL_PULLUP);
	}
	
	// Apaga todos os leds
	Hal__SetAllLeds(ON);   //apaga todos leds
	
	
	// Configuração do 7 segmentos
	
	bitWrite(DDRD, 4, OUTPUT_DIGITAL);
	bitWrite(DDRD, 7, OUTPUT_DIGITAL);
	bitWrite(DDRB, 0, OUTPUT_DIGITAL);
	
	
	//Gpio__PinConfig(PORTD, 4, OUTPUT_DIGITAL);
	//Gpio__PinConfig(PORTD, 7, OUTPUT_DIGITAL);
	//Gpio__PinConfig(PORTB, 0, OUTPUT_DIGITAL);
	}


//---------------------------------------------------------------------------------------------------------------------
/**
 *  This function shall run in background in the main loop 
 *  Call rate: 1ms, 5ms, 10ms, ...
 */
void Hal__FastHandler(void)
{
	LEDsUpdate();   // update the LEDs status
	KeysRead();     // reads the keys and update the Hal_Keys_Buffer
	
}




//---------------------------------------------------------------------------------------------------------------------
/**
 *  Use this function to turn a specific led ON or OFF
 *  output: Respective LED
 *  value: ON/OFF
 */
void Hal__SetLed(LED_OUTPUT_TYPE output,unsigned char value)
{
	Hal_Leds_Buffer[output] = LED_OFF;
	if (value == ACENDE_LED)
	   Hal_Leds_Buffer[output] = LED_ON;
}

//---------------------------------------------------------------------------------------------------------------------
/**
 *  Use this function to turn all LEDs ON or OFF
 *  value ON/OFF
 *  ON: To turn All LEDs ON 
 *  OFF: To turn All LEDs OFF
 */
void Hal__SetAllLeds(unsigned char value)
{
	LED_OUTPUT_TYPE index;

	for(index = 0; index < NUM_OF_LEDS; index++)
		{
		Hal_Leds_Buffer[index] = LED_OFF;
		if (value == ACENDE_LED)
			Hal_Leds_Buffer[index] = LED_ON;
		}
}

//---------------------------------------------------------------------------------------------------------------------
/**
 *  Use this function to read the status of a specific key
 *  key: desired key to be read
 *  return: TRUE if key is pressed otherwise FALSE
 */
unsigned char Hal__ReadKey(KEY_INPUT_TYPE key)
{
	if (key < NUM_OF_KEYS)
	   {
	   if (BIT_TEST(Hal_Keys_Buffer, key) > 0)
	      return (TRUE);
	   }
	 return (FALSE);
}

//---------------------------------------------------------------------------------------------------------------------
/**
 *  Use this function to write a Val in the segment 
 *  
 */
void Hal__WriteValtoSegment(char Segment, char *Value)
{

SevenSeg_WriteValueToSegment(Segment, Value);
}



//=====================================================================================================================
//-------------------------------------- PRIVATE Functions -------------------------------------------------------------
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/**
 *  This local function update the LEDs status
 */
void LEDsUpdate(void)
{
	unsigned char index;
	unsigned char value;
	
	//LEDs Update
	for(index = 0; index < NUM_OF_LEDS; index++)
	   {
		if(Leds_Enable_Table[index] == ENABLED) // Update GPIO only if current LED is configured to be used
		    {
			value = LED_ON;
			if(Hal_Leds_Buffer[index] > 0)
			   {  
				value = LED_OFF;
			   }
			Gpio__PinWrite(LED_GPIO[index].port, LED_GPIO[index].pin, value);
		    }
	   }
}
//---------------------------------------------------------------------------------------------------------------------
/**
 *  This local function reads the keys input and update the Hal_Keys_Buffer
 */

void KeysRead(void)
{
	//Keys read
	KEY_INPUT_TYPE key_index;
	unsigned char value;
	
	for(key_index = KEY_0; key_index < NUM_OF_KEYS; key_index++)
	{
		if(Keys_Enable_Table[key_index] == ENABLED)
		{
			value = Gpio__PinRead(KEYS_GPIO[key_index].port, KEYS_GPIO[key_index].pin);
			if(value == KEY_PRESSED)
			{
				BIT_SET(Hal_Keys_Buffer,key_index);
			}
			else
			{
				BIT_CLR(Hal_Keys_Buffer,key_index);

			}
		}
	}

}
