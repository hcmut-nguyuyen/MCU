/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON1_Pin GPIO_PIN_5
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_6
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_7
#define BUTTON3_GPIO_Port GPIOA
#define SEG_A_Pin GPIO_PIN_0
#define SEG_A_GPIO_Port GPIOB
#define SEG_B_Pin GPIO_PIN_1
#define SEG_B_GPIO_Port GPIOB
#define SEG_C_Pin GPIO_PIN_2
#define SEG_C_GPIO_Port GPIOB
#define LED_GREEN_X_Pin GPIO_PIN_10
#define LED_GREEN_X_GPIO_Port GPIOB
#define LED_RED_Y_Pin GPIO_PIN_11
#define LED_RED_Y_GPIO_Port GPIOB
#define LED_AMBER_Y_Pin GPIO_PIN_12
#define LED_AMBER_Y_GPIO_Port GPIOB
#define LED_GREEN_Y_Pin GPIO_PIN_13
#define LED_GREEN_Y_GPIO_Port GPIOB
#define EN_TL_Pin GPIO_PIN_11
#define EN_TL_GPIO_Port GPIOA
#define EN_7SEG_X0_Pin GPIO_PIN_12
#define EN_7SEG_X0_GPIO_Port GPIOA
#define EN_7SEG_X1_Pin GPIO_PIN_13
#define EN_7SEG_X1_GPIO_Port GPIOA
#define EN_7SEG_Y0_Pin GPIO_PIN_14
#define EN_7SEG_Y0_GPIO_Port GPIOA
#define EN_7SEG_Y1_Pin GPIO_PIN_15
#define EN_7SEG_Y1_GPIO_Port GPIOA
#define SEG_D_Pin GPIO_PIN_3
#define SEG_D_GPIO_Port GPIOB
#define SEG_E_Pin GPIO_PIN_4
#define SEG_E_GPIO_Port GPIOB
#define SEG_F_Pin GPIO_PIN_5
#define SEG_F_GPIO_Port GPIOB
#define SEG_G_Pin GPIO_PIN_6
#define SEG_G_GPIO_Port GPIOB
#define LED_RED_X_Pin GPIO_PIN_8
#define LED_RED_X_GPIO_Port GPIOB
#define LED_AMBER_X_Pin GPIO_PIN_9
#define LED_AMBER_X_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
