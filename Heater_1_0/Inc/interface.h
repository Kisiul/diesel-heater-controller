#ifndef INTERFACE_H
#define INTERFACE_H
#include "display.h"
#include "regulator.h"
#include "rcc.h"

#define PI 3.1415
#define MENU_STATE_NO_MENU 0
#define MENU_STATE_MAIN_PAGE 1
#define MENU_STATE_SET_PWR 2
#define MENU_STATE_SET_TEMP 3
#define MENU_STATE_HELP 4
#define MENU_STATE_OFF 5



void Display_Demo(void);
void Display_Init(void);
char* Itoa(int i, char b[]);
void Game(void);
void Line_Test(void);
void Gauge_display(void);
void Log_display(void);
void Draw_Dial(char x0, char y0, char value);
char Bar_chart(int value, int min, int max);
void menu(void);

#endif
