#include "dht.h"

void dht11_init(void){
	LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<16);  //Ϊ�������ſ�ʱ��
	LPC_IOCON->PIO1_5 &= ~(0x7);  //��������Ϊ��׼PIO
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(0x1<<16);  //�������Ž�����ʱ��
}

int read_dht11(uint8_t *data){
	int i = 0;
	int count = 0;
	mdelay(1000);  // ��ʼ��ʱ1s
		
	//�򴫸������ʹ���18ms�ĵ͵�ƽ����ʾ��ʼ
	PIO1_5_OUT();  //�����������
	PIO1_5_LOW();   //���õ͵�ƽ
	mdelay(30);   //��ʱ18��������
	
	//�ȴ�Ӧ��
	PIO1_5_IN();    //������������
	while(GET_PIO1_5_LEVEL()==1);  //�ߵ�ƽѭ�����ȴ��͵�ƽ
	while(GET_PIO1_5_LEVEL() == 0);  //�͵�ƽѭ�����ȴ��ߵ�ƽ
	while(GET_PIO1_5_LEVEL()==1);    //�ߵ�ƽѭ�����ȴ��͵�ƽ       3��ѭ���˳���ʾ���һ�ֵ͸ߵ�ת��
	
	//ѭ����ȡ40λ������
	for(i = 0;i < 40;++i){              
		count = 0;
		while (GET_PIO1_5_LEVEL() == 0)        //��ȡ�͵�ƽʱ���ڼ�count�Ĵ���
			count++;
		while (GET_PIO1_5_LEVEL() == 1)        //��ȡ�ߵ�ƽʱ���ڼ�count�Ĵ���
			count--;
		if (count > 0)                  // count ����0 ��ʾ�͵�ƽʱ��ȸߵ�ƽʱ�䳤����ǰλΪ0
			data[i/8] &= ~(1<<(7-i%8)); // �ȵ��������Ǹ�λ
		else if (count < 0)             // count С��0 ��ʾ�͵�ƽʱ��ȸߵ�ƽʱ��̣���ǰλΪ1
			data[i/8] |= 1<<(7-i%8);
	}
	while(GET_PIO1_5_LEVEL() == 0);            // 40λ���ݷ�����ɺ�DHT11��������50us�ĵ͵�ƽ
	
	if((data[0]+data[1]+data[2]+data[3]) != data[4])   //����У��
		return -1;	                                   //У����󷵻�-1
	return 0;                                          //У��ɹ�����0
}

void dht11_output(void){     //����ǰ�� uart_init()
	uint8_t data[5];   //0��ʪ������λ��8λ��  1��ʪ��С��λ��8λ��  2���¶�����λ ��8λ�� 3���¶�С��λ ��8λ��  4��У��λ��8λ��
	if(read_dht11(data) < 0)
		printf("Check failure!\n");
	else 
		printf("temperature:%d.%d   humidity:%d.%d\n",data[2],data[3],data[0],data[1]);
}
