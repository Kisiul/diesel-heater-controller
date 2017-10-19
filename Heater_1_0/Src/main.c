/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */

#include "rcc.h"
#include "gpio.h"
#include "display.h"
#include "ugui.h"
#include "interface.h"
#include "regulator.h"

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
	//char screen[SCREEN_HEIGHT*SCREEN_WIDTH]={0};
	//screen_ptr = screen;
  /* USER CODE END 1 */
  /* MCU Configuration----------------------------------------------------------*/
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* Configure the system clock */
  SystemClock_Config();
  /* Initialize all configured peripherals */
  MX_RTC_Init();
	MX_GPIO_Init();
  MX_ADC1_Init();
  
  /* USER CODE BEGIN 2 */

Fan(1);
Ignition(0);
Valve(0);
Regulator_Init();
Display_Init();
HAL_Delay(500);
Ignition(1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
		Average_temp();
		Set_pwr();
		//if(Second_interval_1())Log_Temp();
		if(Opt_sensor()<2000){
			Ignition(1);
					
		}
		else{
			Ignition(0);
					//Log_display();
		}
		//Gauge_display();
		if(Get_keyboard(1)%2)Log_display();
		else Gauge_display();
		//if(Second_interval_1())Log_Temp();
		
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
