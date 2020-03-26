#ifndef WDT_H
#define WDT_H

#include "LPC11xx.h"                    // Device header

void wdt_init(void);
void feed_dog(int us);

#endif
