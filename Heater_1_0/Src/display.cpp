#include "display.h"
#include "ugui.h"

void display::set_a(uint8_t in){
	a = in;
}

void display::pixel(UG_S16 x , UG_S16 y ,UG_COLOR c){
	if(c!=0) screen_area[x][y] = 1;
	else screen_area[x][y] = 0;
}
display::display(){

	/*TODO: set uGUI init*/

	//UG_Init(gui, func, 128, 128);
}
display::~display(){
	
}
 