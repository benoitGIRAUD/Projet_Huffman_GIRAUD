
 /*============================== ESET 2021-2022 ================================
**File Name   :  main.h                                                         **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description : Header file of main.c                                           **
=================================================================================*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif
  /*=============================================================================
  **                               Includes                                     **
  ==============================================================================*/
#include "Struct.h"
#include "stm32f4xx_hal.h"
#include "Occurrence.h"
#include "Struct.h"
#include "ArbreHuffman.h"
#include "Compressiontexte.h"
#include "EnteteHuffman.h"





/* Includes ------------------------------------------------------------------*/





/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/*

*/

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

/*==============================================================================
**                             Local Defines                                    **
================================================================================*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

#define MAX_ARRAY 256

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
