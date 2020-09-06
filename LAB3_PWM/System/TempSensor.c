/*
 * TempSensor.c
 *
 *  Created on: 03/10/2017
 *      Author: MAASDN
 */

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <Z:\AAM_EXP3\LAB3_PWM\Header\C_Types.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\TempSensor.h>
#include <Z:\AAM_EXP3\LAB3_PWM\Header\Hal.h>
//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------

unsigned short int Temperature[NUM_OF_TEMP_SENSOR];

const unsigned char TempSensorTable[NUM_OF_TEMP_SENSOR] = TEMP_SENSOR_CONFIG;
const unsigned char TempSensor_Enable_Table[NUM_OF_TEMP_SENSOR]= {USE_TEMP_SENSOR_1, USE_TEMP_SENSOR_2};
//-------------------------------------- Defines, Enumerations ----------------------------------------------------------------


//-------------------------------------- Global Variables ----------------------------------------------------------------


//-------------------------------------- PRIVATE (Function Prototypes) ---------------------------------------------------



//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================

void TempSensor__Initialize(void)
{
	TEMP_SENSOR_TYPE sensor_id;

	for (sensor_id = 0; sensor_id < NUM_OF_TEMP_SENSOR; sensor_id++) 
	{
		Temperature[sensor_id] = 0;

	}
}
//
//  Esta fun��o faz a convers�o dos valores lidos nos sensores escolhidos
//  e s�o armazenados em Temperature[].
 
//---------------------------------------------------------------------------------------------------------------------
void TempSensor__ConversionHandler(void)
{
	unsigned short int ad_value;  // usar essa vari�vel para fazer os c�lculos!
	TEMP_SENSOR_TYPE sensor_id;   // identificador do sensor
	
	for (sensor_id = 0; sensor_id < NUM_OF_TEMP_SENSOR; sensor_id++) 
	{
		if(TempSensor_Enable_Table[sensor_id] == ENABLED)
		{
			// Fazer a leitura, realizar a convers�o (T(�C) = ( (ValorAD + 400)/4 ) + 50)
			// e armazenar em Temperature[]. 
			ad_value = Hal__GetAnalogInput(TempSensorTable[sensor_id]);
			ad_value = (ad_value + 400);
			ad_value = (ad_value/4) + 50;
			Temperature[sensor_id] = ad_value;
		}
		
	}
	
}
//---------------------------------------------------------------------------------------------------------------------
unsigned short int TempSensor__GetCelsius(TEMP_SENSOR_TYPE sensor_id)
{
	if (sensor_id < NUM_OF_TEMP_SENSOR)
	{
		return Temperature[sensor_id];
	}
	else
	{
		return 0;
	}
	
}
//---------------------------------------------------------------------------------------------------------------------
