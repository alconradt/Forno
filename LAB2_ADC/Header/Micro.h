/*
 * Micro.h
 *
 * Created: 27/03/2019 18:12:30
 *  Author: Ana Watanabe
 */ 

#ifndef MICRO_H_
#define MICRO_H_


// #include <hidef.h> 
//#include <avr/io.h> 
//***********************************************************************************************************
// ************************************  MACROS *************************************************************
//***********************************************************************************************************
#define DISABLE_INTERRUPT() __asm SEI;
#define ENABLE_INTERRUPT()  __asm CLI;


//***********************************************************************************************************
// ************************************  Enums, Structs *****************************************************
//***********************************************************************************************************
//union Low Byte bit definitions Bits 0 - 7
typedef union
{
    unsigned char byte;
    struct
    {
        unsigned char bit0 :1;
        unsigned char bit1 :1;
        unsigned char bit2 :1;
        unsigned char bit3 :1;
        unsigned char bit4 :1;
        unsigned char bit5 :1;
        unsigned char bit6 :1;
        unsigned char bit7 :1;
    } bit;
} DEF_LOWBYTE;

//union High Byte bit definitions Bits 8 - 15
typedef union
{
    unsigned char byte;
    struct
    {
    	unsigned char bit8 :1;
    	unsigned char bit9 :1;
    	unsigned char bit10 :1;
    	unsigned char bit11 :1;
    	unsigned char bit12 :1;
    	unsigned char bit13 :1;
    	unsigned char bit14 :1;
    	unsigned char bit15 :1;
    } bit;
} DEF_HIBYTE;

//***********************************************************************************************************
// ***************************  GPIO Ports Registers ********************************************************
//***********************************************************************************************************

// Port Data and Direction Registers
typedef struct
{
    volatile DEF_LOWBYTE DATA_IN_REG;
    volatile DEF_LOWBYTE DIRECION_REG;
	volatile DEF_LOWBYTE DATA_OUT_PULL_REG;
} GPIO_DATA_TYPE;

// Port Data and Direction Registers Address
#define GPIOB_DATA  (*((volatile GPIO_DATA_TYPE *)0x00000023))    //Port B Data Register
#define GPIOC_DATA  (*((volatile GPIO_DATA_TYPE *)0x00000026))    //Port C Data Register
#define GPIOD_DATA  (*((volatile GPIO_DATA_TYPE *)0x00000029))    //Port D Data Register




#define PORTB_MICRO  &GPIOB_DATA
#define PORTC_MICRO  &GPIOC_DATA
#define PORTD_MICRO  &GPIOD_DATA




#define GPIO_DATA {PORTB_MICRO, PORTC_MICRO, PORTD_MICRO};

//***********************************************************************************************************
// **********************************  ADC Registers ********************************************************
//***********************************************************************************************************


// ADC Registers
typedef struct
{
    volatile DEF_LOWBYTE  ADCL_REG;  /*** ADCL  - Data Result Low  Register;    0x00000078 ***/
    volatile DEF_HIBYTE   ADCH_REG;  /*** ADCH  - Data Result High Register;    0x00000079 ***/
    volatile DEF_LOWBYTE ADCSRA_REG;                /*** ADCSRA - ADC Control and Status  Register A;  0x0000007A ***/
    volatile DEF_LOWBYTE ADCSRB_REG;                  /*** ADCSRB - ADC Control and Status  Register B;    0x0000007B ***/
    volatile DEF_LOWBYTE ADMUX_REG;						/*** ADMUX - ADC Multiplexer election Register;        0x0000007C ***/
    volatile DEF_LOWBYTE LIXO;                          /*** espaço deixado pelo fabricante    ***/
	volatile DEF_LOWBYTE DIDR0_REG;						 /*** DIDR0 - Digital Input Disable Register;        0x0000007E ***/
    volatile DEF_LOWBYTE DIDR1_REG;						/*** DIDR1 - Digital Input Disable Register;        0x0000007F ***/
} ADC_REG_TYPE;	
   // RETIRAR para a versão do aluno **************//
// Port Data and Direction Registers Address
#define ADC_ADCL  (*((volatile ADC_REG_TYPE *)0x00000078))	/*** ADCL  - Data Result Low  Register;    0x00000078 ***/
#define ADC_ADCH  (*((volatile ADC_REG_TYPE *)0x00000079))   /*** ADCH  - Data Result High Register;    0x00000079 ***/
#define ADC_ADCSRA   (*((volatile ADC_REG_TYPE *)0x0000007A))    /*** ADCRH  - Data Result High Register;     0x00000012 ***/
#define ADC_ADCSRB   (*((volatile ADC_REG_TYPE *)0x0000007B))    /*** ADCRL  - Data Result Low Register;      0x00000013 ***/
#define ADC_ADMUX  (*((volatile ADC_REG_TYPE *)0x0000007C))    /*** ADCCVH - Compare Value High Register;   0x00000014 ***/
#define ADC_DIDR0  (*((volatile ADC_REG_TYPE *)0x0000007E))    /*** ADCCVL - Compare Value Low Register;    0x00000015 ***/
#define ADC_DIDR1  (*((volatile ADC_REG_TYPE *)0x0000007F))    /*** ADCCFG - Configuration Register;        0x00000016 ***/

#define ADC_REGISTERS  &ADC_ADCL	
	
	
	

#endif /* MICRO_H_ */