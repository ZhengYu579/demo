#include "led.h"

void led_init(void){
	LPC_IOCON->PIO3_0 &= ~(0x7);
	LPC_GPIO3->DIR |= 0x3;
}
void led1_on(void){
	LPC_GPIO3->DATA &= ~(0x1);
}
	
void led1_off(void){
	LPC_GPIO3->DATA |= (0x1);
}

void led2_on(void){
	LPC_GPIO3->DATA &= ~(0x1 << 1);
}

void led2_off(void){
	LPC_GPIO3->DATA |= (0x1 << 1);
}
