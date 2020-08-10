/*
 * main_prm.h
 *
 *  Created on: 04/09/2017
 *      Author: MAASDN
 */

#ifndef MAIN_PRM_H_
#define MAIN_PRM_H_
//-------------------------------------- Include Files ----------------------------------------------------------------
//#include "C_Types.h"
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Appl.h>
//#include <:\Users\Ana Watanabe\Documents\Atmel Studio\7.0\AAM_EXP2\LAB2_ADC\Header\Gpio.h>


//#include "ADC.h"
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Hal.h>
#include <D:\Materias_UDESC\AAM\AAM_EXP2_parte1\AAM_EXP2\LAB2_ADC\Header\Display.h>

//#include "TempSensor.h"
//#include "OvenTempControl.h"
//#include "Sounds.h"
//#include "Timer.h"
//#include "PWM.h"
//#include "LcdMgr.h"
//-------------------------------------- Defines ----------------------------------------------------------------

// Select ENALBED to use a fixed slot time duration for each main slot, otherwise select DISABLED
// If ENALBED, need to define the slot time duration in SLOT_TIME parameters below
#define USE_FIXED_TIME_SLOT	ENABLED //ENABLED//

// Define the fixed time slot duration
// Each slot in main loop will take SLOT_TIME before switch to next slot 
// Use _1MS for 1ms, _5MS for 5ms or _10MS for 10ms 
#define SLOT_TIME	 _1MS	//_1MS  // _4MS  // _10MS  

// ENALBED or DISABLED the Watchdog
#define WATCHDOG_ENABLE  	 ENABLED// //DISABLED


#define INITIALIZE_TASKS()\
{\
	Hal__Initialize();\
	Display__Initialize();\
	Appl__Initialize();\
	ADC__Initialize();\
	}

#define ALL_SLOTS_TASKS()\
{\
	Hal__FastHandler();\
	Hal__BackgroundHandler();\
}

#define SLOT_1_TASKS()\
{\
}

#define SLOT_2_TASKS()\
{\
	Appl__Handler();\
	Display__Handler();\
}
	
#define SLOT_3_TASKS()\
{\
	ADC__Handler();\
}
	
#define SLOT_4_TASKS()\
{\
}
	
#define SLOT_5_TASKS()\
{\
}




	



#endif /* MAIN_PRM_H_ */
