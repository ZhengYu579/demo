#ifndef KEY_H
#define KEY_H

#include "LPC11xx.h"                    // Device header
#define SW_SEL 0
#define SW_UP 1
#define SW_DOWN 2
#define SW_LEFT 3
#define SW_RIGHT 4
#define SW_NULL 100

void key_init(void);
uint8_t get_key(void);

#endif
