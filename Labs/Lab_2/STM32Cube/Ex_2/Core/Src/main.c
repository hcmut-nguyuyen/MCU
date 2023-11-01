/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define BLINK_LED_TIME 100
#define SEVEN_SEGMENT_STATE_NUMBER 4
#define SEVEN_SEGMENT_STATE_TIME 50
#define BLINK_DOT_TIME 100
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
int blink_led_counter = BLINK_LED_TIME;
int blink_led_flag = 0;
int seven_segment_state_counter = SEVEN_SEGMENT_STATE_TIME;
int seven_segment_state_flag = 0;
int blink_dot_counter = BLINK_DOT_TIME;
int blink_dot_flag = 0;
int led_buffer[SEVEN_SEGMENT_STATE_NUMBER] = {1, 2, 3, 0};
GPIO_PinState seven_segment_display[10][7] = {
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET},
  {GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET},
};
GPIO_PinState seven_segment_enable[SEVEN_SEGMENT_STATE_NUMBER][SEVEN_SEGMENT_STATE_NUMBER] = {
  {GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET}
};
int seven_segment_state = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG(int number);
void active7SEG(int index);
void update7SEG(int index);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_RESET);
  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    if(blink_led_flag == 1){
		blink_led_flag = 0;
		blink_led_counter = BLINK_LED_TIME;
	  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}
    if(seven_segment_state_flag == 1){
	  seven_segment_state_flag = 0;
	  seven_segment_state_counter = SEVEN_SEGMENT_STATE_TIME;
	  update7SEG(seven_segment_state++);
	  if(seven_segment_state >= SEVEN_SEGMENT_STATE_NUMBER){
	    seven_segment_state = 0;
	  }
    }
    if(blink_dot_flag == 1){
	  blink_dot_flag = 0;
	  blink_dot_counter = BLINK_DOT_TIME;
	  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin|SEG_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin LED_RED_Pin EN0_Pin EN1_Pin
                           EN2_Pin EN3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin SEG_D_Pin
                           SEG_E_Pin SEG_F_Pin SEG_G_Pin */
  GPIO_InitStruct.Pin = SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin|SEG_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim ){
  --blink_led_counter;
  if(blink_led_counter <= 0){
	blink_led_flag = 1;
  }
  --seven_segment_state_counter;
  if(seven_segment_state_counter <= 0) {
	seven_segment_state_flag = 1;
  }
  --blink_dot_counter;
  if(blink_dot_counter <= 0){
  	blink_dot_flag = 1;
  }
}
void display7SEG(int number){
  if(number >= 0 && number <= 9){
	HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, seven_segment_display[number][0]);
	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, seven_segment_display[number][1]);
	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, seven_segment_display[number][2]);
	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, seven_segment_display[number][3]);
	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, seven_segment_display[number][4]);
	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, seven_segment_display[number][5]);
	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, seven_segment_display[number][6]);
  }
}
void active7SEG(int index){
  if(index >=0 && index < SEVEN_SEGMENT_STATE_NUMBER){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, seven_segment_enable[index][0]);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, seven_segment_enable[index][1]);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, seven_segment_enable[index][2]);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, seven_segment_enable[index][3]);
  }
}
void update7SEG(int index) {
  if (index >= 0 && index < SEVEN_SEGMENT_STATE_NUMBER) {
	active7SEG(index);
	display7SEG(led_buffer[index]);
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
