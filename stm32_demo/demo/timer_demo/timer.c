#include "timer.h"

void mdelay(int ms){
	LPC_SYSCON->SYSAHBCLKCTRL |= (0X1<<7);
	LPC_TMR16B0->PR = SystemCoreClock/1000 - 1;
	LPC_TMR16B0->MR0 = ms;
	LPC_TMR16B0->MCR |= (0x1<<2);
	LPC_TMR16B0->TCR |= (0x1<<1);
	LPC_TMR16B0->TCR &= ~(0x1 <<1);
	LPC_TMR16B0->TCR |= (0x1);
	while(LPC_TMR16B0->TCR &(0X1));
}

void udelay(int us){
	LPC_SYSCON->SYSAHBCLKCTRL |= (0X1<<7);
	LPC_TMR16B0->PR = SystemCoreClock/1000000 - 1;
	LPC_TMR16B0->MR0 = us;
	LPC_TMR16B0->MCR |= (0x1<<2);
	LPC_TMR16B0->TCR |= (0x1<<1);
	LPC_TMR16B0->TCR &= ~(0x1 <<1);
	LPC_TMR16B0->TCR |= (0x1);
	while(LPC_TMR16B0->TCR &(0X1));
}
