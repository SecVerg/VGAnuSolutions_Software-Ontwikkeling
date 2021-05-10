/**
 * @file Logic_Layer.c
 * @brief Logic Layer functions as mediator between Front_Layer and I/O_Layer
 *  Created on: 23 apr. 2021
 *    @authors: Maarten van Dijk, Christiaan Meerkerk, Stijn Vergouwen
 */

#include "Logic_Layer.h"

/**
 * @brief Command execution:
 * Uses the command struct to execute the correct functions in the I/O layer.
 * @param[in] VGA_Command CMD
 * 			The given command is struct VGA_Command located in main.h
 *
 * @retval Functions not yet supported return ERR_EXEC_NYI (Not Yet Implemented)
 * @retval Error codes from API functions are also returned
*/
int LL_exec_command(VGA_Command CMD)
{
	switch(CMD.CMD_Type)
	{
		case LINE:
			return API_Draw_Line(CMD.X_pos, CMD.Y_pos, CMD.X_sec_pos, CMD.Y_sec_pos, CMD.Color, CMD.Thickness);

		case RECT:
			return API_Draw_Rectangle(CMD.X_pos, CMD.Y_pos, CMD.Width, CMD.Height, CMD.Color, CMD.Filled);

		case TEXT:
			return API_Draw_Text(CMD.X_pos, CMD.Y_pos, CMD.Color, CMD.Text, CMD.Font, CMD.Fontsize, CMD.Fontstyle);

		case BITM:
			return API_Draw_Bitmap(CMD.Number, CMD.X_pos, CMD.Y_pos);

		case CLRS:
			API_Draw_Clearscreen(CMD.Color);
			return 0;

		// Bonus command types :
		case WAIT:
			return ERR_EXEC_NYI;

		case REPT:
			return ERR_EXEC_NYI;

		case CIRC:
			return API_Draw_Circle(CMD.X_pos, CMD.Y_pos, CMD.Radius, CMD.Color);

		case FIGU:
			return ERR_EXEC_NYI;

		default:
			return ERR_EXEC;
	}
	return ERR_EXEC_UNK;
}
