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
	char tokens[TOK_AMT][TOK_LEN]; 			// 2d token buffer
	pTokenType* pToken = tokens;   			// Pointer to first index of 2d token buffer

	token = strtok(buf, ",");	 			// Find the first word in the sentence which is seperated via the delimiter ","
	sprintf(*pToken, token);
	pToken++;								// Move pointer to next char array

	while(token != NULL){					// Find all the other words with the delimiter "," between them
		token = strtok(NULL, ",");
		sprintf(*pToken, token);
		pToken++;
	}

	pToken = tokens;						// Reset pointer to first index

	// Compare first index of buffer with the command types
	// If they are the same, fill VGA_Command struct with the arguments
	if(strcmp(*pToken, "lijn") == 0)
	{
		pToken++;
		HAL_UART_Transmit(&huart2, (uint8_t *)"lijn command\n", 13, 10);
		CMD.CMD_Type = LINE;
		CMD.X_pos = (uint16_t)strtopos(*pToken++);
		CMD.Y_pos = (uint8_t)strtopos(*pToken++);
		CMD.X_sec_pos = (uint16_t)strtopos(*pToken++);
		CMD.Y_sec_pos = (uint8_t)strtopos(*pToken++);
		CMD.Color = FL_Color_Parse(*pToken++);
		CMD.Thickness = (uint8_t)atoi(*pToken);
	}
	else if(strcmp(*pToken, "rechthoek") == 0)
	{
		pToken++;
		HAL_UART_Transmit(&huart2, (uint8_t *)"rechthoek command\n", 18, 10);
		CMD.CMD_Type = RECT;
		CMD.X_pos = (uint16_t)strtopos(*pToken++);
		CMD.Y_pos = (uint8_t)strtopos(*pToken++);
		CMD.Width = (uint16_t)atoi(*pToken++);
		CMD.Height = (uint8_t)atoi(*pToken++);
		CMD.Color = FL_Color_Parse(*pToken++);
		CMD.Filled = (uint8_t)atoi(*pToken);
	}
	else if(strcmp(*pToken, "tekst") == 0)
	{
		pToken++;
		HAL_UART_Transmit(&huart2, (uint8_t *)"tekst command\n", 14, 10);
		CMD.CMD_Type = TEXT;
		CMD.X_pos = (uint16_t)strtopos(*pToken++);
		CMD.Y_pos = (uint8_t)strtopos(*pToken++);
		CMD.Color = FL_Color_Parse(*pToken++);
		CMD.Text = *pToken++;
		CMD.Font = *pToken++;
		CMD.Fontsize = (uint8_t)atoi(*pToken++);
		CMD.Fontstyle = *pToken;
	}
	else if(strcmp(*pToken, "bitmap") == 0)
	{
		pToken++;
		HAL_UART_Transmit(&huart2, (uint8_t *)"bitmap command\n", 15, 10);
		CMD.CMD_Type = BITM;
		CMD.Number = (uint8_t) atoi(*pToken++);
		CMD.X_pos = (uint8_t) strtopos(*pToken++);
		CMD.Y_pos = (uint8_t) strtopos(*pToken);
	}
	else if(strcmp(*pToken, "clearscherm") == 0)
	{
		pToken++;
		HAL_UART_Transmit(&huart2, (uint8_t *)"clearscherm command\n", 20, 10);
		CMD.CMD_Type = CLRS;
		CMD.Color = FL_Color_Parse(*pToken++);
	}
	else if(strcmp(*pToken, "wacht") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"wacht command\n", 14, 10);
		CMD.CMD_Type = WAIT;
	}
	else if(strcmp(*pToken, "herhaal") == 0)									//BONUS COMMAND
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"herhaal command\n", 16, 10);
		CMD.CMD_Type = REPT;
	}
	else if(strcmp(*pToken, "cirkel") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"cirkel command\n", 15, 10);
		CMD.CMD_Type = CIRC;
	}
	else if(strcmp(*pToken, "figuur") == 0)										//BONUS COMMAND
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"figuur command\n", 15, 10);
		CMD.CMD_Type = FIGU;
	}
	else
	{
		return ERR_PARSE;
	}

	if(CMD.Color == ERR_COLOR)
		return ERR_COLOR;

	if (CMD.X_pos == ERR_OOR || CMD.X_sec_pos == ERR_OOR ||
		CMD.Y_pos == ERR_OOR || CMD.Y_sec_pos == ERR_OOR)
		return ERR_OOR;

	// Send command struct to Logic Layer for further processing
	return LL_exec_command(CMD);
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
	else if(strcmp(text, "bruin") == 0)
	{
		res = VGA_COL_BROWN;
	}
	else if(strcmp(text, "grijs") == 0)
	{
		res = VGA_COL_GREY;
	}
	else
	{
		return res = ERR_COLOR;
	}

	return res;
}

void FL_Write_Error(int err)
{
	char err_msg[MAX_ERRMSG_SIZE];

	switch(err)
	{
		case ERR_PARSE || ERR_EXEC:
			sprintf(err_msg, "Er is iets mis gegaan:\nError no.%d, command niet herkend.\n", err);
			HAL_UART_Transmit(&huart2, (uint8_t *)err_msg, strlen(err_msg), 10);
			break;
		case ERR_COLOR:
			sprintf(err_msg, "Er is iets mis gegaan:\nError no.%d, kleur niet herkend.\n", err);
			HAL_UART_Transmit(&huart2, (uint8_t *)err_msg, strlen(err_msg), 10);
			break;
		case ERR_EXEC_NYI:
			sprintf(err_msg, "Command nog niet geimplementeerd.\n");
			HAL_UART_Transmit(&huart2, (uint8_t *)err_msg, strlen(err_msg), 10);
			break;
		case ERR_EXEC_UNK:
			sprintf(err_msg, "Er is iets mis gegaan:\nError no.%d, commandfout.\n", err);
			HAL_UART_Transmit(&huart2, (uint8_t *)err_msg, strlen(err_msg), 10);
			break;
		case ERR_OOR:
			sprintf(err_msg, "Er is iets mis gegaan:\nError no.%d, x en/of y posities buiten beeld.\n", err);
			HAL_UART_Transmit(&huart2, (uint8_t *)err_msg, strlen(err_msg), 10);
			break;
	}
}


// A simple atoi() function
int strtopos(char* str)
{
    // Initialize result
    int res = 0;

    if (str[0] == '-'){
    	return ERR_OOR;
    }

    // Iterate through all characters
    // of input string and update result
    // take ASCII character of corosponding digit and
    // subtract the code from '0' to get numerical
    // value and multiply res by 10 to shuffle
    // digits left to update running total
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    if(res > 320)
    	return ERR_OOR;

    // return result.
    return res;
}
