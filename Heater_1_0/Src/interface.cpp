#include "interface.h"


UG_GUI gui;

void Display_Init(){
	UG_Init(&gui,Lcd_Pixel,SCREEN_WIDTH,SCREEN_HEIGHT);
	UG_FillScreen(C_WHITE);
}
