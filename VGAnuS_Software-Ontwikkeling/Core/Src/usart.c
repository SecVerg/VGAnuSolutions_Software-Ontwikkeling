/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */

uint8_t RxRollover = 0;
uint8_t RxCounter = 0;
uint8_t RxBfrPos = 0;
uint8_t TxCounter = 0;
char UART2_txBuffer[TX_BUFSIZE];
uint8_t UART2_rxBuffer[RX_BUFSIZE];

/* USER CODE END 0 */

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 DMA Init */
    /* USART2_RX Init */
    hdma_usart2_rx.Instance = DMA1_Stream5;
    hdma_usart2_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_rx.Init.Mode = DMA_CIRCULAR;
    hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart2_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart2_rx);

    /* USART2_TX Init */
    hdma_usart2_tx.Instance = DMA1_Stream6;
    hdma_usart2_tx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_tx.Init.Mode = DMA_NORMAL;
    hdma_usart2_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart2_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart2_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart2_tx);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	// UART Rx Complete Callback;
	// Rx Complete is called by: DMA (automatically), if it rolls over
	// and when an IDLE Interrupt occurs
	// DMA Interrupt allays occurs BEFORE the idle interrupt can be fired because
	// idle detection needs at least one UART clock to detect the bus is idle. So
	// in the case, that the transmission length is one full buffer length
	// and the start buffer pointer is at 0, it will be also 0 at the end of the
	// transmission. In this case the DMA rollover will increment the RxRollover
	// variable first and len will not be zero.
	if(__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE)) {									// Check if it is an "Idle Interrupt"
		__HAL_UART_CLEAR_IDLEFLAG(&huart2);												// clear the interrupt
		RxCounter++;																	// increment the Rx Counter

		uint8_t TxSize = 0;
		uint16_t start = RxBfrPos;														// Rx bytes start position (=last buffer position)
		RxBfrPos = RX_BUFSIZE - (uint16_t)huart->hdmarx->Instance->NDTR;				// determine actual buffer position
		uint16_t len = RX_BUFSIZE;														// init len with max. size

		if(RxRollover < 2)  {
			if(RxRollover) {															// rolled over once
				if(RxBfrPos <= start) len = RxBfrPos + RX_BUFSIZE - start;				// no bytes overwritten
				else len = RX_BUFSIZE + 1;												// bytes overwritten error
			} else {
				len = RxBfrPos - start;													// no bytes overwritten
			}
		} else {
			len = RX_BUFSIZE + 2;														// dual rollover error
		}

		if(len && (len <= RX_BUFSIZE)) {
			// create response message
			#ifdef UART_DBG
				sprintf(UART2_txBuffer, "ACK RxC:%d S:%d L:%d RO:%d RXp:%d >>", RxCounter, start, len, RxRollover, RxBfrPos);

			#else
				sprintf(UART2_txBuffer, "U heeft ingevoerd:");
			#endif
			TxSize = strlen(UART2_txBuffer);

			// add received bytes to UART2_txBuffer
			uint8_t i;
			for(i = 0; i < len; i++) *(UART2_txBuffer + TxSize + i) = *(UART2_rxBuffer + ((start + i) % RX_BUFSIZE));
			TxSize += i;
		} else {
			// buffer overflow error:
			sprintf(UART2_txBuffer, "NAK RX BUFFER OVERFLOW ERROR %d\r\n", (len - RX_BUFSIZE));	// Change error message
			TxSize = strlen(UART2_txBuffer);
		}

		HAL_UART_Transmit_DMA(&huart2, (uint8_t*)UART2_txBuffer, TxSize);						// send a response

		RxRollover = 0;																	// reset the Rollover variable
	} else {
		// no idle flag? --> DMA rollover occurred
		RxRollover++;		// increment Rollover Counter
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	// UART Tx Complete Callback;
	TxCounter++;
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
