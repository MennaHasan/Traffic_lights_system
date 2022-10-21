/*
 * led.c
 *
 * Created: 9/24/2022 2:15:36 AM
 *  Author: Dell
 */ 

#include "led.h"

uint8_t LED_init(uint8_t ledPort, uint8_t ledPin){
	DIO_init(ledPin, ledPort, OUT);
	
	return 1;
}

uint8_t LED_on(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPin, ledPort, HIGH);
	return 1;
}
uint8_t LED_off(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPin, ledPort, LOW);
	return 1;
}
uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin){
	DIO_toggle(ledPin, ledPort);
	return 1;
}

uint8_t LED_check(uint8_t ledPort, uint8_t ledPin, uint8_t *value){
	DIO_read(ledPin,ledPort, value);
	return 1;
}