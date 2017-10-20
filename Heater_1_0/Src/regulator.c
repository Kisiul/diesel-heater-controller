#include"regulator.h"

char temperature1_av[20];
char temperature2_av[20];
//char temperature_log[128][3];
char Temp1_index;
char TempLog_index;
char time_of_minute;

char P_value;
char I_value;
char D_value;

int Power;
int Timestamp, Timestamp_s, Timestamp_5s, Timestamp_ns, Timestamp_min;
	
char Set_temperature;
int Temperature_difference;
char EGT_difference;

void Regulator_Init(void){
P_value = INITIAL_P_VALUE;
I_value = INITIAL_I_VALUE;
D_value = INITIAL_D_VALUE;
Timestamp = Up_Time();
Timestamp_s = Timestamp;
Timestamp_5s = Timestamp;
Timestamp_ns = Timestamp;
Timestamp_min = Timestamp;
time_of_minute = Timestamp;
	for(char i = 0; i<20; i++) temperature1_av[i] = 70;
	for(char i = 0; i<20; i++) temperature2_av[i] = 70;
	//for(char j=0;j<3;j++)for(char i = 0; i<120; i++) temperature_log[i][j] = 255;
	
Power = 0;
Set_temperature = 25;
Temperature_difference = 0;
Temp1_index = 0;
TempLog_index = 0;

Average_temp();
Set_pwr();
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
/*
void Log_Temp(void){
	if(TempLog_index>=119){
		for(char j=0;j<3;j++)for(char i=1;i<120;i++)temperature_log[i-1][j]=temperature_log[i][j];
		temperature_log[119][0] = Get_Temp(1)+50;
		temperature_log[119][1] = Get_Temp(2)+50;
		temperature_log[119][2] = Get_pwr()+50;
	}
	else {
		temperature_log[TempLog_index][0] = Get_Temp(1)+50;
		temperature_log[TempLog_index][1] = Get_Temp(2)+50;
		temperature_log[TempLog_index++][2] = Get_pwr()+50;
		
	}
}

int Get_Temp_Log(char i){
	int temp = temperature_log[i][1]-50;
	if(temp-Get_Set_temp()>20&&temp!=205) temp = Get_Set_temp()+20;
	if(temp-Get_Set_temp()<-20&&temp!=205) temp = Get_Set_temp()-20;
	return temp;
}

int Get_EGT_Log(char i){
	int temp = temperature_log[i][0]-50;
	if(temp>120&&temp!=205)temp=120;
	if(temp<-5&&temp!=205) temp=-5;
	return temp;
}

int Get_PWR_Log(char i){
	return temperature_log[i][2]-50;
}
*/
void Set_pwr(void){
	Temperature_difference = Set_temperature - Get_Temp(2);
	
	Power = Temperature_difference * P_value;
	
	if(Power>100) Power = 100;
	if(Power<0) Power = 0;
}

char Second_interval_1(void){
	if(Up_Time()>Timestamp_s){
		Timestamp_s = Up_Time();
		return 1;
	}
	else return 0;
}
char Second_interval_5(void){
	if(Up_Time()>Timestamp_5s+4){
			Timestamp_5s = Up_Time();
			return 1;
	}
	else return 0;
}
char Second_interval_n(char n){
		if(Up_Time()>Timestamp_ns+n){
			Timestamp_ns = Up_Time();
			return 1;
	}
	else return 0;
}
char Minute_interval_1(void){
		if(Up_Time()>Timestamp_min+60){
			Timestamp_min = Up_Time();
			time_of_minute = 0;
			return 1;
	}
	else return 0;
}
char Get_time_of_minute(void){
	return time_of_minute;
}
void Inc_time_of_minute(void){
	time_of_minute++;
}
