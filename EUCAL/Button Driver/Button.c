/*
 * Button.c
 *
 * Created: 9/24/2022 3:15:53 AM
 *  Author: Dell
 */ 

#include "button.h"

int BUTTON_init(uint8_t buttonPort, uint8_t buttonPin){
	return DIO_init(buttonPin, buttonPort, IN);	
}
int BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value){
	return DIO_read(buttonPin, buttonPort, value);
}