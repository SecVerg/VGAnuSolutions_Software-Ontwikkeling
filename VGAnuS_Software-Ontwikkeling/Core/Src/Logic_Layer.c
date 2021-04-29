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
	switch(CMD.type)​
    {​
		case LINE:​
			API_draw_line(CMD.x, CMD.y, CMD.x2, CMD.y2, CMD.kleur, CMD.dikte); ​
			break;

		case RECT:
			API_draw_rectangle(x_lup, y_lup, breedte, hoogte, kleur, gevuld);
			break;​

		case TEXT:
			API_draw_text(x, y, kleur, tekst, fontnaam, fontgrootte, fontstijl);
			break;

		case BITM:
			API_draw_bitmap(nr, x-lup, y-lup, smiley);
			break;

		case CLRS:
			API_clearscherm(kleur);
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

		case CRIC:
			return 100;
			break;

		case FIGU:
			return 100;
			break;

		default:
			return 100;
			break;
	}
  return 0;​
}
