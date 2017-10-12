#include "display.h"
#include "ugui.h"

void display::set_a(uint8_t in){
	a = in;
}

void display::set_pixel(UG_S16 x, UG_S16 y){
	screen_area[x][y] = 1;
}
void display::reset_pixel(UG_S16 x, UG_S16 y){
	screen_area[x][y] = 0;
}

display::display(){

}
display::~display(){
	
}
 
void pixel(UG_S16 x , UG_S16 y ,UG_COLOR c){
	if(c) display::set_pixel(x,y);
	else display::reset_pixel(x,y);
 }