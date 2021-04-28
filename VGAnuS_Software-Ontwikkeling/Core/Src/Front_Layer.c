/*
 * Front_Layer.c
 *
 *  Created on: 22 Apr 2021
 *      Author: secve
 */

#include "main.h"

void FL_Parse(char *buf)
{
	char *woord;
	char woorden[10][10];
	int i = 0;
	VGA_Command cmd;

	woord = strtok(buf, ",");	 //Find the first word in the sentence which is seperated via the delimiter ","
	sprintf(woorden[i], woord);

	while(woord != NULL){					 //Find all the other words with the delimiter "," between them
		sprintf(woorden[i], woord);
		i++;

		woord = strtok(NULL, ",");
	}

	if(strcmp(woorden[0], "lijn") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"lijn command", 12);

		cmd->CMD_Type = LINE;
	}
	else if(strcmp(woorden[0], "rechthoek") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"rechthoek command", 12);
	}
	else if(strcmp(woorden[0], "tekst") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"tekst command", 12);
	}
	else if(strcmp(woorden[0], "bitmap") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"bitmap command", 12);
	}
	else if(strcmp(woorden[0], "clearscherm") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"clearscherm command", 12);
	}
	else
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"Command nvt", 11);
	}
}
