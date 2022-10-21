/*
 * LEDDriverTest.c
 *
 * Created: 10/21/2022 2:33:02 PM
 *  Author: Menatallah
 */ 


#include "LEDDriverTest.h"

void test_LED_Driver(){
	LED_init(PORT_A,0);
	LED_init(PORT_B,1);
	
	LED_on(PORT_A,0);
	LED_on(PORT_B,1);



	for(int i=0; i<=30000; i++){
		
	}
	LED_off(PORT_A,0);
	LED_toggle(PORT_B,1);
	
	for(int i=0; i<=30000; i++){
		
	}
	LED_on(PORT_B,1);
	
	uint8_t val1, val2;
	LED_check(PORT_A,0,&val1);
	LED_check(PORT_B,1,&val2);	
}