/*
 * SevenSeg.c
 *
 * Created: 13/05/2019 14:04:34
 *  Author: Ana Watanabe
 */ 
#include <avr/io.h> ]

#include <Z:\Forno\Header\Micro.h>
#include <Z:\Forno\Header\SevenSeg.h>
#include <Z:\Forno\Header\Gpio.h>

/* Segment byte maps for numbers 0 to 9 */
const char SEGMENT_MAP_DIGIT[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};

/* Byte maps to select digit 1 to 4 */
const char SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};


/* Write a value to one of the 4 digits of the display */
void SevenSeg_WriteValueToSegment(char Segment, char Value)
{
	bitClear(PORTD, LATCH_PIN);

	for (uint8_t i = 0; i < 8; i++)  {
		bitWrite(PORTB, 0, ((Value) & (1 << (7 - i))));
		bitSet(PORTD, CLK_PIN);
		bitClear(PORTD, CLK_PIN);
	}

	for (uint8_t i = 0; i < 8; i++)  {
		bitWrite(PORTB, 0, (SEGMENT_SELECT[Segment] & (1 << (7 - i))));
		bitSet(PORTD, CLK_PIN);
		bitClear(PORTD, CLK_PIN);
	}

	bitSet(PORTD, LATCH_PIN);
}



