/*
 * application.c
 *
 * Created: 9/24/2022 2:25:06 AM
 *  Author: Dell
 */ 
#include "Application.h"

uint8_t mode ;
// mode = 0 when normal mode and 1 when pedestrian mode

uint8_t APP_init(){

	//initialize the application's LEDs
	LED_init(Green_LED_pedestrian_PORT, Green_LED_pedestrian_PIN);
	LED_init(Yellow_LED_pedestrian_PORT, Yellow_LED_pedestrian_PIN);
	LED_init(Red_LED_pedestrian_PORT, Red_LED_pedestrian_PIN);
	
	LED_init(Green_LED_cars_PORT, Green_LED_cars_PIN);
	LED_init(Yellow_LED_cars_PORT, Yellow_LED_cars_PIN);
	LED_init(Red_LED_cars_PORT, Red_LED_cars_PIN);
	
	//initialize the button
	BUTTON_init(Button_PORT, Button_PIN);
	
	//initialize the timer
	timer_init();
	
	//initialize interrupts
	interrupt_init();
	pedestrian_mode_callback(pedestrian_mode);
	return 1;
}
uint8_t APP_start(){
	normal_mode();
	return 1;
}
uint8_t app_delay(int n){
	timer_start(PRESCALAR);
	timer_delay(n);
	timer_stop();
	
	return 1;
}
uint8_t normal_mode(){
	interrupt_init();
	mode = 0;
	//this gets executed and repeated whenever in normal mode

	// green for cars on
	LED_off(Red_LED_pedestrian_PORT, Red_LED_pedestrian_PIN);
	LED_off(Yellow_LED_cars_PORT, Yellow_LED_cars_PIN);
	
	LED_on(Green_LED_cars_PORT, Green_LED_cars_PIN);
	
	// yellow for cars on
	app_delay(NUMBER_OF_OVERFLOWS);	
	LED_off(Green_LED_cars_PORT, Green_LED_cars_PIN);	
	//make the led blink for 5 seconds
	for (int i=1;i<=4;i++){
		DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
		app_delay(61);
	}
		DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
		app_delay(62);
	
	// red for cars on
	LED_off(Yellow_LED_cars_PORT, Yellow_LED_cars_PIN);
	LED_on(Red_LED_cars_PORT, Red_LED_cars_PIN);
	
	// yellow for cars on
	app_delay(NUMBER_OF_OVERFLOWS);
	LED_off(Red_LED_cars_PORT, Red_LED_cars_PIN);
	//make the led blink for 5 seconds
	for (int i=1;i<=4;i++){
		DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
		app_delay(61);
	}
	DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
	app_delay(62);
	return 1;
}
void  pedestrian_mode(){
	mode = 1;
	uint8_t led_state;
	LED_off(Red_LED_pedestrian_PORT, Red_LED_pedestrian_PIN);

	LED_check(Red_LED_cars_PORT,Red_LED_cars_PIN, &led_state);
	if (led_state ==1){
		LED_on(Green_LED_pedestrian_PORT, Green_LED_pedestrian_PIN);
		app_delay(NUMBER_OF_OVERFLOWS);
	}else{
		LED_off(Green_LED_cars_PORT,Green_LED_cars_PIN);
		LED_on(Red_LED_pedestrian_PORT, Red_LED_pedestrian_PIN);
		
		//make the led blink for 5 seconds
		for (int i=1;i<=4;i++){
			DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
			DIO_toggle(Yellow_LED_pedestrian_PIN, Yellow_LED_pedestrian_PORT);
			app_delay(61);
		}
		DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
		DIO_toggle(Yellow_LED_pedestrian_PIN, Yellow_LED_pedestrian_PORT);
		app_delay(62);
		LED_off(Yellow_LED_pedestrian_PORT, Yellow_LED_pedestrian_PIN);
		LED_off(Yellow_LED_cars_PORT, Yellow_LED_cars_PIN);
		// blinking done
		LED_off(Red_LED_pedestrian_PORT, Red_LED_pedestrian_PIN);
		LED_off(Green_LED_cars_PORT, Green_LED_cars_PIN);

	
		LED_on(Red_LED_cars_PORT, Red_LED_cars_PIN);
		LED_on(Green_LED_pedestrian_PORT, Green_LED_pedestrian_PIN);
		app_delay(NUMBER_OF_OVERFLOWS);
	}
	
	LED_off(Red_LED_cars_PORT, Red_LED_cars_PIN);
	
	//make the led blink for 5 seconds
	for (int i=1;i<=4;i++){
		DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
		DIO_toggle(Yellow_LED_pedestrian_PIN, Yellow_LED_pedestrian_PORT);
		app_delay(61);
	}
	DIO_toggle(Yellow_LED_cars_PIN, Yellow_LED_cars_PORT);
	DIO_toggle(Yellow_LED_pedestrian_PIN, Yellow_LED_pedestrian_PORT);
	app_delay(62);
	LED_off(Yellow_LED_pedestrian_PORT, Yellow_LED_pedestrian_PIN);
	LED_off(Yellow_LED_cars_PORT , Yellow_LED_cars_PIN);
	// blinking done
	

	LED_off(Green_LED_pedestrian_PORT, Green_LED_pedestrian_PIN);
	LED_off(Red_LED_cars_PORT,Red_LED_cars_PIN);
	
	LED_on(Red_LED_pedestrian_PORT, Red_LED_pedestrian_PIN);
	LED_off(Green_LED_cars_PORT,Green_LED_cars_PIN);
	normal_mode();
	
}

