/*
 * bit_manipulation.h
 *
 * Created: 9/24/2022 1:37:14 AM
 *  Author: Dell
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_


#define bitset(port,nbit)   ((port) |=  (1<<(nbit)))
#define bitclear(port,nbit) ((port) &= ~(1<<(nbit)))
#define bitflip(port,nbit)  ((port) ^=  (1<<(nbit)))
#define bitcheck(port,nbit) (port & (1<<nbit)) >>nbit



#endif /* BIT_MANIPULATION_H_ */