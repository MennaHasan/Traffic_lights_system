/*
 * Button.h
 *
 * Created: 9/24/2022 3:15:41 AM
 *  Author: Dell
 */ 



#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/interrupt library/interrupts.h"

//defining the PIN and PORT of the button to make it on INT0 pin
#define Button_PORT PORT_D
#define Button_PIN 3

//defining button state macros
#define BUTTON_lOW		0
#define BUTTON_HIGH		1

int BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
int BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);


#endif /* BUTTON_H_ */