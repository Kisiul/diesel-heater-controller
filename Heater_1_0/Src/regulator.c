#include"regulator.h"

char temperature1_av[20];
char temperature2_av[20];
char temperature_log[128];
char Temp1_index;
char Temp2_index;

char P_value;
char I_value;
char D_value;

int Power;

char Set_temperature;
int Temperature_difference;
char EGT_difference;

void Regulator_Init(void){
P_value = INITIAL_P_VALUE;
I_value = INITIAL_I_VALUE;
D_value = INITIAL_D_VALUE;
	
	for(char i = 0; i<20; i++) temperature1_av[i] = 20;
	for(char i = 0; i<20; i++) temperature2_av[i] = 20;
	for(char i = 0; i<120; i++) temperature_log[i] = 255;
	
Power = 0;
Set_temperature = 25;
Temperature_difference = 0;
Temp1_index = 0;
Temp2_index = 0;
}
void Average_temp(void){
	if(Temp1_index >= 19) Temp1_index = 0;
	temperature1_av[Temp1_index] = Temperature(1)+50;
	temperature2_av[Temp1_index] = Temperature(2)+50;
	Temp1_index++;
}

int Get_Temp(char a){
	int temp=0;
	switch(a){
		case 1:
			for(char i=0; i<20; i++)temp += (temperature1_av[i] - 50);
		break;
		case 2:
			for(char i=0; i<20; i++)temp += (temperature2_av[i] - 50);
		break;
	}
	return temp/20;
}

char Get_Set_temp(void){
	return Set_temperature;
}

char Get_pwr(void){
	return Power;
}

void Set_pwr(void){
	Temperature_difference = Set_temperature - Get_Temp(2);
	
	Power = Temperature_difference * P_value;
	
	if(Power>100) Power = 100;
	if(Power<0) Power = 0;
}
