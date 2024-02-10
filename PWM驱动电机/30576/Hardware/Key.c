
#include "Key.h"

void  Key_Init(void)
{
    RCC_APB2PeriphClockCmd(KEYALL_CLK,ENABLE);
	GPIO_InitTypeDef  GPIO_Initstructure;   
    GPIO_Initstructure.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin  =  KEY1_PIN | KEY2_PIN;
	//GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KEYALL_PORT,&GPIO_Initstructure);
}


uint8_t  Key_getnum(void)
{
    uint8_t  Keynum = 0;
	if (GPIO_ReadInputDataBit(KEYALL_PORT,KEY1_PIN) == 0)
	{
		Delay_ms(20);
		while  (GPIO_ReadInputDataBit(KEYALL_PORT,KEY1_PIN) == 0);
	    Delay_ms(20);
		Keynum = 1;
	}
	
	if (GPIO_ReadInputDataBit(KEYALL_PORT,KEY2_PIN) == 0)
	{
		Delay_ms(20);
		while  (GPIO_ReadInputDataBit(KEYALL_PORT,KEY2_PIN) == 0);
	    Delay_ms(20);
		Keynum = 2;
	}
	
	return  Keynum;
}
