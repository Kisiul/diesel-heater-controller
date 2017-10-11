#ifndef DISPLAY_H
#define DISPLAY_H

#include "stm32f1xx.h"
#include "ugui.h"

#define SCREEN_HEIGHT 128
#define SCREEN_WIDTH 128
class display{
	private:
		uint8_t a;
		uint8_t screen_area[SCREEN_WIDTH][SCREEN_HEIGHT];
		UG_GUI gui;
	public:
		display();
	void set_a(uint8_t in);
	void pixel(UG_S16 x , UG_S16 y ,UG_COLOR c);
		~display();
	
};


#endif
