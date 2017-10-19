#ifndef REGULATOR_H
#define REGULATOR_H

#include "gpio.h"
#include "rcc.h"

#define INITIAL_P_VALUE 15
#define INITIAL_I_VALUE 1
#define INITIAL_D_VALUE 1

void Regulator_Init(void);
void Average_temp(void);
int Get_Temp(char a);
char Get_Set_temp(void);
char Get_pwr(void);
void Set_pwr(void);
int Get_Temp_Log(char i);
void Log_Temp(void);
int Get_PWR_Log(char i);
int Get_EGT_Log(char i);
char Second_interval_1(void);
char Second_interval_5(void);
char Second_interval_n(char n);
char Minute_interval_1(void);

#endif
