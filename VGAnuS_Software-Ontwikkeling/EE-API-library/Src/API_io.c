/**-----------------------------------------------------------
 * @file API_io.c
 *
 *  Created on: 29 Apr 2021
 *    @authors: secve, Maarten van Dijk, Christiaan Meerkerk
 */

#include "API_io.h"

/**-----------------------------------------------------------
* @brief API init function:
* Initializes the VGA timers for displaying on a screen with
* the connector. Fills the screen with white color.
* @param[in] 	None
* @retval		None
*/
void API_init_IO(void)
{
	// Initialize VGA screen timers/registers
	UB_VGA_Screen_Init();

	// Fill the screen with white
	UB_VGA_FillScreen(VGA_COL_WHITE);
}
