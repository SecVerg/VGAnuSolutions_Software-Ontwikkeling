/*
 * Logic_Layer.c
 *
 *  Created on: 23 apr. 2021
 *      Author: Maarten
 */



// Functions not yet supported return error 100
// This function uses the given command to execute the correct functions in the I/O layer
int LL_exec_command()
{
	switch(VGA_Command.type)​
    {​
	       case lijn:​
	       	   API_draw_line(VGA_Command.x, VGA_Command.y, VGA_Command.x2, VGA_Command.y2, VGA_Command.kleur, VGA_Command.dikte); ​
	       break;

	       case rechthoek:
	    	   API_draw_rectangle(x_lup, y_lup, breedte, hoogte, kleur, gevuld);
	       break;​

	       case tekst:
	    	   API_draw_text(x, y, kleur, tekst, fontnaam, fontgrootte, fontstijl);
	       break;

	       case bitmap:
	    	   API_draw_bitmap(nr, x-lup, y-lup, smiley);
		   break;

	       case clearscherm:
	    	   API_clearscherm(kleur);
	       break;

	       // Bonus command types :
	       case wacht:
	    	   return 100;
	       break;

	       case herhaal:
	    	   return 100;
	       break;

	       case execute:
	    	   return 100;
	       break;

	       case cirkel:
	    	   return 100;
	       break;

	       case figuur:
	    	   return 100;
	       break;

	       default:
		   	   return 100;
		   break;
	     }
  return 0;​
}
