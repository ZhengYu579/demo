#include "dht.h"

void dht11_init(void){
	LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<16);  //为配置引脚开时钟
	LPC_IOCON->PIO1_5 &= ~(0x7);  //配置引脚为标准PIO
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(0x1<<16);  //配置引脚结束关时钟
}

int read_dht11(uint8_t *data){
	int i = 0;
	int count = 0;
	mdelay(1000);  // 起始延时1s
		
	//向传感器发送大于18ms的低电平，表示开始
	PIO1_5_OUT();  //引脚设置输出
	PIO1_5_LOW();   //设置低电平
	mdelay(30);   //延时18毫秒以上
	
	//等待应答
	PIO1_5_IN();    //引脚设置输入
	while(GET_PIO1_5_LEVEL()==1);  //高电平循环，等待低电平
	while(GET_PIO1_5_LEVEL() == 0);  //低电平循环，等待高电平
	while(GET_PIO1_5_LEVEL()==1);    //高电平循环，等待低电平       3次循环退出表示完成一轮低高低转换
	
	//循环获取40位的数据
	for(i = 0;i < 40;++i){              
		count = 0;
		while (GET_PIO1_5_LEVEL() == 0)        //获取低电平时间内加count的次数
			count++;
		while (GET_PIO1_5_LEVEL() == 1)        //获取高电平时间内减count的次数
			count--;
		if (count > 0)                  // count 大于0 表示低电平时间比高电平时间长，当前位为0
			data[i/8] &= ~(1<<(7-i%8)); // 先到的数据是高位
		else if (count < 0)             // count 小于0 表示低电平时间比高电平时间短，当前位为1
			data[i/8] |= 1<<(7-i%8);
	}
	while(GET_PIO1_5_LEVEL() == 0);            // 40位数据发送完成后，DHT11会继续输出50us的低电平
	
	if((data[0]+data[1]+data[2]+data[3]) != data[4])   //数据校验
		return -1;	                                   //校验错误返回-1
	return 0;                                          //校验成功返回0
}

void dht11_output(void){     //调用前请 uart_init()
	uint8_t data[5];   //0：湿度整数位（8位）  1：湿度小数位（8位）  2：温度整数位 （8位） 3：温度小数位 （8位）  4：校验位（8位）
	if(read_dht11(data) < 0)
		printf("Check failure!\n");
	else 
		printf("temperature:%d.%d   humidity:%d.%d\n",data[2],data[3],data[0],data[1]);
}
