/*
 * Logic_Layer.c
 *
 *  Created on: 23 apr. 2021
 *      Author: Maarten
 */

#include "Logic_Layer.h"

// Functions not yet supported return error 100
// This function uses the given command to execute the correct functions in the I/O layer
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
			break;

		case BITM:
			return API_Draw_Bitmap(CMD.Number, CMD.X_pos, CMD.Y_pos);
			break;

		case CLRS:
			return API_Draw_Clearscreen(CMD.Color);

		// Bonus command types :
		case WAIT:
			return ERR_EXEC_NYI;

		case REPT:
			return ERR_EXEC_NYI;

		case EXEC:
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
