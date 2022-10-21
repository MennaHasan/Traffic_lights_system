/*
 * dio.c
 *
 * Created: 9/23/2022 7:56:18 PM
 *  Author: Dell
 */ 

#include "dio.h"

int DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction){
	switch (portNumber)
	{
		case PORT_A: 
			if (direction == IN){
				//DDRA &= ~(1<<pinNumber);	//initialize as input 
				bitclear(DDRA,pinNumber); //write low
				return 1;
			}
			else if (direction == OUT){
				//DDRA |= (1<<pinNumber);		//initialize as output
				bitset(DDRA,pinNumber); //write high
				return 1;
			}
			else{
				//error handling 
				return 0;
			}
		break;
		
		case PORT_B:
		if (direction == IN){
			//DDRB &= ~(1<<pinNumber);	//initialize as input
			bitclear(DDRB ,pinNumber); //write low
			return 1;
		}
		else if (direction == OUT){
			//DDRB |= (1<<pinNumber);		//initialize as output
			bitset(DDRB ,pinNumber); //write high
			return 1;
		}
		else{
			//error handling
			return 0;
		}
		break;
		
		case PORT_C:
		if (direction == IN){
			//DDRC &= ~(1<<pinNumber);	//initialize as input
			bitclear(DDRC,pinNumber); //write low
			return 1;
		}
		else if (direction == OUT){
			//DDRC |= (1<<pinNumber);		//initialize as output
			bitset(DDRC,pinNumber); //write high
			return 1;
		}
		else{
			//error handling
			return 0;
		}
		break;
		
		case PORT_D:
		if (direction == IN){
			//DDRD &= ~(1<<pinNumber);	//initialize as input
			bitclear(DDRD,pinNumber); //write low
			return 1;
		}
		else if (direction == OUT){
			//DDRD |= (1<<pinNumber);		//initialize as output
			bitset(DDRD,pinNumber); //write high
			return 1;
		}
		else{
			//error handling
			return 0;
		}
		break;
		
		default: 
			return 0;
	}
}
int DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value){
	switch (portNumber)
	{
		case PORT_A:
		if (value == LOW){
			//PORTA &= ~(1<<pinNumber);	//write low
			bitclear(PORTA,pinNumber); //write low
			return 1;
		}
		else if (value == HIGH){
			//PORTA |= (1<<pinNumber);		//write high
			bitset(PORTA,pinNumber); //write high
			return 1;
		}
		else{
			//error handling
			return 0;
		}
		break;
		
		case PORT_B:
		if (value == LOW){
			//PORTB &= ~(1<<pinNumber);	
			bitclear(PORTB,pinNumber); //write low
			return 1;
		}
		else if (value == HIGH){
			//PORTB |= (1<<pinNumber);		//write high
			bitset(PORTB,pinNumber); //write high
			return 1;
		}
		else{
			//error handling
			return 0;
		}
		break;
		
		case PORT_C:
		if (value == LOW){
			//PORTC &= ~(1<<pinNumber);	//write low
			bitclear(PORTC,pinNumber); //write low
			return 1;
		}
		else if (value == HIGH){
			//PORTC |= (1<<pinNumber);		//write high
			bitset(PORTC,pinNumber); //write high
			return 1;
		}
		else{
			//error handling
			return 0;
		}
		break;
		
		case PORT_D:
		if (value == LOW){
			//PORTD &= ~(1<<pinNumber);	//write low
			bitclear(PORTD,pinNumber); //write low
			return 1;
		}
		else if (value == HIGH){
			//PORTD |= (1<<pinNumber);		//write high
			bitset(PORTD,pinNumber); //write high
			return 1;
		}
		else{
			return 0;
		}
		break;
	}
	return 0;
}
int DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	switch (portNumber)
	{
		case PORT_A:
			bitflip(PORTA,pinNumber); 
			return 1;
		break;
		
		case PORT_B:
			bitflip(PORTB,pinNumber); 
			return 1;
		break;
		
		case PORT_C:
			bitflip(PORTC,pinNumber); 
			return 1;
		break;
	
		case PORT_D:
			bitflip(PORTD,pinNumber); 
			return 1;
		break;
		
		default:
			return 0;
		break;
	}
}
int DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	switch (portNumber)
	{
		case PORT_A:
			*value = bitcheck(PINA,pinNumber);
			return 1;
		break;
		
		case PORT_B:
			*value = bitcheck(PINB,pinNumber);
			return 1;
		break;	
		
		case PORT_C:
			*value = bitcheck(PINC,pinNumber);
			return 1;
		break;
		
		case PORT_D:
			*value = bitcheck(PIND,pinNumber);
			return 1;
		break;
		
		default:
			//error handling
			return 0;
		break;
	}
	
}