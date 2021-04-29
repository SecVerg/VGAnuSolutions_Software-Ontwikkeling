/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stdint.h"
#include "stm32_ub_vga_screen.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "API.h"
#include "usart.h"
#include "Front_Layer.h"
#include "Logic_Layer.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef struct
{
	uint8_t  CMD_Type;		// A specific Type value

	uint16_t X_pos;			//  X_LUP, The first X-axis positional value of the item
							// to be displayed on the screen

	uint8_t  Y_pos;		// Y_LUP, The first Y-axis positional value of the item
							// to be displayed on the screen

	uint16_t X_sec_pos;		// X'The second Y-axis positional value of the item
							// to be displayed on the screen

	uint8_t  Y_sec_pos;		// Y' The second Y-axis positional value of the item
							// to be displayed on the screen

	uint16_t Width;			// Width of the item to be displayed in the screen
							// in pixels

	uint8_t  Height;		// Height of the item to be displayed in the screen
							// in pixels

	uint8_t  Filled;		// 1 or 0 to specify if rectangle is filled with
							// color or not

	uint16_t Color;			// Specifies the color of the item to be
							// displayed on the screen

	uint8_t  Number;

	uint8_t  Thickness;

	char*	 Text;			// Text string to be displayed on the screen

	char*	 Font;			// Font of the text to be displayed on the screen
							// Arial or Consolas

	char*  	 Fontstyle;		// Fontstyle of the text to be displayed on the screen
							// Cursive, Bold or normal

	uint8_t  Fontsize;		// Fontsize of the text to be displayed on the screen
							// 1 or 2
} VGA_Command;

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
#define VGA_BLUE0_Pin GPIO_PIN_8
#define VGA_BLUE0_GPIO_Port GPIOE
#define VGA_BLUE1_Pin GPIO_PIN_9
#define VGA_BLUE1_GPIO_Port GPIOE
#define VGA_GREEN0_Pin GPIO_PIN_10
#define VGA_GREEN0_GPIO_Port GPIOE
#define VGA_GREEN1_Pin GPIO_PIN_11
#define VGA_GREEN1_GPIO_Port GPIOE
#define VGA_GREEN2_Pin GPIO_PIN_12
#define VGA_GREEN2_GPIO_Port GPIOE
#define VGA_RED0_Pin GPIO_PIN_13
#define VGA_RED0_GPIO_Port GPIOE
#define VGA_RED1_Pin GPIO_PIN_14
#define VGA_RED1_GPIO_Port GPIOE
#define VGA_RED2_Pin GPIO_PIN_15
#define VGA_RED2_GPIO_Port GPIOE
#define VGA_HSYNC_Pin GPIO_PIN_11
#define VGA_HSYNC_GPIO_Port GPIOB
#define VGA_VSYNC_Pin GPIO_PIN_12
#define VGA_VSYNC_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

#define LINE 0x1		//lijn
#define RECT 0x2		//Rechthoek
#define TEXT 0x3		//text
#define BITM 0x4		//Bitmap
#define CLRS 0x5		//Clearscreen
#define WAIT 0x6		//Wacht
#define REPT 0x7		//Herhaal
#define CIRC 0x8		//Cirkel
#define FIGU 0x9		//Figuur
#define EXEC 0xA		//Execute

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
