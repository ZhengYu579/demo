#include "uart.h"

void uart_init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= 0x1<<16; //IOCON时钟
	LPC_IOCON->PIO1_6 &= ~(0x7);
	LPC_IOCON->PIO1_6 |= (0x1);   //配置引脚功能为RXD
	LPC_IOCON->PIO1_7 &= ~(0x7);
	LPC_IOCON->PIO1_7 |= (0x1);  //配置引脚功能TXD
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(0x1<<16); //关闭IOCON时钟
	
	LPC_SYSCON->UARTCLKDIV = 1;  //设置UART时钟分频 系统时钟倍数（默认零不起作用）
	LPC_SYSCON->SYSAHBCLKCTRL |= 0x1<<12; //使能UART时钟
	
	LPC_UART->LCR |= 0x1<<7; 
	LPC_UART->DLL = 26;
	LPC_UART->DLM = 0;
	LPC_UART->LCR &= ~(0x1<<7);
	
	LPC_UART->LCR = 0x3; //配置帧格式 1位起始位  （不用配）  8位数据位  1位停止位  不校验
	
	LPC_UART->FCR = 0x1;  //使能FIFO缓存
	
	//LPC_UART->TER &= ~(0x1<<7);  UART发送器持续发送数据  置零失效  不会发送数据
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

