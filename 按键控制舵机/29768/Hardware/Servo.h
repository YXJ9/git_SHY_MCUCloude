#ifndef  _SERVO_H
#define  _SERVO_H

#include "stm32f10x.h"
#include "PWM.h"

void Servo_Init(void);
void Servo_SetAngle(float Angle);
#endif