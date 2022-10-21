/*
 * led.h
 *
 * Created: 9/24/2022 2:14:24 AM
 *  Author: Dell
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO Driver/dio.h"	
#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/interrupt library/interrupts.h"


// defining all the LEDs in the program
#define Green_LED_pedestrian_PORT PORT_B
#define Green_LED_pedestrian_PIN 0

#define Yellow_LED_pedestrian_PORT PORT_B
#define Yellow_LED_pedestrian_PIN 1

#define Red_LED_pedestrian_PORT PORT_B
#define Red_LED_pedestrian_PIN 2

#define Green_LED_cars_PORT PORT_A
#define Green_LED_cars_PIN 0

#define Yellow_LED_cars_PORT PORT_A
#define Yellow_LED_cars_PIN 1

#define Red_LED_cars_PORT PORT_A
#define Red_LED_cars_PIN 2


uint8_t LED_init(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_on(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_off(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin);
//uint8_t LED_blink(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_check(uint8_t ledPort, uint8_t ledPin, uint8_t *value);


#endif /* LED_H_ */