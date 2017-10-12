#include "display.h"
#include "ugui.h"

void display::set_a(uint8_t in){
	a = in;
}

void set_pixel(UG_S16 x, UG_S16 y){
	screen_area[x][y] = 1;
}
void reset_pixel(UG_S16 x, UG_S16 y){
	screen_area[x][y] = 0;
}

display::display(){

}
display::~display(){
	
}
 
 void pixel(UG_S16 x , UG_S16 y ,UG_COLOR c){

 }