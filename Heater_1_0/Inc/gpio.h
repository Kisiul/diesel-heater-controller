#ifndef GPIO_H
#define GPIO_H

#include "stm32f1xx_hal.h"
#include "math.h"

void Error_Handler(void);
void MX_GPIO_Init(void);
void MX_ADC1_Init(void);
void Fan(int a);
void Valve(int a);
void Ignition(int a);
int Temperature(char a);
unsigned int Opt_sensor(void);
char Get_keyboard(void);
void Reset_keyboard(void);
#endif
