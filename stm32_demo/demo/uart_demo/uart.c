#include "uart.h"

void uart_init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= 0x1<<16; //IOCONʱ��
	LPC_IOCON->PIO1_6 &= ~(0x7);
	LPC_IOCON->PIO1_6 |= (0x1);   //�������Ź���ΪRXD
	LPC_IOCON->PIO1_7 &= ~(0x7);
	LPC_IOCON->PIO1_7 |= (0x1);  //�������Ź���TXD
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(0x1<<16); //�ر�IOCONʱ��
	
	LPC_SYSCON->UARTCLKDIV = 1;  //����UARTʱ�ӷ�Ƶ ϵͳʱ�ӱ�����Ĭ���㲻�����ã�
	LPC_SYSCON->SYSAHBCLKCTRL |= 0x1<<12; //ʹ��UARTʱ��
	
	LPC_UART->LCR |= 0x1<<7; 
	LPC_UART->DLL = 26;
	LPC_UART->DLM = 0;
	LPC_UART->LCR &= ~(0x1<<7);
	
	LPC_UART->LCR = 0x3; //����֡��ʽ 1λ��ʼλ  �������䣩  8λ����λ  1λֹͣλ  ��У��
	
	LPC_UART->FCR = 0x1;  //ʹ��FIFO����
	
	//LPC_UART->TER &= ~(0x1<<7);  UART������������������  ����ʧЧ  ���ᷢ������
}


void send_byte(int ch)
{
	LPC_UART->THR = ch&0xff;
	while(!(LPC_UART->LSR & 0x1<<5));
}

void put_string(char *str)
{
	while (*str) {
		send_byte(*str);
		str++;
	}
}

int recv_byte(void){
	while(!(LPC_UART->LSR & 0x1));
	return (LPC_UART->RBR & 0xff);
}

void get_string(char *str){
	int ch = 0;
	
	while((ch = recv_byte()) != '#'){
		*str++ = ch;
	}
	*str = '\0';
}

int fputc (int c, FILE *fp)
{
	send_byte(c);
	return c;
}

