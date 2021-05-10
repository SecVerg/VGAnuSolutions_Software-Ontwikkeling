/**
 * API_draw.c
 * @brief API_draw contains all functions that directly write to the screen
 *  Created on: 29 Apr 2021
 *      Author: Stijn Vergouwen, Maarten van Dijk, Christiaan Meerkerk
 */
#include "API_draw.h"

/** ----------------------------------------------------------
// @brief Draw line function
// Arguments:
// @param[in] x1,y1,x2,x2 : coords of beginning and end of line
// @param[in] color : color of the line
// @param[in] thicc : thickness of the line
*/
int API_Draw_Line(uint16_t x1, uint8_t y1, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc)
{
int err = 0;
int dx,dy,sdx,sdy,px,py,dxabs,dyabs,i,k; //
float slope;

	dx = x2 - x1; /* the horizontal distance of the line */
	dy = y2 - y1; /* the vertical distance of the line */
	dxabs = abs(dx); //Negative values converterd to positive values
	dyabs = abs(dy);
	sdx = sgn(dx); //returns 1 if positive, 0 if 0 and -1 if less than 0
	sdy = sgn(dy); //returns 1 if positive, 0 if 0 and -1 if less than 0

	if (dxabs >= dyabs) /* the line is more horizontal than vertical */
	{
		slope = (float) dy / (float) dx; //determine slope(a)
		for (i = 0; i != dx; i += sdx) {
			px = i + x1;
			py = slope * i + y1;
			for (k = 0; k < thicc; k++)
				UB_VGA_SetPixel(px, py + k, color);
		}
	} else /* the line is more vertical than horizontal */
	{
		slope = (float) dx / (float) dy; //determine slope(a)
		for (i = 0; i != dy; i += sdy) {
			px = slope * i + x1;
			py = i + y1;
			for (k = 0; k < thicc; k++)
				UB_VGA_SetPixel(px + k, py, color);
		}
	}
	return err;
}

/**-----------------------------------------------------------
// @brief Draw rectangle function
// Arguments:
// @param[in] x1,y1 : coords of top left corner of rectangle
// @param[in] width : width of the rectangle in pixels
// @param[in] height: height of the rectangle in pixels
// @param[in] color : color of the rectangle
// @param[in] filled: if the rectangle is filled with color or just the outlines
// 			1 is filled, 0 is just outlines
*/
int API_Draw_Rectangle(uint16_t x, uint8_t y, uint16_t width, uint8_t height, uint8_t color, uint8_t filled)
{
	uint8_t err = 0;
	uint16_t xcount, ycount;


	for(ycount = 0; ycount < VGA_DISPLAY_Y; ycount++)
	{
		for(xcount = 0; xcount < VGA_DISPLAY_X; xcount++)
		{
			if(filled)
			{
				if (ycount >= y && xcount >= x && xcount <= x + width && ycount <= y + height)
				{
					UB_VGA_SetPixel(xcount, ycount, color);
				}
			}
			else
			{
				if ((ycount >= y && xcount >= x && xcount <= x + width && ycount <= y + height) &&
					(ycount <= y || ycount >= y + height || xcount <= x || xcount >= x + width))
				{
					UB_VGA_SetPixel(xcount, ycount, color);
				}
			}
		}
	}

	return err;
}

/**-----------------------------------------------------------
 * @brief Draw clearscreen function clears the screen and fills with a specified color
 * Arguments:
 * @param[in] color : color of the screen to be filled with
*/
int API_Draw_Clearscreen(uint8_t color)
{
	UB_VGA_FillScreen(color);

	return 0;
}

/**
 * @brief API bitmap function
 * @param[in] number : selects a bitmap
 * 		0 = happy smiley
 * 		1 = sad smiley
 * 		2 = arrow up
 * 		3 = arrow down
 * 		4 = arrow left
 * 		5 = arrow right
 * @param[in] X_pos : X coordinate
 * @param[in] Y_pos : Y coordinate
 * 		xpos and ypos determine bottom left location
*/
int API_Draw_Bitmap(uint8_t Number, uint16_t X_pos, uint8_t Y_pos)
{
	uint8_t err = 0;
	for (uint64_t y = 0; y<27;y++)
	{
		for (uint64_t x=0; x<32;x++)
		{
			if (numberArray[Number][y] & (0b00000000000000000000000000000001 << x))
			{
				UB_VGA_SetPixel(x + X_pos,y + Y_pos, 0);
			}
		}
	}
	return err;
}

/**-----------------------------------------------------------
 * @brief Draw text function
 * Arguments:
 * @param[in] x1,y1 : coords of top left corner of text
 * @param[in] color : color of the text
 * @param[in] text  : the text to be displayed on the screen
 * @param[in] font  : font of the text to be displayed in
 * @param[in] fontsize: size of the letters (1 - 2)
 * @param[in] fontstyle: cursif, bold, normal
*/
int API_Draw_Text(uint16_t x, uint8_t y, uint8_t color, char* text, char* font, uint8_t fontsize, char* fontstyle)
{
	uint8_t font_type;
	uint16_t x1= x;
	uint8_t y1= y;

	if(strcmp(font, "arial") == 0)
	{
		if(strcmp(fontstyle, "vet") == 0)
		{
			font_type = ARIAL_THICC;
		}
		if(strcmp(fontstyle, "cursief") == 0)
		{
			font_type = ARIAL_CURS;
		}
		else
		{
			font_type = ARIAL_NORM;
		}
	}
	if(strcmp(font, "consolas") == 0)
	{
		if(strcmp(fontstyle, "vet") == 0)
		{
			font_type = CONSOLAS_THICC;
		}
		if(strcmp(fontstyle, "cursief") == 0)
		{
			font_type = CONSOLAS_CURS;
		}
		else
		{
			font_type = CONSOLAS_NORM;
		}
	}

	for(int i = 0; i < strlen(text); i++){
		API_Draw_Char(x1, y1, color, text[i], font_type);
		if(x1 >= 250){
			y1+=10;
			x1 = x;
		} else {
			x1+=7;
		}
	}


	return 0;
}

/**-----------------------------------------------------------
 * @brief Draw circle function
 * Arguments:
 * @param[in] x1,y1 : coords of middle of circle
 * @param[in] r  	 : radius of circle
 * @param[in] color : color of the circle
*/
int API_Draw_Circle(uint16_t x, uint8_t y, uint16_t r, uint8_t color)
{
    // Consider a rectangle of size N*N
    int N = 2*r+1;
    int ax, ay;  // Coordinates inside the rectangle

    // Draw a square of size N*N.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Start from the left most corner point
            ax = i-r;
            ay = j-r;
            // If this point is inside the circle, print it
            if (((ax*ax) + (ay*ay)) <= r*r+1 )
            {
            	UB_VGA_SetPixel((ax+x),(ay+y), color);
            }
        }
    }
    return 0;
}

/**-----------------------------------------------------------
 * @brief Draw char function
 * Arguments:
 * @param[in] x1,y1 : coords of top left corner of char
 * @param[in] color : color of the char
 * @param[in] font  : font of the letter to be displayed in
*/
int API_Draw_Char (uint8_t x, uint8_t y, uint8_t color, char character, uint8_t font)
{
	// get character index for bitmap array
	uint16_t index = (uint16_t)character - ASCII_START;
	uint8_t character_byte;
	uint8_t special_char_counter = 0;
	uint8_t special_char = 0;


	if (font == ARIAL_CURS) // character has 2 bytes per row
		special_char = Special_Char(character);

	// go through all bytes
	for(int i = 0; i <= MAX_FONT_BYTES; i++){
		// go through bits in byte
		for (int j = 0; j < BITS_IN_BYTE; j++){
			// get byte for character from font array
			character_byte = Font_Array[font][index][i];

			if (special_char) // character has 2 bytes per row
			{
				if (character_byte & (BYTE_CHECK_BEGIN >> j)) // if bit is 1
				{
					if (i % 2 == 1) // second byte, has to be shifted to the right by 8 pixels
						UB_VGA_SetPixel(j + BITS_IN_BYTE + x, special_char_counter + y, color);
					else // first byte
						UB_VGA_SetPixel(j + x, special_char_counter + y, color);
				}
			}
			else
			{
				// if bit is 1 write to screen
				if (character_byte & (BYTE_CHECK_BEGIN >> j))
				{
					UB_VGA_SetPixel(j + x, i + y, color);
				}
			}
		}

		// only increment this if i is an equal number
		// y position for special character is the same for 2 bytes
		special_char_counter += i % 2;
	}

	return 0;
}

int Special_Char(char c)
{
	// go through special char array and return 1 if given char is in this array
	for (int i = 0; i < SPECIAL_CHAR_AMT; i++)
	{
		if(c == Special_Char_Array[i])
		{
			return 1;
		}
	}
	return 0;
}
