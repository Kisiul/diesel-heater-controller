#include "interface.h"


UG_GUI gui;
char liczba[5];
char menu_state;
char menu_next_state;

void Display_Init(){
	Lcd_Init();
	UG_Init(&gui,Lcd_Pixel,SCREEN_WIDTH,SCREEN_HEIGHT);
	UG_FillScreen(C_BLACK);
	UG_FontSelect(&FONT_6X8);
	UG_SetBackcolor(C_BLACK);
	UG_SetForecolor(C_WHITE);
	UG_PutString(25, 50, "Krzysztof\nDabrowski");
	UG_PutString(18, 70, "733 411 819");
	
	menu_state = MENU_STATE_NO_MENU;
	menu_next_state = MENU_STATE_MAIN_PAGE;
	Lcd_print_screen();
}

void menu(void){
	switch (menu_state){
		case MENU_STATE_NO_MENU:
			menu_next_state = MENU_STATE_MAIN_PAGE;
		
			break;
		case MENU_STATE_MAIN_PAGE:
			UG_FillRoundFrame(10,28,118,70,5,C_BLACK);
			UG_DrawRoundFrame(10,28,118,70,5,C_WHITE);
			UG_PutString(13,30,"A - Stala temp.");
			UG_PutString(13,40,"B - Stala moc");
			UG_PutString(13,50,"C - Wylacz");
			UG_PutString(13,60,"D - Pomoc");
			if(Get_keyboard()=='A')menu_next_state = MENU_STATE_SET_TEMP;
			else if(Get_keyboard()=='B')menu_next_state = MENU_STATE_SET_PWR;
			else if(Get_keyboard()=='C')menu_next_state = MENU_STATE_OFF;
			else if(Get_keyboard()=='D')menu_next_state = MENU_STATE_HELP;
			else menu_next_state = MENU_STATE_NO_MENU;
		break;
		case MENU_STATE_SET_TEMP:
			UG_FillRoundFrame(10,28,118,70,5,C_BLACK);
			UG_DrawRoundFrame(10,28,118,70,5,C_WHITE);
			UG_PutString(13,30,"Temp:");
			menu_next_state = MENU_STATE_NO_MENU;
		break;
		case MENU_STATE_SET_PWR:
			UG_FillRoundFrame(10,28,118,70,5,C_BLACK);
			UG_DrawRoundFrame(10,28,118,70,5,C_WHITE);
			UG_PutString(13,30,"Moc:");
			menu_next_state = MENU_STATE_NO_MENU;
		break;
		case MENU_STATE_OFF:
			UG_FillRoundFrame(10,28,118,70,5,C_BLACK);
			UG_DrawRoundFrame(10,28,118,70,5,C_WHITE);
			UG_PutString(13,30,"Off");
			menu_next_state = MENU_STATE_NO_MENU;
		break;
				case MENU_STATE_HELP:
			UG_FillRoundFrame(10,28,118,70,5,C_BLACK);
			UG_DrawRoundFrame(10,28,118,70,5,C_WHITE);
			UG_PutString(13,30,"Krzysztof\nDabrowski\n733411819");
			menu_next_state = MENU_STATE_NO_MENU;
		break;

	}
	if(Get_keyboard()){
		menu_state = menu_next_state;
		Reset_keyboard();
	}
}

void Gauge_display(void){
	
	UG_FillScreen(C_BLACK);
	UG_DrawLine(1,54,127,54,C_WHITE);
	UG_DrawLine(63,0,63,54,C_WHITE);
	UG_DrawLine(63,72,63,127,C_WHITE);
	UG_DrawLine(1,72,127,72,C_WHITE);
	
	UG_DrawFrame(2,36,61, 52, C_WHITE);
	UG_FillFrame(4,38,4+Bar_chart(Get_Temp(1),0,120),50, C_WHITE);
	UG_PutString(19, 4, "EGT");
	UG_PutString(23, 20, Itoa(Get_Temp(1), liczba));
	
	UG_DrawFrame(65,36,126, 52, C_WHITE);
	UG_FillFrame(67,38,67+Bar_chart(Get_Temp(2),0,50),50, C_WHITE);
	UG_PutString(81, 4, "TEMP");
	UG_PutString(89, 20, Itoa(Get_Temp(2), liczba));
	
	UG_DrawFrame(2,108,61, 124, C_WHITE);
	UG_FillFrame(4,110,4+Bar_chart(Opt_sensor(),0,4096),122, C_WHITE);
	UG_PutString(15, 76, "FIRE");
	UG_PutString(23, 92, Itoa(Opt_sensor()/40.96, liczba));
	
	UG_DrawFrame(65,108,126, 124, C_WHITE);
	UG_FillFrame(67,110,67+Bar_chart(Get_pwr(),0,100),122, C_WHITE);
	UG_PutString(85, 76, "PWR");
	UG_PutString(89, 92, Itoa(Get_pwr(), liczba));
	UG_DrawLine(67,106,67+Bar_chart(Get_time_of_minute(),0,59),106,C_WHITE);	
	
	UG_PutString(34, 59, "set:");
	UG_PutString(68, 59, Itoa(Get_Set_temp(), liczba));

	//UG_PutChar(Get_keyboard(), 100, 58, C_BLACK, C_WHITE);			
	//Lcd_print_screen();
}
/*
void Log_display(void){
	UG_FillScreen(C_BLACK);
	UG_PutString(1,2,"UpTime:");
	UG_PutString(56,2,Itoa(Up_Time()/3600, liczba));
	UG_PutString(72,2,":");
	UG_PutString(80,2,Itoa((Up_Time()/60)%60, liczba));
	UG_PutString(96,2,":");
	UG_PutString(104,2,Itoa(Up_Time()%60, liczba));
	
	UG_DrawLine(1,11,1,52, C_WHITE);
	UG_DrawLine(1, 31, 128, 31, C_WHITE);
	
	for(char i=0;i<120;i++)if(Get_Temp_Log(i)!=205)UG_DrawPixel(i+1, 31+(Get_Set_temp()-Get_Temp_Log(i)), C_WHITE);
	
	UG_DrawLine(1,56,1,115, C_WHITE);
	UG_DrawLine(1, 110, 128, 110, C_WHITE);
	
	for(char i=0;i<120;i++)if(Get_EGT_Log(i)!=205)UG_DrawPixel(i+1, 110-Get_EGT_Log(i)/2, C_WHITE);
	
	UG_DrawLine(1,118,1,127, C_WHITE);
	UG_DrawLine(1, 127, 128, 127, C_WHITE);
	
	for(char i=0;i<120;i++)if(Get_PWR_Log(i)!=205)UG_DrawPixel(i+1, 127-(Get_PWR_Log(i)/10), C_WHITE);
	
	//UG_PutString(2,63, Itoa(Get_sys_ticked(), liczba));
	Lcd_print_screen();
}
*/

char* Itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

char Bar_chart(int value, int min, int max){
	int ret = value*55/(max-min);
	if(ret>55) ret = 55;
	if(ret<1) ret = 1;
	return ret;
}
