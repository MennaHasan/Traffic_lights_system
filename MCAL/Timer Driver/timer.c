/*
 * timer.c
 *
 * Created: 9/24/2022 4:01:32 PM
 *  Author: Dell
 */ 

#include "timer.h"

uint8_t timer_init(){
	// timer configuration for timer 0
	TCCR0 = 0x00;		// normal mode chosen
	TCNT0 = 0x00;		// setting initial timer value to 0 
	
	return 1;
}

uint8_t timer_start(unsigned int prescalar){

//this function set a prescalar as an integer value so that the timer starts	
	switch (prescalar){
		
		case 1: //no prescaling
			bitset(TCCR0,0);
			return 1;

		break;
		
		case 8: 
			bitset(TCCR0,1);
			return 1;
		break;
		
		case 64:
			bitset(TCCR0,0);
			bitset(TCCR0,1);
			return 1;
		break;
		
		case 256:
			bitset(TCCR0,2);
			return 1;
		break;
		
		case 1024:
			bitset(TCCR0,0);
			bitset(TCCR0,2);
			return 1;
		break;
		
		default:
			return 0;	
	} 
}
uint8_t timer_stop(){
	//timer stop
	TCCR0 = 0x00;
	return 1;
}

uint8_t timer_get_state(){
	// this function reads the overflow flag and then clears it if it was 1
	return bitcheck(TIFR,0);
}

uint8_t timer_delay(unsigned int overflows_number){
	unsigned int overflows_counter =0;
	
	while(overflows_counter < overflows_number){	
		while(timer_get_state()==0);
		//clear overflow flag
		bitset(TIFR,0);
		overflows_counter++;
	}
	return 1;
}