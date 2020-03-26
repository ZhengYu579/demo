#include "my.h"

int main(void){
	uart_init();
	dht11_init();
	while(1){
		dht11_output();
		mdelay(1000);
	}
}
