#include "display.h"

char screen[SCREEN_WIDTH/8][SCREEN_HEIGHT];

void Lcd_Pixel(UG_S16 x, UG_S16 y, UG_COLOR color){
	if(color) screen[x/8][y] |= (1<<(7-x%8));
	else screen[x/8][y] &= ~(1<<(7-x%8));
}

void Lcd_print_screen(void){
			Lcd_send_command(LCD_AUTO_RESET);
			Lcd_send_data(GRAPHIC_RAM_ADDRESS & 0xFF);
			while(!Lcd_status_check(1));
			Lcd_send_data(GRAPHIC_RAM_ADDRESS >> 8);
			while(!Lcd_status_check(0));
			Lcd_send_command(LCD_SET_ADDRESS_POINTER);
			while(!Lcd_status_check(0));
			Lcd_send_command(LCD_AUTO_WRITE);
	
	for(int i=0; i<SCREEN_HEIGHT; i++){
		for(int j=0; j<SCREEN_WIDTH/8; j++){
			Lcd_send_data(screen[j][i]);
			}
		}
				Lcd_send_command(LCD_AUTO_RESET);
			Lcd_send_data(GRAPHIC_RAM_ADDRESS & 0xFF);
			while(!Lcd_status_check(1));
			Lcd_send_data(GRAPHIC_RAM_ADDRESS >> 8);
			while(!Lcd_status_check(0));
			Lcd_send_command(LCD_SET_ADDRESS_POINTER);
	}

	
	

void Lcd_send_command(int cmd){
	lcdRS(1);
	lcdRD(1);
	lcdWR(0);
	lcdCD(1);
	lcdCE(0);
	lcdDB(cmd);
	pseudo_delay();
	lcdCE(1);
}

void Lcd_send_data(int data){
	lcdRS(1);
	lcdRD(1);
	lcdWR(0);
	lcdCD(0);
	lcdCE(0);
	lcdDB(data);
	pseudo_delay();
	lcdCE(1);
}

void Lcd_reset(void){
	lcdRS(0);
	HAL_Delay(10);
	lcdRS(1);
}

int Lcd_status_check(int sta){
	int ret;
	Lcd_set_read();
	lcdRS(1);
	lcdRD(0);
	lcdWR(1);
	lcdCD(1);
	lcdCE(0);
	pseudo_delay();
	lcdCE(1);
	switch(sta){
		case 0:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
		break;
		case 1:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_14);
		break;
		case 2:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13);
		break;
		case 3:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12);
		break;
		case 4:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11);
		break;
		case 5:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10);
		break;
		case 6:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
		break;
		case 7:
			ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
		break;

		
	}
	Lcd_set_write();
	lcdRS(1);
	return(ret);
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
	if(a & 1<<0)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	if(a & 1<<1)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
	if(a & 1<<2)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
	if(a & 1<<3)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
	if(a & 1<<4)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
	if(a & 1<<5)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
	if(a & 1<<6)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	if(a & 1<<7)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
}

void pseudo_delay(void){
	//for(int i=0; i<2; i++);
}

void Lcd_Init(void){
	Lcd_set_write();
Lcd_reset();
while(!Lcd_status_check(1));
Lcd_send_data(GRAPHIC_RAM_ADDRESS & 0xFF);
while(!Lcd_status_check(1));
Lcd_send_data(GRAPHIC_RAM_ADDRESS >> 8);
while(!Lcd_status_check(0));
Lcd_send_command(LCD_SET_GRAPHIC_HOME_ADDRESS);
while(!Lcd_status_check(1));
Lcd_send_data(LCD_GRAPHIC_AREA);
while(!Lcd_status_check(1));
Lcd_send_data(0);
while(!Lcd_status_check(0));
Lcd_send_command(LCD_SET_GRAPHIC_AREA);
while(!Lcd_status_check(0));
Lcd_send_command(LCD_TEXT_OFF_GRAPHIC_ON);
while(!Lcd_status_check(0));
Lcd_send_command(LCD_EXTERNAL_GRAPHIC_MODE);
while(!Lcd_status_check(1));
Lcd_send_data(GRAPHIC_RAM_ADDRESS & 0xFF);
while(!Lcd_status_check(1));
Lcd_send_data(GRAPHIC_RAM_ADDRESS >> 8);
while(!Lcd_status_check(0));
Lcd_send_command(LCD_SET_ADDRESS_POINTER);
while(!Lcd_status_check(0));
Lcd_send_command(LCD_SET_8_LINE_CURSOR);
while(!Lcd_status_check(0));
}

void Lcd_set_write(void){
	  GPIO_InitTypeDef GPIO_InitStruct;
	  /*Configure GPIO pins :PA8 PA9 PA10 
                           PA11 PA12 PA13 PA14 
                           PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void Lcd_set_read(void){
	  GPIO_InitTypeDef GPIO_InitStruct;
	  /*Configure GPIO pins :PA8 PA9 PA10 
                           PA11 PA12 PA13 PA14 
                           PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
