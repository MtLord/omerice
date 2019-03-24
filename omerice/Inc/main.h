/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define direE_Pin GPIO_PIN_4
#define direE_GPIO_Port GPIOC
#define direF_Pin GPIO_PIN_5
#define direF_GPIO_Port GPIOC
#define PS2_CS_Pin GPIO_PIN_2
#define PS2_CS_GPIO_Port GPIOB
#define direA_Pin GPIO_PIN_12
#define direA_GPIO_Port GPIOB
#define direB_Pin GPIO_PIN_13
#define direB_GPIO_Port GPIOB
#define motorE_pwm_Pin GPIO_PIN_14
#define motorE_pwm_GPIO_Port GPIOB
#define motorF_pwm_Pin GPIO_PIN_15
#define motorF_pwm_GPIO_Port GPIOB
#define direC_Pin GPIO_PIN_8
#define direC_GPIO_Port GPIOC
#define direD_Pin GPIO_PIN_9
#define direD_GPIO_Port GPIOC
#define motorA_pwm_Pin GPIO_PIN_8
#define motorA_pwm_GPIO_Port GPIOA
#define motorB_pwm_Pin GPIO_PIN_9
#define motorB_pwm_GPIO_Port GPIOA
#define motorC_pwm_Pin GPIO_PIN_10
#define motorC_pwm_GPIO_Port GPIOA
#define motorD_pwm_Pin GPIO_PIN_11
#define motorD_pwm_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define gyro_cs_Pin GPIO_PIN_15
#define gyro_cs_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
