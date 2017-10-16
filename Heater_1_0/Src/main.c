/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */

#include "rcc.h"
#include "gpio.h"
#include "display.h"
#include "ugui.h"
#include "interface.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* Configure the system clock */
  SystemClock_Config();
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_RTC_Init();

  /* USER CODE BEGIN 2 */
Fan(0);
Ignition(0);
Valve(0);


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

int alcd=0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
		if(alcd>=255){
			alcd=0;
			//Lcd_send_command(LCD_AUTO_RESET);
			Valve(1);
			HAL_Delay(1000);
			Valve(0);
			//Lcd_send_command(LCD_AUTO_WRITE);
		}

		while(!Lcd_status_check(0));
		while(!Lcd_status_check(1));
		Lcd_send_data(alcd++);
		Ignition(0);
		while(!Lcd_status_check(0));
		while(!Lcd_status_check(1));
		Lcd_send_command(LCD_DATA_WRITE_AND_INC_ADP);
		Ignition(1);

		
		
  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}






/* USER CODE BEGIN 4 */

/* USER CODE END 4 */



#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif
