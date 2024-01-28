#ifndef  _PWM_H
#define  _PWM_H

#include  "stm32f10x.h"
#define  GPIO_CLK   RCC_APB2Periph_GPIOA
#define  GPIO_PORT  GPIOA
#define  GPIO_PIN   GPIO_Pin_1
#define  GPIO_speed GPIO_Speed_50MHz


void PWM_Init(void);
void PWM_SetCompare2(uint16_t Compare);
#endif  
