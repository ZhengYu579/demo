#ifndef DHT_H
#define DHT_H
#include "LPC11xx.h"                    // Device header
#include "timer.h"
#include "uart.h"

#define PIO1_5_OUT()  LPC_GPIO1->DIR |= (0x1<<5)     //������Ϊ���
#define PIO1_5_IN()  LPC_GPIO1->DIR &= ~(0x1<<5)     //������Ϊ����
#define PIO1_5_HIGH()  LPC_GPIO1->DIR |= (0x1<<5)    //������Ϊ�ߵ�ƽ
#define PIO1_5_LOW()   LPC_GPIO1->DATA &= ~(0x1<<5)  //������Ϊ�͵�ƽ
#define GET_PIO1_5_LEVEL()  ((LPC_GPIO1->DATA>>5) & (0x1))  //��ȡ���ŵ�ƽ

void dht11_init(void);
int read_dht11(uint8_t *data);
void dht11_output(void);

#endif
