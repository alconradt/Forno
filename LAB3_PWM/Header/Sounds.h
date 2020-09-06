/*
 * Sounds.h
 *
 * Created: 05/11/2019 22:49:44
 *  Author: Ana Watanabe
 */ 


#ifndef Sounds_H_
#define Sounds_H_

//typedef enum {
//	SOUND_POWER_ON = 0,
//	SOUND_KEY_PRESS,
//	SOUND_END_CYCLE,
//	NUM_OF_SOUNDS,
//	PLAY_NO_SOUND = 0XFF  // N�O RETIRE ESTA LINHA
//} SOUNDS_TYPE;


typedef enum {
	SOUND_POWER_ON = 0,
	SOUND_KEY_PRESS,
	SOUND_END_CYCLE,
	PLAY_NO_SOUND,   // N�O RETIRE ESTA LINHA
	NUM_OF_SOUNDS,
} SOUNDS_TYPE;

//Prot�tipos
void Sounds__Initialize(void);
void Sounds__Background(void);
void Sounds__PlaySounds( SOUNDS_TYPE sound_id);


#endif /* Sounds_H_ */