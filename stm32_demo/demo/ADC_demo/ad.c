#include "ad.h"

void ad0_init(void){
	LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<16);  //为配置引脚开IOCON时钟
	LPC_IOCON->R_PIO0_11 &= ~(0x7);      //初始化引脚功能	
	LPC_IOCON->R_PIO0_11 |= (0x1<<1);   //配置引脚为AD功能
	LPC_IOCON->R_PIO0_11 &= ~(0x1<<7);  //引脚模式设置为模拟输入
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(0x1<<16);    //配置引脚结束关闭IOCON时钟
	
	LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<13);  //AD转换器开时钟
	LPC_SYSCON->PDRUNCFG &= ~(0x1<<4);   //配置ADC上电
	LPC_ADC->CR = (0X1);  //配置选择AD0引脚
	LPC_ADC->CR |= (99 << 8);    //分频工作时钟，不能超过最大频率4.5
}
int read_ad0(void){
	LPC_ADC->CR |= 0x1<<24;    //启动 AD0 转换   ，   start
	while((LPC_ADC->STAT & 0x1) == 0x0);
	return (LPC_ADC->DR[0] >> 6) & 0x3ff;
}
