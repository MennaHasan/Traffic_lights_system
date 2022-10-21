/*
 * Project2.c
 *
 * Created: 9/23/2022 5:12:02 PM
 * Author : Dell
 */ 



#include "Application/application.h"

// including the libraries for testing the drivers
#include "Application/DIODriverTest.h"
#include "Application/TimerDriverTest.h"
#include "Application/LEDDriverTest.h"
#include "Application/ButtonDriverTest.h"
#include "Application/InterruptDriverTest.h"
int main(void)
{
	//uint8_t buttonstate; 
	
	APP_init();
	
    while (1) 
    {
		APP_start();
    }
	return 0;
}