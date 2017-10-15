#include "display.h"


unsigned int screen[SCREEN_WIDTH][SCREEN_HEIGHT];

void Lcd_Pixel(UG_S16 x, UG_S16 y, UG_COLOR color){
	if(color) screen[x][y] = 1;
	else screen[x][y] = 0;
}

void lcdWR(int a){
	if(a) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET); 
}

void lcdRD(int a){
	if(a) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); 
}

void lcdCE(int a){
	if(a) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET); 
}

void lcdCD(int a){
	if(a) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET); 
}

void lcdRS(int a){
	if(a) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); 
}

void lcdFS(int a){
	if(a) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); 
}

void lcdDB(int a){
	
}