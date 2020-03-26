#include "nled.h"

void nled_init(void){
	LPC_IOCON->PIO2_9 &= ~(0x7);
	LPC_IOCON->PIO2_10 &= ~(0x7);
	LPC_IOCON->PIO2_11 &= ~(0x7);
	LPC_GPIO2->DIR |= (0x7<<9);
}

void nled_on(uint8_t word){
	uint8_t code[] = {0x12,  0xDE,  0x0B, 0x0E, 0xC6, 0x26, 0x22, 0x9E, 0x02, 0x06, 0x82, 0x62, 0x33, 0x4A, 0x23, 0xA3};
	int i = 0;
	LPC_GPIO2->DATA |= (0x1<<9);
	for(i = 7;i >= 0; --i){
		LPC_GPIO2->DATA &= ~(0X1 << 10);
		if(((code[word] >> i) & 1) == 0){
			LPC_GPIO2->DATA &= ~(0x1 << 11);
		}else{
			LPC_GPIO2->DATA |= (0x1 << 11);
		}
		LPC_GPIO2->DATA |= (0X1 << 10);
	}
	LPC_GPIO2->DATA &= ~(0x1<<9);
}
