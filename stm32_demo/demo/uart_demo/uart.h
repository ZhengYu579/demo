#ifndef UART_H
#define UART_H
#include "LPC11xx.h" // Device header
#include "stdio.h"

void send_byte(int ch);
void put_string(char *str);
int recv_byte(void);
void get_string(char *str);
void uart_init(void);
int fputc (int c,FILE* fp);


#endif
