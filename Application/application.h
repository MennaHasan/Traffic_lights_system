/*
 * application.h
 *
 * Created: 9/24/2022 2:25:18 AM
 *  Author: Dell
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

//#include "avr/interrupt.h"
#include "../EUCAL/LED Driver/led.h"
#include "../EUCAL/Button Driver/Button.h"

#define PRESCALAR 64
#define NUMBER_OF_OVERFLOWS 306
#define F_CPU 1000000



uint8_t APP_init();
uint8_t APP_start();
uint8_t app_delay(int n);
uint8_t normal_mode();
void  pedestrian_mode();
uint8_t interrupt_init();


#endif /* APPLICATION_H_ */