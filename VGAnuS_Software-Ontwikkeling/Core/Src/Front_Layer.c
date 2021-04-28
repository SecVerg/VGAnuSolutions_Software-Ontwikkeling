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
	char woorden[10][10];
	int i = 0;

	woord = strtok(buf, ",");	 //Find the first word in the sentence which is seperated via the delimiter ","
	sprintf(woorden[i], woord);

	while(woord != NULL){					 //Find all the other words with the delimiter "," between them
		sprintf(woorden[i], woord);
		i++;
		woord = strtok(NULL, ",");
		//printf("%s\n", woord);			 //print each word
	}

	for (i = 0; i < 10; i++)
	{
		HAL_UART_Transmit_DMA(&huart2, (uint8_t*)woorden[i], strlen(woorden[i]));						// send a response
	}

}
