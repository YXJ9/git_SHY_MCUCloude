#include "PWM.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

void PWM_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    // RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//重映射TIM2到GPIO
    // GPIO_PinRemapConfig(GPIO_PartialRemap_TIM2, ENABLE);
    //GPIOC初始化
    RCC_APB2PeriphClockCmd(GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin  = GPIO_PIN1|GPIO_PIN2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIO_PORT, &GPIO_InitStructure);
    //TIM2初始化
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_InternalClockConfig(TIM2);//选择内部时钟
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 100-1;//ARR精度1%
    TIM_TimeBaseInitStructure.TIM_Prescaler = 72-1; //PSC  10KHz
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
//初始化OC，因为咱用的是通用定时器，虽然高级定时器OC结构体内用不到，但也必须给结构体一个初始化！
    TIM_OCStructInit(&TIM_OCInitStructure);//初始化OC结构体
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//OC模式为PWM1
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能输出状态
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//极性，设置高电平
    TIM_OCInitStructure.TIM_Pulse = 0;//CCR
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);
    TIM_OC3Init(TIM2, &TIM_OCInitStructure);
    TIM_Cmd(TIM2, ENABLE);
}

void TIM_SetOC2Init(uint16_t value)
{
  TIM_SetCompare2(TIM2, value);
}

void TIM_SetOC3Init(uint16_t value)
{
 TIM_SetCompare3(TIM2, value);
}