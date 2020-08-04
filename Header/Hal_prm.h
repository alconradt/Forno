/*
 * Hal_prm.h
 *
 *  Created on: 04/09/2017
 *      Author: MAASDN
 */

#ifndef HAL_PRM_H_
#define HAL_PRM_H_

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\Forno\Header\C_Types.h>


//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------

//-------------------------------------------------------------------------------------------
// --------------------------------- ON BOARD LEDs CONFIGURATION ----------------------------
//-------------------------------------------------------------------------------------------
//On board LEDs configuration
// Select ENABLED for LEDs that will be used otherwise DISABLED

#define USE_LED_0		ENABLED
#define USE_LED_1		ENABLED
#define USE_LED_2		ENABLED
#define USE_LED_3		ENABLED


//-------------------------------------------------------------------------------------------
// ---------------------------------  KEYS CONFIGURATION ----------------------------------
//-------------------------------------------------------------------------------------------
//On board Keys configuration
// Select ENABLED for Keys that will be used otherwise DISABLED
#define USE_KEY_0		ENABLED	
#define USE_KEY_1		ENABLED	
#define USE_KEY_2		ENABLED	
#define USE_KEY_3		ENABLED

//-------------------------------------------------------------------------------------------
// ---------------------------------  AD CONFIGURATION ------------------------------------
//-------------------------------------------------------------------------------------------

//#define HAL_ANALOG_MODE	    	MODE_10BITS//MODE_8BITS //MODE_10BITS //MODE_12BITS
//#define HAL_CONVERSION_METHOD	AD_CONTINUOUS_CONVERSION//AD_SINGLE_CONVERSION //AD_CONTINUOUS_CONVERSION


//On board Analog configuration
// Select ENABLED for analog that will be used otherwise DISABLED
//PTB2 AD CH2 (Analog 0 - Pot)
//PTD1 AD CH9 (Analog 1 - Pot)
//PTD8 AD CH 8 (Accel axis X)
//PTB0 AD CH 0 (Accel axis Y)
//PTB1 AD CH 1 (Accel axis Z)
//#define USE_POT_INPUT_0		ENABLED	
//#define USE_POT_INPUT_1		ENABLED
//#define USE_ACCEL_AXIS_X	ENABLED
//#define USE_ACCEL_AXIS_Y	ENABLED
//#define USE_ACCEL_AXIS_Z	ENABLED


//Use table below to link each analog input configured as enabled with its respective AD channel (AD_CHx) as per 
// enumeration defined in ADC.h
//#define HAL_ANALOG_CHANNEL_CONFIG \
	{\
		 AD_CH2, 	/*POT_INPUT_0*/\
		 AD_CH9,  	/*POT_INPUT_1*/\
		 AD_CH8,  	/*ACCEL_AXIS_X*/\
		 AD_CH0,  	/*ACCEL_AXIS_Y*/\
		 AD_CH1  	/*ACCEL_AXIS_Z*/\
    }	

//-------------------------------------------------------------------------------------------
// --------------------------------- BUZZER CONFIGURATION ------------------------------------
//-------------------------------------------------------------------------------------------

//#define USE_BUZZER				ENABLED  //	DISABLED		 
//#define BUZZER_DEFAULT_ON_DUTY	50 //50%	
//#define BUZZER_DEFAULT_FREQ		4000 //Hz
//=====================================================================================================================
//-------------------------------------- PUBLIC (Function Prototypes) -------------------------------------------------
//=====================================================================================================================

#endif /* HAL_PRM_H_ */
