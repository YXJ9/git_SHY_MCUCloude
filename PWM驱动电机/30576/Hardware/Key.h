#ifndef  _KEY_H
#define  _KEY_H
#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#define  KEYALL_CLK   RCC_APB2Periph_GPIOA
#define  KEYALL_PORT  GPIOA
#define  KEY1_PIN     GPIO_Pin_3
#define  KEY2_PIN     GPIO_Pin_4
void  Key_Init(void);
uint8_t  Key_getnum(void);
#endif
