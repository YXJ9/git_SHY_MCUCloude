#include  "PWM.h"
#include "stm32f10x_rcc.h"
#include <stdint.h>


void PWM_Init(void)
{
   
   RCC_APB2PeriphClockCmd(GPIO_CLK, ENABLE);
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
   //重映射配置
   // RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//开启AFIO重映射时钟
   // GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);//使用重映射函数映射TIM2到PA15
   // GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);//关闭PA15引脚的调试端口定义

   GPIO_InitTypeDef GPIO_InitStructure;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_InitStructure.GPIO_Pin = GPIO_PIN;
   GPIO_InitStructure.GPIO_Speed  = GPIO_speed;
   GPIO_Init(GPIO_PORT, &GPIO_InitStructure);
   
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
   TIM_InternalClockConfig(TIM2);//内部时钟
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
   TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
   TIM_TimeBaseInitStructure.TIM_Period = 100-1; //ARR
   TIM_TimeBaseInitStructure.TIM_Prescaler = 720-1; //PSC
   TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
   TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);

   TIM_OCInitTypeDef  TIM_OCInitStructure;
   TIM_OCStructInit(&TIM_OCInitStructure);//初始化OC结构体
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
   TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
   TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
   TIM_OCInitStructure.TIM_Pulse = 0; //CCR
   TIM_OC1Init(TIM2, &TIM_OCInitStructure);

   TIM_Cmd(TIM2, ENABLE);
   
}

void PWM_SetCompare1(uint16_t Compare)
{
   TIM_SetCompare1(TIM2, Compare);
}



