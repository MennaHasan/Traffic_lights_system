/*
 * interrupts.c
 *
 * Created: 10/21/2022 2:37:34 PM
 *  Author: Menatallah
 */ 

#include "interrupts.h"

extern uint8_t mode ;
 
 // for the callback function 
 
 // Callback registration
 void pedestrian_mode_callback(notify_ob f)
 {
	 g_notify_ob = f;
 } 
 
ISR(EXT_INT_1){
	if (mode ==0){	
		g_notify_ob();
	}
	//else do nothing
}
uint8_t interrupt_init(){
	
	// enabling general interrupts
	sei();
	// choosing the general interrupt sense
	bitset(MCUCR,0);
	bitset(MCUCR,1);
		
	//enabling external interrupt 1
	bitset(GICR,7);  //bit 7 is interrupt 1
	
	return 1;
}