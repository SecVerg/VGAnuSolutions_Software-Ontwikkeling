/*
 * Front_Layer.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */

#include "Front_Layer.h"

int FL_Parse(char *buf)
{
	char *token = '\0';
	VGA_Command CMD = {0};
	char tokens[TOK_AMT][TOK_LEN];
	pTokenType* pToken = tokens;

	for (int i = 0; i < TOK_AMT; i++)
	{
		for (int j = 0; j < TOK_LEN; j++)
		{
			tokens[i][j] = '\0';
		}
	}

	token = strtok(buf, ",");	 			//Find the first word in the sentence which is seperated via the delimiter ","
	sprintf(*pToken, token);
	pToken++;

	while(token != NULL){					//Find all the other words with the delimiter "," between them
		token = strtok(NULL, ",");
		sprintf(*pToken, token);
		pToken++;
	}

	pToken = tokens;

	if(strcmp(*pToken, "lijn") == 0)
	{
		pToken++;
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"lijn command", 12);
		CMD.CMD_Type = LINE;
		CMD.X_pos = (uint16_t)atoi(*pToken++);
		CMD.Y_pos = (uint8_t)atoi(*pToken++);
		CMD.X_sec_pos = (uint16_t)atoi(*pToken++);
		CMD.Y_sec_pos = (uint8_t)atoi(*pToken++);
		CMD.Color = FL_Color_Parse(*pToken++);
		CMD.Thickness = (uint8_t)atoi(*pToken);
	}
	else if(strcmp(*pToken, "rechthoek") == 0)
	{
		pToken++;
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"rechthoek command", 17);
		CMD.CMD_Type = RECT;
		CMD.X_pos = (uint16_t)atoi(*pToken++);
		CMD.Y_pos = (uint8_t)atoi(*pToken++);
		CMD.Width = (uint16_t)atoi(*pToken++);
		CMD.Height = (uint8_t)atoi(*pToken++);
		CMD.Color = FL_Color_Parse(*pToken++);
		CMD.Filled = (uint8_t)atoi(*pToken);

	}
	else if(strcmp(*pToken, "tekst") == 0)
	{
		pToken++;
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"tekst command", 13);
		CMD.CMD_Type = TEXT;
		CMD.X_pos = (uint16_t)atoi(*pToken++);
		CMD.Y_pos = (uint8_t)atoi(*pToken++);
		CMD.Color = FL_Color_Parse(*pToken++);
		CMD.Text = *pToken++;
		CMD.Font = *pToken++;
		CMD.Fontsize = (uint8_t)atoi(*pToken++);
		CMD.Fontstyle = *pToken;
	}
	else if(strcmp(*pToken, "bitmap") == 0)
	{
		pToken++;
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"bitmap command", 14);
		CMD.CMD_Type = BITM;
		CMD.Number = (uint8_t) atoi(*pToken++);
		CMD.X_pos = (uint8_t) atoi(*pToken++);
		CMD.Y_pos = (uint8_t) atoi(*pToken);

	}
	else if(strcmp(*pToken, "clearscherm") == 0)
	{
		pToken++;
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"clearscherm command", 19);
		CMD.CMD_Type = CLRS;
		CMD.Color = FL_Color_Parse(*pToken);
	}

	else if(strcmp(*pToken, "wacht") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"wacht command\n", 13);
		CMD.CMD_Type = WAIT;
	}
	else if(strcmp(*pToken, "cirkel") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"cirkel command\n", 14);
		CMD.CMD_Type = CIRC;
	}
	else if(strcmp(*pToken, "figuur") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"figuur command\n", 14);
		CMD.CMD_Type = FIGU;
	}
	else
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"Command nvt\n", 11);
	}


	LL_exec_command(CMD);

	return 0;
}

uint8_t FL_Color_Parse(char *text)
{
	uint8_t res = 0;

	if(strcmp(text, "zwart") == 0)
	{
		res = VGA_COL_BLACK;
	}
	else if(strcmp(text, "blauw") == 0)
	{
		res = VGA_COL_BLUE;
	}
	else if(strcmp(text, "lichtblauw") == 0)
	{
		res = VGA_COL_LIGHTBLUE;
	}
	else if(strcmp(text, "groen") == 0)
	{
		res = VGA_COL_GREEN;
	}
	else if(strcmp(text, "lichtgroen") == 0)
	{
		res = VGA_COL_LIGHTGREEN;
	}
	else if(strcmp(text, "rood") == 0)
	{
		res = VGA_COL_RED;
	}
	else if(strcmp(text, "lichtrood") == 0)
	{
		res = VGA_COL_LIGHTRED;
	}
	else if(strcmp(text, "wit") == 0)
	{
		res = VGA_COL_WHITE;
	}
	else if(strcmp(text, "cyaan") == 0)
	{
		res = VGA_COL_CYAN;
	}
	else if(strcmp(text, "magenta") == 0)
	{
		res = VGA_COL_MAGENTA;
	}
	else if(strcmp(text, "lichtmagenta") == 0)
	{
		res = VGA_COL_LIGHTMAGENTA;
	}
	else if(strcmp(text, "geel") == 0)
	{
		res = VGA_COL_YELLOW;
	}

	return res;
}
