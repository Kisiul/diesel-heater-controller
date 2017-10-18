#ifndef INTERFACE_H
#define INTERFACE_H
#include "display.h"
#include "regulator.h"

#define PI 3.1415

void Display_Demo(void);
void Display_Init(void);
char* Itoa(int i, char b[]);
void Game(void);
void Line_Test(void);
void Gauge_display(void);
void Draw_Dial(char x0, char y0, char value);
char Bar_chart(int value, int min, int max);
#endif
