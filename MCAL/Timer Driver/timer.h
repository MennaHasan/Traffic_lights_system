/*
 * timer.h
 *
 * Created: 9/24/2022 4:01:41 PM
 *  Author: Dell
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"


uint8_t timer_init();
uint8_t timer_start(unsigned int prescalar);
uint8_t timer_stop();
uint8_t timer_get_state();
uint8_t timer_delay(unsigned int overflows_number);

#endif /* TIMER_H_ */