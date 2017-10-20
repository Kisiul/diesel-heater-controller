#ifndef RCC_H
#define RCC_H
#include "stm32f1xx_hal.h"


void SystemClock_Config(void);
void MX_RTC_Init(void);

int Up_Time(void);
unsigned int Get_sys_ticked(void);


#endif
