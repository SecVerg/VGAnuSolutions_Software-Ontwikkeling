/*
 * Front_Layer.c
 *
 *  Created on: 22 Apr 2021
 *      Author: secve
 */

#include "main.h"

void FL_Parse(char *buf)
{
	char *token;
	char tokens[10][10];
	int i = 0;
	VGA_Command cmd;

	woord = strtok(buf, ",");	 //Find the first word in the sentence which is seperated via the delimiter ","
	sprintf(tokens[i], token);

	while(woord != NULL){					 //Find all the other words with the delimiter "," between them
		sprintf(tokens[i], token);
		i++;

		token = strtok(NULL, ",");
	}

	if(strcmp(tokens[0], "lijn") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"lijn command", 12);

	}
	else if(strcmp(woorden[0], "rechthoek") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"rechthoek command", 12);
		CMD->CMD_Type = RECT;
	}
	else if(strcmp(woorden[0], "tekst") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"tekst command", 12);
		CMD->CMD_Type = TEXT;
	}
	else if(strcmp(woorden[0], "bitmap") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"bitmap command", 12);
		CMD->CMD_Type = BITM;
	}
	else if(strcmp(woorden[0], "clearscherm") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"clearscherm command", 12);
		CMD->CMD_Type = CLRS;
	}

	else if(strcmp(woorden[0], "wacht") == 0)										//BONUS COMMAND
		{
			HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"wacht command", 12);
			CMD->CMD_Type = WAIT;
		}
	else if(strcmp(woorden[0], "cirkel") == 0)										//BONUS COMMAND
			{
				HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"cirkel command", 12);
				CMD->CMD_Type = CIRC;
			}
	else if(strcmp(woorden[0], "figuur") == 0)										//BONUS COMMAND
			{
				HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"figuur command", 12);
				CMD->CMD_Type = FIGU;
			}
	else
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"Command nvt", 11);

	}
}
