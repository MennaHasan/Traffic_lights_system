/*
 * interrupts.h
 *
 * Created: 9/30/2022 4:28:13 PM
 *  Author: Menatallah
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
//#include "../DIO Driver/dio.h"

// for the call back function
typedef void (*notify_ob)(void);
notify_ob g_notify_ob;

void register_callback(notify_ob);
uint8_t interrupt_init();
void pedestrian_mode_callback(notify_ob f);

// defining external interrupt requests
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3

//#define set global interrupts and clear global interrupts
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
#define cli() __asm__ __volatile__ ("cli" ::: "memory")



// ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)




#endif /* INTERRUPTS_H_ */