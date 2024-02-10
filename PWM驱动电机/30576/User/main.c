#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "PWM.h"


//占空比0~100
int  main(void)
{
    PWM_Init();
    Key_Init();
    while(1)
	{
        if(Key_getnum()==1)//正转
        {
          
          TIM_SetOC2Init(10);
          TIM_SetOC3Init(0);
        }
        if(Key_getnum()==2)//反转
        {
          TIM_SetOC2Init(0);
          TIM_SetOC3Init(10);
        }
        
	}


}
