#ifndef REGULATOR_H
#define REGULATOR_H

#include "gpio.h"

#define INITIAL_P_VALUE 15
#define INITIAL_I_VALUE 1
#define INITIAL_D_VALUE 1

void Regulator_Init(void);
void Average_temp(void);
int Get_Temp(char a);
char Get_Set_temp(void);
char Get_pwr(void);
void Set_pwr(void);

#endif
