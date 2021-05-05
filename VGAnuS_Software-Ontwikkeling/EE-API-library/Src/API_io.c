/*
 * API_io.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve, Maarten van Dijk, Christiaan Meerkerk
 */

#include "API_io.h"

//-----------------------------------------------------------
// Draw line function
// Arguments:
// void
// ----------------------------------------------------------
void API_init_IO(void)
{
	// Initialize VGA screen timers/registers
	UB_VGA_Screen_Init();

	// Fill the screen with white
	UB_VGA_FillScreen(VGA_COL_WHITE);
}
