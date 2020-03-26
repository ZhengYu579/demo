#include "wdt.h"

void wdt_init(void){
	LPC_SYSCON->WDTCLKSEL = (0x1);
	LPC_SYSCON->WDTCLKUEN = (0x0);
	LPC_SYSCON->WDTCLKUEN = (0x1);	
	LPC_SYSCON->WDTCLKDIV = 12;
	LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<15);
	LPC_WDT->MOD |= 0x3;	
}

void feed_dog(int us){
	LPC_WDT->TC = (us*1000);
	LPC_WDT->FEED = 0xAA;
	LPC_WDT->FEED = 0x55;
}
