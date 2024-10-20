/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
#define Select_Mode_Pin GPIO_PIN_1
#define Select_Mode_GPIO_Port GPIOA
#define Modify_Mode_Pin GPIO_PIN_2
#define Modify_Mode_GPIO_Port GPIOA
#define Set_Value_Pin GPIO_PIN_3
#define Set_Value_GPIO_Port GPIOA
#define LED_RED_X1_Pin GPIO_PIN_4
#define LED_RED_X1_GPIO_Port GPIOA
#define LED_YELLOW_X1_Pin GPIO_PIN_5
#define LED_YELLOW_X1_GPIO_Port GPIOA
#define LED_GREEN_X1_Pin GPIO_PIN_6
#define LED_GREEN_X1_GPIO_Port GPIOA
#define LED_RED_Y2_Pin GPIO_PIN_7
#define LED_RED_Y2_GPIO_Port GPIOA
#define SEG0_Pin GPIO_PIN_0
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_1
#define SEG1_GPIO_Port GPIOB
#define SEG2_Pin GPIO_PIN_2
#define SEG2_GPIO_Port GPIOB
#define LED_GREEN_Y2_Pin GPIO_PIN_8
#define LED_GREEN_Y2_GPIO_Port GPIOA
#define LED_GREEN_Y2A9_Pin GPIO_PIN_9
#define LED_GREEN_Y2A9_GPIO_Port GPIOA
#define Light_Y1_Pin GPIO_PIN_10
#define Light_Y1_GPIO_Port GPIOA
#define Light_Y2_Pin GPIO_PIN_11
#define Light_Y2_GPIO_Port GPIOA
#define Light_X1_Pin GPIO_PIN_12
#define Light_X1_GPIO_Port GPIOA
#define Light_X2_Pin GPIO_PIN_13
#define Light_X2_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_3
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_4
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_5
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_6
#define SEG6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
