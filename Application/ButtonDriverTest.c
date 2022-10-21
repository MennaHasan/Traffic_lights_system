/*
 * ButtonDriverTest.c
 *
 * Created: 10/21/2022 2:44:48 PM
 *  Author: Menatallah
 */ 


#include "ButtonDriverTest.h"
void test_Button_Driver(){
	
	uint8_t val;
	BUTTON_init(PORT_A, 0);
	BUTTON_read(PORT_A,0,&val);
	
}

