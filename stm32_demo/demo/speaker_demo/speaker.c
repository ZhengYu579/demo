#include "speaker.h"

void speaker_pwm_config(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= 0x1<<16;
	LPC_IOCON->R_PIO1_1 &= ~0x7;
	LPC_IOCON->R_PIO1_1 |= 0x3;
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(0x1<<16);	
	LPC_SYSCON->SYSAHBCLKCTRL |= 0x1<<10;
	LPC_TMR32B1->PR = 9;
	LPC_TMR32B1->MCR |= 0x1<<4;
	LPC_TMR32B1->PWMC |= 0x1;

}

void play(int freq, int t)
{
	LPC_TMR32B1->MR1 = SystemCoreClock/(LPC_TMR32B1->PR+1)/freq;
	LPC_TMR32B1->MR0 = LPC_TMR32B1->MR1/2;
	LPC_TMR32B1->TCR |= 0x1<<1;
	LPC_TMR32B1->TCR &= ~(0x1<<1);
	LPC_TMR32B1->TCR = 0x1;
	mdelay(t);
	LPC_TMR32B1->TCR &= ~0x1;
}
