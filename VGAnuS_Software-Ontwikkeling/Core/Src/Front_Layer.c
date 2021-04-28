/*
 * Front_Layer.c
 *
 *  Created on: 22 Apr 2021
 *      Author: secve
 */
<<<<<<< Updated upstream
=======
#include "main.h"
>>>>>>> Stashed changes


<<<<<<< Updated upstream
=======
	char splitUp[100] = UART2_txBuffer;  //Array in which the sentence is placed

	char *woord = strtok(splitUp, ",");	 //Find the first word in the sentence which is seperated via the delimiter ","

	while(woord != 0){					 //Find all the other words with the delimiter "," between them
		woord = strtok(0, ",");
		printf("%s\n", woord);			 //print each word
	}
}
>>>>>>> Stashed changes
