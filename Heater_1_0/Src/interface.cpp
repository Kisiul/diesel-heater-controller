#include "interface.h"


UG_GUI gui;
char liczba[5];
char menu_page;

void Display_Init(){
	Lcd_Init();
	UG_Init(&gui,Lcd_Pixel,SCREEN_WIDTH,SCREEN_HEIGHT);
	UG_FillScreen(C_BLACK);
	UG_FontSelect(&FONT_8X8);
	UG_SetBackcolor(C_BLACK);
	UG_SetForecolor(C_WHITE);
	UG_PutString(25, 50, "Krzysztof\nDabrowski");
	UG_PutString(18, 70, "733 411 819");
	
	menu_page = 0;
	Lcd_print_screen();
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
	UG_PutString(85, 4, "ACT");
	UG_PutString(89, 20, Itoa(Get_Temp(2), liczba));
	
	UG_DrawFrame(2,108,61, 124, C_WHITE);
	UG_FillFrame(4,110,4+Bar_chart(Opt_sensor(),0,4096),122, C_WHITE);
	UG_PutString(15, 76, "FIRE");
	UG_PutString(23, 92, Itoa(Opt_sensor()/40.96, liczba));
	
	UG_DrawFrame(65,108,126, 124, C_WHITE);
	UG_FillFrame(67,110,67+Bar_chart(Get_pwr(),0,100),122, C_WHITE);
	UG_PutString(85, 76, "PWR");
	UG_PutString(89, 92, Itoa(Get_pwr(), liczba));
		
	
	UG_PutString(34, 59, "set:");
	UG_PutString(68, 59, Itoa(Get_Set_temp(), liczba));
	Lcd_print_screen();
}

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
	
	Lcd_print_screen();
}
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

void Draw_Dial(char x0, char y0, char value){
	char x1,y1,x2,y2;
	x1 = x0-25*cos(value*(2*PI/100)-(PI/4));
	y1 = y0-25*sin(value*(2*PI/100)-(PI/4));
	x2 = x0-30*cos(value*(2*PI/100)-(PI/4));
	y2 = y0-30*sin(value*(2*PI/100)-(PI/4));
	
	UG_DrawLine(x1,y1,x2,y2, C_WHITE);
}

char Bar_chart(int value, int min, int max){
	int ret = value*55/(max-min);
	if(ret>55) ret = 55;
	if(ret<1) ret = 1;
	return ret;
}
