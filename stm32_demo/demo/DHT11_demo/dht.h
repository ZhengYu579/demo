#ifndef DHT_H
#define DHT_H
#include "LPC11xx.h"                    // Device header
#include "timer.h"
#include "uart.h"

#define PIO1_5_OUT()  LPC_GPIO1->DIR |= (0x1<<5)     //引脚设为输出
#define PIO1_5_IN()  LPC_GPIO1->DIR &= ~(0x1<<5)     //引脚设为输入
#define PIO1_5_HIGH()  LPC_GPIO1->DIR |= (0x1<<5)    //引脚设为高电平
#define PIO1_5_LOW()   LPC_GPIO1->DATA &= ~(0x1<<5)  //引脚设为低电平
#define GET_PIO1_5_LEVEL()  ((LPC_GPIO1->DATA>>5) & (0x1))  //获取引脚电平

void dht11_init(void);
int read_dht11(uint8_t *data);
void dht11_output(void);

#endif
