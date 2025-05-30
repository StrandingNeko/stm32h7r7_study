/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7rsxx_hal.h"

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
#define PIN_HW_VER_ADC_Pin GPIO_PIN_3
#define PIN_HW_VER_ADC_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_1
#define LED_RED_GPIO_Port GPIOO
#define LED_BLUE_Pin GPIO_PIN_5
#define LED_BLUE_GPIO_Port GPIOO

/* USER CODE BEGIN Private defines */
#define LED_RED_ON()	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1)
#define LED_RED_OFF()	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0)

#define LED_BLUE_ON()	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0)
#define LED_BLUE_OFF()	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
