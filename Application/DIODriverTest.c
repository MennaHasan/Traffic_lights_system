/*
 * DIODriverTest.c
 *
 * Created: 10/21/2022 2:32:04 PM
 *  Author: Menatallah
 */ 


#include "DIODriverTest.h"


// functions to be tested 

void test_DIO_Driver1(){
	//this is a test function 
	
	//1. it will initialize 4 ports as in and out 
	DIO_init(1,PORT_A,IN);
	DIO_init(2,PORT_B,OUT);
	DIO_init(4,PORT_C,IN);
	DIO_init(5,PORT_D,OUT);
	_delay_ms(3000);              // 3000ms delay

	// 2. it will write 0 on one of them and 1 on one of them 
	DIO_write(2,PORT_B,1);
	DIO_write(5,PORT_D,0);
	_delay_ms(3000);              // 3000ms delay

	//3. it will toggle them both 
	DIO_toggle(2,PORT_B);
	DIO_toggle(5,PORT_D);
	_delay_ms(3000);              // 3000ms delay	
}

void test_DIO_Driver2(){
	uint8_t val1 ;
	uint8_t val2 ;
	uint8_t val3 ;
	uint8_t val4 ;
	
	// initialization
	DIO_init(1,PORT_A,IN);
	DIO_init(2,PORT_B,OUT);
	DIO_init(4,PORT_C,IN);
	DIO_init(5,PORT_D,OUT);
	
	//4. it will read values on all pins
	DIO_read(1,PORT_A, &val1);
	DIO_read(2,PORT_B, &val2);
	DIO_read(4,PORT_C, &val3);
	DIO_read(5,PORT_D, &val4);
}