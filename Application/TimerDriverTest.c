/*
 * TimerDriverTest.c
 *
 * Created: 10/21/2022 2:32:44 PM
 *  Author: Menatallah
 */ 

#include "TimerDriverTest.h"


//functions to be tested
void test_Timer_Driver1(){
	
	timer_init();
	
	timer_start(1);
	timer_stop();
	
	timer_start(8);
	timer_stop();
	
	timer_start(64);
	timer_stop();
		
	timer_start(8);
	while(timer_get_state()==0);
	
	timer_stop();	
	
}

void test_Timer_Driver2(){
	
	DIO_init(2,PORT_B,OUT);
	DIO_write(2,PORT_B,1);

	timer_start(64);
	timer_delay(306); //function to be tested 
	timer_stop();
	
	DIO_init(2,PORT_C,OUT);
	DIO_write(2,PORT_C,0);
}