/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "dts.h"
#include "flash.h"
#include "gpio.h"
#include "memorymap.h"
#include "sbs.h"
#include "usart.h"
#include "xspi.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
 * @brief  This function jumps to the application through its vector table
 * @return @ref BOOTStatus_TypeDef
 */
void JumpToApplication(void)
{
    uint32_t primask_bit;
    typedef void (*pFunction)(void);
    static pFunction JumpToApp;
    uint32_t Application_vector;

    /* Suspend SysTick */
    HAL_SuspendTick();

    /* if I-Cache is enabled, disable I-Cache-----------------------------------*/
    if (SCB->CCR & SCB_CCR_IC_Msk)
    {
        SCB_DisableICache();
    }

    /* if D-Cache is enabled, disable D-Cache-----------------------------------*/
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_DisableDCache();
    }

    /* Initialize user application's Stack Pointer & Jump to user application  */
    primask_bit = __get_PRIMASK();
    __disable_irq();

    /* Apply offsets for image location and vector table offset */
    Application_vector = 0x70000000UL;

    SCB->VTOR = (uint32_t)Application_vector;
    JumpToApp = (pFunction)(*(__IO uint32_t *)(Application_vector + 4u));

    __set_MSP(*(__IO uint32_t *)Application_vector);

    /* Re-enable the interrupts */
    __set_PRIMASK(primask_bit);

    JumpToApp();
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MPU Configuration--------------------------------------------------------*/
    MPU_Config();

    /* Enable the CPU Cache */

    /* Enable I-Cache---------------------------------------------------------*/
    SCB_EnableICache();

    /* Enable D-Cache---------------------------------------------------------*/
    SCB_EnableDCache();

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */
    MX_FLASH_Init();
    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_SBS_Init();
    MX_XSPI2_Init();
    MX_XSPI1_Init();
    MX_UART4_Init();
    MX_DTS_Init();
    MX_ADC1_Init();
    MX_FLASH_Init();
    /* USER CODE BEGIN 2 */
    EXTMEM_Flash_Probe();
    EXTMEM_Flash_EnterXIP();
    EXTMEM_PSRAM_Probe();
    EXTMEM_PSRAM_EnterXIP();
    JumpToApplication();
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
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

    /** Configure the main internal regulator output voltage
     */
    if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE0) != HAL_OK)
    {
        Error_Handler();
    }

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL1.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL1.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL1.PLLM = 12;
    RCC_OscInitStruct.PLL1.PLLN = 300;
    RCC_OscInitStruct.PLL1.PLLP = 1;
    RCC_OscInitStruct.PLL1.PLLQ = 2;
    RCC_OscInitStruct.PLL1.PLLR = 2;
    RCC_OscInitStruct.PLL1.PLLS = 2;
    RCC_OscInitStruct.PLL1.PLLT = 2;
    RCC_OscInitStruct.PLL1.PLLFractional = 0;
    RCC_OscInitStruct.PLL2.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL2.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL2.PLLM = 4;
    RCC_OscInitStruct.PLL2.PLLN = 83;
    RCC_OscInitStruct.PLL2.PLLP = 2;
    RCC_OscInitStruct.PLL2.PLLQ = 2;
    RCC_OscInitStruct.PLL2.PLLR = 2;
    RCC_OscInitStruct.PLL2.PLLS = 3;
    RCC_OscInitStruct.PLL2.PLLT = 3;
    RCC_OscInitStruct.PLL2.PLLFractional = 0;
    RCC_OscInitStruct.PLL3.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 |
                                  RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK4 | RCC_CLOCKTYPE_PCLK5;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
    RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
    RCC_ClkInitStruct.APB5CLKDivider = RCC_APB5_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */
/* ------------------redirect printf to uart-------------------*/
#if !defined(__MICROLIB)
#if defined(__GNUC__) || defined(__clang__)
__asm(".global __use_no_semihosting\n\t");
#elif defined(__CC_ARM)
#pragma import(__use_no_semihosting)
#endif

void _sys_exit(int x)
{
    UNUSED(x);
}

void _ttywrch(int ch) //__use_no_semihosting was requested, _ttywrch was
{
    UNUSED(ch);
}

FILE __stdout; // comment this code in GNU environment
#endif

#if defined(__GNUC__) && !defined(__clang__)
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart4, (uint8_t *)&ch, 1, 1000);
    return ch;
}
/* USER CODE END 4 */

/* MPU Configuration */

static void MPU_Config(void)
{
    MPU_Region_InitTypeDef MPU_InitStruct = {0};

    /* Disables the MPU */
    HAL_MPU_Disable();

    /** Initializes and configures the Region and the memory to be protected
     */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER0;
    MPU_InitStruct.BaseAddress = 0x0;
    MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
    MPU_InitStruct.SubRegionDisable = 0x87;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
    MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    /** Initializes and configures the Region and the memory to be protected
     */
    MPU_InitStruct.Number = MPU_REGION_NUMBER1;
    MPU_InitStruct.BaseAddress = 0x90000000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
    MPU_InitStruct.SubRegionDisable = 0x0;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    /** Initializes and configures the Region and the memory to be protected
     */
    MPU_InitStruct.Number = MPU_REGION_NUMBER2;
    MPU_InitStruct.BaseAddress = 0x70000000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_128MB;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);
    /* Enables the MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

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

#ifdef USE_FULL_ASSERT
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
