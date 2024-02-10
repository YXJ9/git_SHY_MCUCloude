#ifndef  _PWM_H
#define  _PWM_H

#include "stm32f10x.h"

#define  GPIO_CLK   RCC_APB2Periph_GPIOA
#define  GPIO_PORT  GPIOA

#define  GPIO_PIN1  GPIO_Pin_1
#define  GPIO_PIN2  GPIO_Pin_2

void PWM_Init(void);
void TIM_SetOC2Init(uint16_t value);
void TIM_SetOC3Init(uint16_t value);
#endif