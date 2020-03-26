#include "key.h"

void key_init(void){
	LPC_IOCON->PIO0_3 &= ~(0X7);
	LPC_IOCON->PIO1_8 &= ~(0X7);
	LPC_IOCON->PIO1_9 &= ~(0X7);
	LPC_IOCON->PIO1_10 &= ~(0X7);
	LPC_IOCON->PIO1_11 &= ~(0X7);
}

uint8_t get_key(void){
	LPC_GPIO0->DIR &= ~(0X1<<3);
	LPC_GPIO1->DIR &= ~(0XF << 8);
	if((LPC_GPIO0->DATA & (0X1 << 3)) == 0){
		return SW_SEL;
	}
	if((LPC_GPIO1->DATA & (0X1 << 8)) == 0){
		return SW_UP;
	}
	if((LPC_GPIO1->DATA & (0X1 << 9)) == 0){
		return SW_DOWN;
	}
	if((LPC_GPIO1->DATA & (0X1 << 10)) == 0){
		return SW_LEFT;
	}
	if((LPC_GPIO1->DATA & (0X1 << 11)) == 0){
		return SW_RIGHT;
	}
	return SW_NULL;
}
