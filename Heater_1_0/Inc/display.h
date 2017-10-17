#ifndef DISPLAY_H
#define DISPLAY_H

#include "ugui.h"
#include "gpio.h"

#define SCREEN_HEIGHT 128
#define SCREEN_WIDTH 128

void Lcd_Pixel(UG_S16 x, UG_S16 y, UG_COLOR color);
void Lcd_print_screen(void);
void Lcd_set_write(void);
void Lcd_set_read(void);
void Lcd_send_command(int cmd);
void Lcd_send_data(int data);
void Lcd_reset(void);
int Lcd_status_check(int sta);
void pseudo_delay(void);
void Lcd_Init(void);


void lcdWR(int a);
void lcdRD(int a);
void lcdCE(int a);
void lcdCD(int a);
void lcdRS(int a);
void lcdFS(int a);

void lcdDB(int a);


#define LCD_TEXT_OFF_GRAPHIC_ON 152
#define LCD_AUTO_WRITE 176
#define LCD_OFF 144
#define LCD_EXTERNAL_GRAPHIC_MODE 136
#define LCD_OR_MODE 128
#define LCD_AUTO_RESET 178
#define LCD_SET_COURSOR_POINTER 33
#define LCD_SET_OFFSET_REGISTER 34
#define LCD_SET_ADDRESS_POINTER 36
#define LCD_SET_GRAPHIC_HOME_ADDRESS 66
#define LCD_SET_GRAPHIC_AREA 67
#define GRAPHIC_RAM_ADDRESS 0 //0x7FFF
#define LCD_GRAPHIC_AREA 16
#define LCD_SET_8_LINE_CURSOR 167
#define LCD_DATA_WRITE_AND_INC_ADP 192
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
