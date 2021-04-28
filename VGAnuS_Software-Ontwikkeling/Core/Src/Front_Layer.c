/*
 * Front_Layer.c
 *
 *  Created on: 22 Apr 2021
 *      Author: secve
 */

#include "main.h"

void FL_Parse(char *buf)
{
	//char splitUp[100] = buf;  //Array in which the sentence is placed
	char *woord;

	woord = strtok(buf, ",");	 //Find the first word in the sentence which is seperated via the delimiter ","

	while(woord != NULL){					 //Find all the other words with the delimiter "," between them
		HAL_UART_Transmit_DMA(&huart2, (uint8_t*)woord, strlen(woord));						// send a response
		woord = strtok(NULL, ",");
		//printf("%s\n", woord);			 //print each word
	}
}
