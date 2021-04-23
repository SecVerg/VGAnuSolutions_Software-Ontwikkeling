/*
 * Logic_Layer.c
 *
 *  Created on: 23 apr. 2021
 *      Author: Maarten
 */



// Functie die nog niet ondersteund worden of niet herkend worden geven error 100
// Functie die het commando gebruikt om de juiste I/O layer functies aan te sturen
int LL_exec_command()
{
	switch(type)​
    {​
	       case lijn:​
	       	   API_draw_line(x, y, x2, y2, kleur, dikte); //roept I/O layer aan​
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
