#include "interface.h"


UG_GUI gui;
char liczba[5];

void Display_Init(){
	Lcd_Init();
	UG_Init(&gui,Lcd_Pixel,SCREEN_WIDTH,SCREEN_HEIGHT);
	UG_FillScreen(C_WHITE);
	UG_DrawFrame(115,0,127,12,C_BLACK);
	UG_DrawLine(117,2,125,10,C_BLACK);
	UG_DrawLine(117,10,125,2,C_BLACK);
	UG_FontSelect(&FONT_8X8);
	UG_SetBackcolor(C_WHITE);
	UG_SetForecolor(C_BLACK);
	UG_PutString(35, 55, "Monika");
	UG_PutString(40, 65, Itoa(7378, liczba));
	UG_DrawCircle(63,59,36,C_BLACK);
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
