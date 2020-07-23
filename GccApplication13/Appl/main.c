//-------------------------------------- Include Files ----------------------------------------------------------------
//#include "C_Types.h"
//#include <hidef.h> /* for EnableInterrupts macro */
//#include "derivative.h" /* include peripheral declarations */
#include <Z:\AAM_EXP1_parte4\GccApplication13\Header\main_prm.h>

//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------
typedef enum
{
	SLOT_1,
	SLOT_2,
	SLOT_3,
	SLOT_4,
	SLOT_5,
	NUM_OF_MAIN_SLOTS
}MAIN_SLOT_TYPE;

//**********************tem que VER e MUDAR!!!!!!!!!!!!!!
//#define DISABLE_WATCHDOG()	 SOPT1 &=(0x3F); //0b00111111  cleaning COPT0 and COPT1 bits of SOPT1 register
//#define RESET_WATCHDOG()    (void)(SRS = 0x55U, SRS = 0xAAU)

#define _1MS  	0x08
#define _4MS 	0x0A
#define _10MS 	0x0B
//-------------------------------------- Global Variables ----------------------------------------------------------------

MAIN_SLOT_TYPE Slot;


//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================

void main(void)
{
	//#if (WATCHDOG_ENABLE == DISABLED)
	//DISABLE_WATCHDOG();
	//#endif //WATCHDOG_ENABLE
	//EnableInterrupts;
	Slot = SLOT_1;

	
	
	
	//#if (USE_FIXED_TIME_SLOT == ENABLED)
	//RTCMOD = 0x00;
	//RTCSC = 0x00;
	//RTCSC_RTCLKS = 0x00;
	//RTCSC_RTCPS = SLOT_TIME;
	//#endif //USE_FIXED_TIME_SLOT
	
	// Functions Initialization
	INITIALIZE_TASKS();
	
	
	//Main Loop
	for(;;)
	{
		//#if (WATCHDOG_ENABLE == ENABLED)
		//RESET_WATCHDOG();	/* feeds the watch dog */
		//#endif //WATCHDOG_ENABLE
		
		//ALL_SLOTS_TASKS();
		switch(Slot)
		{
			case SLOT_1:
			SLOT_1_TASKS();
			break;

			case SLOT_2:
			SLOT_2_TASKS();
			break;

			case SLOT_3:
			SLOT_3_TASKS();
			break;

			case SLOT_4:
			SLOT_4_TASKS();
			break;

			case SLOT_5:
			SLOT_5_TASKS();
			break;

			default:
			Slot = SLOT_1;
			break;

		}
// ******************* retirado
//		#if (USE_FIXED_TIME_SLOT == ENABLED)
//		while(RTCSC_RTIF == 0)	// Wait time to sync
//		{
			//Resets watchdog while waiting to sync
//			RESET_WATCHDOG();
//		}
		
		// Re-start the RTC timer
	//	RTCSC = RTCSC | 0x80;
	//	#endif //USE_FIXED)TIME_SLOT
		
		Slot++;
		if(Slot >= NUM_OF_MAIN_SLOTS)
		{
			Slot = SLOT_1;
		}

	}

}







/*
 * GccApplication10.c
 *
 * Created: 23/04/2019 09:49:15
 * Author : Ana Watanabe
 */ 

// #include <avr/io.h>
// #include <C:\Users\Ana Watanabe\Documents\Atmel Studio\7.0\GccApplication10\GccApplication10\Header\Gpio.h>





/* Write a value to one of the 4 digits of the display 
void WriteValueToSegment(char Segment, char Value)
{
	bitClear(PORTD, 4);

	for (uint8_t i = 0; i < 8; i++)  {
		bitWrite(PORTB, 0, !!(Value & (1 << (7 - i))));
		bitSet(PORTD, 7);
		bitClear(PORTD, 7);
	}

	for (uint8_t i = 0; i < 8; i++)  {
		bitWrite(PORTB, 0, !!(SEGMENT_SELECT[Segment] & (1 << (7 - i))));
		bitSet(PORTD, 7);
		bitClear(PORTD, 7);
	}

	bitSet(PORTD, 4);
}
*/


/*

int main(void)
{
	char i, valor;
	valor = 0x90;
	
	bitWrite(DDRD, 4, OUTPUT_DIGITAL);
	bitWrite(DDRD, 7, OUTPUT_DIGITAL);
	bitWrite(DDRB, 0, OUTPUT_DIGITAL);
	*/
    /* Replace with your application code */
   /* while (1) 
	{
	for(i=0; i<4; i++)
	      WriteValueToSegment(i,valor);
    }
}
*/

