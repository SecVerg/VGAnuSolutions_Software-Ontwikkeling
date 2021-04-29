/*
 * Front_Layer.c
 *
 *  Created on: 22 Apr 2021
 *      Author: secve
 */

#include "main.h"
#include "stdlib.h"
int FL_Color_Parse();

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
		CMD.X_pos = (uint16_t)atoi(tokens[1]);
		CMD.Y_pos = (uint8_t)atoi(tokens[2]);
		CMD.X_sec_pos = (uint16_t)atoi(tokens[3]);
		CMD.Y_sec_pos = (uint8_t)atoi(tokens[4]);

		uint16_t color = FL_Color_Parse(tokens[5]);
		CMD.Color = color;
		CMD.thickness = (uint8_t)atoi(tokens[6]);

	}
	else if(strcmp(tokens[0], "rechthoek") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"rechthoek command", 17);
		CMD.CMD_Type = RECT;

		CMD.X_pos = (uint16_t)atoi(tokens[1]);
		CMD.Y_pos = (uint8_t)atoi(tokens[2]);
		CMD.Width = (uint16_t)atoi(tokens[3]);
		CMD.Height = (uint8_t)atoi(tokens[4]);

		uint16_t color = FL_Color_Parse(tokens[5]);
		CMD.Color = color;
		CMD.Filled = (uint8_t)atoi(tokens[6]);

	}
	else if(strcmp(tokens[0], "tekst") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"tekst command", 13);
		CMD.CMD_Type = TEXT;
		CMD.X_pos = (uint16_t)atoi(tokens[1]);
		CMD.Y_pos = (uint8_t)atoi(tokens[2]);
		uint16_t color = FL_Color_Parse(tokens[3]);
		CMD.Color = color;
		CMD.Text = tokens[4];
		CMD.Font = tokens[5];
		CMD.Fontsize = (uint8_t)atoi(tokens[6]);
		CMD.Fontstyle = tokens[7];
	}
	else if(strcmp(tokens[0], "bitmap") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"bitmap command", 14);
		CMD.CMD_Type = BITM;
		CMD.number = (uint8_t) atoi(tokens[1]);
		CMD.X_pos = (uint16_t) atoi(tokens[2]);
		CMD.Y_pos = (uint8_t) atoi(tokens[3]);

	}
	else if(strcmp(tokens[0], "clearscherm") == 0)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"clearscherm command", 19);
		CMD.CMD_Type = CLRS;
		uint16_t color = FL_Color_Parse(tokens[1]);
		CMD.Color = color;
		//CMD.Color = tokens[1];
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

int FL_Color_Parse(char *text)
{
	uint16_t res = 0;

	if(strcmp(text, "zwart") == 0)
	{
		res = VGA_COL_BLACK;
	}

	else if(strcmp(text, "blauw") == 0)
	{
		res = VGA_COL_BLUE;
	}

	else if(strcmp(text, "groen") == 0)
	{
		res = VGA_COL_GREEN;
	}

	else if(strcmp(text, "rood") == 0)
	{
		res = VGA_COL_RED;
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

	else if(strcmp(text, "geel") == 0)
	{
		res = VGA_COL_YELLOW;
	}

	return res;

}

