/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    flash.c
  * @brief   This file provides code for the configuration
  *          of the Flash instances.
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
/* Includes ------------------------------------------------------------------*/
#include "flash.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* FLASH init function */
void MX_FLASH_Init(void)
{

  /* USER CODE BEGIN FLASH_Init 0 */

  /* USER CODE END FLASH_Init 0 */

  FLASH_OBProgramInitTypeDef pOBInit = {0};

  /* USER CODE BEGIN FLASH_Init 1 */

  /* USER CODE END FLASH_Init 1 */
  if (HAL_FLASH_Unlock() != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_FLASH_OB_Unlock() != HAL_OK)
  {
    Error_Handler();
  }
  pOBInit.OptionType = OPTIONBYTE_USER;
  pOBInit.USERType = OB_USER_IWDG_SW|OB_USER_NRST_STOP
                              |OB_USER_NRST_STDBY|OB_USER_VDDIO_HSLV
                              |OB_USER_IWDG_STOP|OB_USER_IWDG_STDBY
                              |OB_USER_XSPI1_HSLV|OB_USER_XSPI2_HSLV
                              |OB_USER_SRAM_ECC;
  pOBInit.USERConfig1 = OB_IWDG_SW|OB_STOP_NORST
                              |OB_STANDBY_NORST|OB_VDDIO_HSLV_DISABLE
                              |OB_IWDG_STOP_RUN|OB_IWDG_STDBY_RUN
                              |OB_XSPI1_HSLV_ENABLE|OB_XSPI2_HSLV_ENABLE;
  pOBInit.USERConfig2 = OB_AXISRAM_ECC_DISABLE;
  if (HAL_FLASHEx_OBProgram(&pOBInit) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_FLASH_OB_Lock() != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_FLASH_Lock() != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FLASH_Init 2 */

  /* USER CODE END FLASH_Init 2 */

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
