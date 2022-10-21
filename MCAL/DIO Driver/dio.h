/*
 * dio.h
 *
 * Created: 9/23/2022 7:56:30 PM
 *  Author: Dell
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"


#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// defines for directions
#define IN 0
#define OUT 1

// defines for values
#define LOW 0
#define HIGH 1

int DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
int DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
int DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
int DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);


#endif /* DIO_H_ */