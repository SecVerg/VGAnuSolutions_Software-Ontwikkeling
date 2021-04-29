/*
 * Logic_Layer.c
 *
 *  Created on: 23 apr. 2021
 *      Author: Maarten
 */
#include "Front_Layer.h"
#include "Logic_Layer.h"

// Functions not yet supported return error 100
// This function uses the given command to execute the correct functions in the I/O layer
int LL_exec_command(VGA_Command CMD)
{
	switch(CMD.CMD_Type)
	{
		case LINE:
			API_draw_line(CMD.X_pos, CMD.Y_pos, CMD.X_sec_pos, CMD.Y_sec_pos, CMD.Color, CMD.Thickness);
			break;

		case RECT:
			API_draw_rectangle(CMD.X_pos, CMD.Y_pos, CMD.Width, CMD.Height, CMD.Color, CMD.Filled);
			break;

		case TEXT:
			//API_draw_text(CMD.X_pos, CMD.Y_pos, CMD.Color, CMD.Text, CMD.Font, CMD.Fontsize, CMD.Fontstyle);
			break;

		case BITM:
			//API_draw_bitmap(CMD.Number, CMD.X_pos, CMD.Y_pos);
			break;

		case CLRS:
			//API_clearscherm(CMD.Color);
			break;

		// Bonus command types :
		case WAIT:
			return 100;
			break;

		case REPT:
			return 100;
			break;

		case EXEC:
			return 100;
			break;

		case CIRC:
			return 100;
			break;

		case FIGU:
			return 100;
			break;

		default:
			return 100;
			break;
	}
	return 0;
}
