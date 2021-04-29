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
	VGA_Command CMD;

	token = strtok(buf, ",");	 //Find the first word in the sentence which is seperated via the delimiter ","
	sprintf(tokens[i], token);

	while(token != NULL){					 //Find all the other words with the delimiter "," between them
		sprintf(tokens[i], token);
		i++;

		token = strtok(NULL, ",");
	}

	if(strcmp(tokens[0], "lijn") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"lijn command", 12);

		CMD.CMD_Type = LINE;
	}
	else if(strcmp(tokens[0], "rechthoek") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"rechthoek command", 17);
		CMD.CMD_Type = RECT;
	}
	else if(strcmp(tokens[0], "tekst") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"tekst command", 13);
		CMD.CMD_Type = TEXT;
	}
	else if(strcmp(tokens[0], "bitmap") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"bitmap command", 14);
		CMD.CMD_Type = BITM;
	}
	else if(strcmp(tokens[0], "clearscherm") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"clearscherm command", 19);
		CMD.CMD_Type = CLRS;
	}

	else if(strcmp(tokens[0], "wacht") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"wacht command", 13);
		CMD.CMD_Type = WAIT;
	}
	else if(strcmp(tokens[0], "cirkel") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"cirkel command", 14);
		CMD.CMD_Type = CIRC;
	}
	else if(strcmp(tokens[0], "figuur") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"figuur command", 14);
		CMD.CMD_Type = FIGU;
	}
	else
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"Command nvt", 11);
	}
}
