#include "ad.h"

void ad0_init(void){
	LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<16);  //Ϊ�������ſ�IOCONʱ��
	LPC_IOCON->R_PIO0_11 &= ~(0x7);      //��ʼ�����Ź���	
	LPC_IOCON->R_PIO0_11 |= (0x1<<1);   //��������ΪAD����
	LPC_IOCON->R_PIO0_11 &= ~(0x1<<7);  //����ģʽ����Ϊģ������
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(0x1<<16);    //�������Ž����ر�IOCONʱ��
	
	LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<13);  //ADת������ʱ��
	LPC_SYSCON->PDRUNCFG &= ~(0x1<<4);   //����ADC�ϵ�
	LPC_ADC->CR = (0X1);  //����ѡ��AD0����
	LPC_ADC->CR |= (99 << 8);    //��Ƶ����ʱ�ӣ����ܳ������Ƶ��4.5
}
int read_ad0(void){
	LPC_ADC->CR |= 0x1<<24;    //���� AD0 ת��   ��   start
	while((LPC_ADC->STAT & 0x1) == 0x0);
	return (LPC_ADC->DR[0] >> 6) & 0x3ff;
}
