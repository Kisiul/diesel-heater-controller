#ifndef DISPLAY_H
#define DISPLAY_H

#include "ugui.h"
#include "gpio.h"

#define SCREEN_HEIGHT 128
#define SCREEN_WIDTH 128

void Lcd_Pixel(UG_S16 x, UG_S16 y, UG_COLOR color);
void Lcd_set_write(void);
void Lcd_set_read(void);


void lcdWR(int a);
void lcdRD(int a);
void lcdCE(int a);
void lcdCD(int a);
void lcdRS(int a);
void lcdFS(int a);

void lcdDB(int a);

#endif

/*conections:
lcd -> uC

WR -> PB7 !
RD -> PB6 !
CE -> PB5 !
CD -> PB4
RS -> PB3 !
FS -> PA4

DB0 -> PA15
DB1 -> PA14
DB2 -> PA13
DB3 -> PA12
DB4 -> PA11
DB5 -> PA10
DB6 -> PA9
DB7 -> PA8

*/
