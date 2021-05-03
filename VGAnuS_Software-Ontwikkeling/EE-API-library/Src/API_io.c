/*
 * API_io.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */

#include "API.h"

void API_init_IO(void)
{
	// Initialize VGA screen timers/registers
	UB_VGA_Screen_Init();

	// Fill the screen with white
	UB_VGA_FillScreen(VGA_COL_WHITE);
}

//bitmap arrays
byte numberArray[][7] = {
	// happy smiley
	{
		0b0011111000,
		0b0100000100,
		0b1000000010,
		0b1010001010,
		0b1000000010,
		0b1010001010,
		0b1001110010,
		0b0100000100,
		0b0011111000,
	},
	// sad smiley
	{
		0b0011111000,
		0b0100000100,
		0b1000000010,
		0b1010001010,
		0b1000000010,
		0b1001110010,
		0b1010001010,
		0b0100000100,
		0b0011111000,
	},
};
