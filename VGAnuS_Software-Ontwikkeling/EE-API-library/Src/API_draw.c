/*
 * API_draw.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */
#include "API_draw.h"


// Bitmap array

uint64_t numberArray[][BIT_AMT] = {
{
0b00001111100000111110000000000000,
0b00011000110001100011000000000000,
0b00000000000000000000000000000000,
0b00000111000000011100000000000000,
0b00001111100000111110000000000000,
0b00011101110001110111000000000000,
0b00011000110001100011000000000000,
0b00011000110001100011000000000000,
0b00011000110001100011000000000000,
0b00011101110001110111000000000000,
0b00001111100000111110000000000000,
0b00000111000000011100000000000000,
0b00000000000100000000000000000000,
0b00000000001000000000000000000000,
0b00000000011000000000000000000000,
0b00000000110000000000000000000000,
0b00000000011000000000000000000000,
0b01110000000000000001110000000000,
0b01111000000000000011110000000000,
0b00111100000000000111100000000000,
0b00011111000000001111000000000000,
0b00001111100000111110000000000000,
0b00000111111111111100000000000000,
0b00000001111111110000000000000000,
0b00000000011111000000000000000000,
0b00000000000000000000000000000000,
},

{
0b00001111100000111110000000000000,
0b00011000110001100011000000000000,
0b00000000000000000000000000000000,
0b00000111000000011100000000000000,
0b00001111100000111110000000000000,
0b00011101110001110111000000000000,
0b00011000110001100011000000000000,
0b00011000110001100011000000000000,
0b00011000110001100011000000000000,
0b00011101110001110111000000000000,
0b00001111100000111110000000000000,
0b00000111000000011100000000000000,
0b00000000000100000000000000000000,
0b00000000001000000000000000000000,
0b00000000011000000000000000000000,
0b00000000110000000000000000000000,
0b00000000011000000000000000000000,
0b00000000000000000000000000000000,
0b00000000011111000000000000000000,
0b00000001111111110000000000000000,
0b00000111111111111100000000000000,
0b00001111100000111110000000000000,
0b00011111000000001111000000000000,
0b00111100000000000111100000000000,
0b01111000000000000011110000000000,
0b01110000000000000001111000000000,
0b01100000000000000000110000000000,
},

{
0b00000000000001100000000000000000,
0b00000000000011110000000000000000,
0b00000000000111111000000000000000,
0b00000000001111111100000000000000,
0b00000000011111111110000000000000,
0b00000000111111111111000000000000,
0b00000001111011110111100000000000,
0b00000011110011110011110000000000,
0b00000111100011110001111000000000,
0b00001111000011110000111100000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
},

{
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00000000000011110000000000000000,
0b00001111000011110000111100000000,
0b00000111100011110001111000000000,
0b00000011110011110011110000000000,
0b00000001111011110111100000000000,
0b00000000111111111111000000000000,
0b00000000011111111110000000000000,
0b00000000001111111100000000000000,
0b00000000000111111000000000000000,
0b00000000000011110000000000000000,
0b00000000000001100000000000000000,
},

{
0b0000000000000000000000000000000,
0b0000000000000000000000000000000,
0b0000000000000000000000100000000,
0b0000000000000000000000110000000,
0b0000000000000000000000111000000,
0b0000000000000000000000111100000,
0b0000000000000000000000011110000,
0b0000000000000000000000001111000,
0b0000000000000000000000000111100,
0b1111111111111111111111111111110,
0b1111111111111111111111111111111,
0b1111111111111111111111111111111,
0b1111111111111111111111111111110,
0b0000000000000000000000000111100,
0b0000000000000000000000001111000,
0b0000000000000000000000011110000,
0b0000000000000000000000111100000,
0b0000000000000000000000111000000,
0b0000000000000000000000110000000,
0b0000000000000000000000100000000,
0b0000000000000000000000000000000,
},

{

0b0000000010000000000000000000000,
0b0000000110000000000000000000000,
0b0000001110000000000000000000000,
0b0000011110000000000000000000000,
0b0000111100000000000000000000000,
0b0001111000000000000000000000000,
0b0011110000000000000000000000000,
0b0111111111111111111111111111110,
0b1111111111111111111111111111111,
0b1111111111111111111111111111111,
0b0111111111111111111111111111110,
0b0011110000000000000000000000000,
0b0001111000000000000000000000000,
0b0000111100000000000000000000000,
0b0000011110000000000000000000000,
0b0000001110000000000000000000000,
0b0000000110000000000000000000000,
0b0000000010000000000000000000000,
},
};

// Bitmap array for Arial font
static const uint16_t Font_Array[100][10] =  {
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, // Ascii = [ ]
{0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x10,0x00,0x00}, // Ascii = [!]
{0x28,0x28,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, // Ascii = ["]
{0x24,0x24,0x7C,0x24,0x48,0x7C,0x48,0x48,0x00,0x00}, // Ascii = [#]
{0x38,0x54,0x50,0x38,0x14,0x54,0x54,0x38,0x10,0x00}, // Ascii = [$]
{0x20,0x54,0x58,0x30,0x28,0x54,0x14,0x08,0x00,0x00}, // Ascii = [%]
{0x10,0x28,0x28,0x10,0x34,0x48,0x48,0x34,0x00,0x00}, // Ascii = [&]
{0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, // Ascii = [']
{0x08,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0x10,0x08}, // Ascii = [(]
{0x20,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x20}, // Ascii = [)]
{0x10,0x38,0x10,0x28,0x00,0x00,0x00,0x00,0x00,0x00}, // Ascii = [*]
{0x00,0x00,0x10,0x10,0x7C,0x10,0x10,0x00,0x00,0x00}, // Ascii = [+]
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x10}, // Ascii = [,]
{0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00}, // Ascii = [-]
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00}, // Ascii = [.]
{0x08,0x08,0x10,0x10,0x10,0x10,0x20,0x20,0x00,0x00}, // Ascii = [/]
{0x38,0x44,0x44,0x54,0x44,0x44,0x44,0x38,0x00,0x00}, // Ascii = [0]
{0x10,0x30,0x50,0x10,0x10,0x10,0x10,0x10,0x00,0x00}, // Ascii = [1]
{0x38,0x44,0x44,0x04,0x08,0x10,0x20,0x7C,0x00,0x00}, // Ascii = [2]
{0x38,0x44,0x04,0x18,0x04,0x04,0x44,0x38,0x00,0x00}, // Ascii = [3]
{0x08,0x18,0x28,0x28,0x48,0x7C,0x08,0x08,0x00,0x00}, // Ascii = [4]
{0x7C,0x40,0x40,0x78,0x04,0x04,0x44,0x38,0x00,0x00}, // Ascii = [5]
{0x38,0x44,0x40,0x78,0x44,0x44,0x44,0x38,0x00,0x00}, // Ascii = [6]
{0x7C,0x04,0x08,0x10,0x10,0x20,0x20,0x20,0x00,0x00}, // Ascii = [7]
{0x38,0x44,0x44,0x38,0x44,0x44,0x44,0x38,0x00,0x00}, // Ascii = [8]
{0x38,0x44,0x44,0x44,0x3C,0x04,0x44,0x38,0x00,0x00}, // Ascii = [9]
{0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x10,0x00,0x00}, // Ascii = [:]
{0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x10,0x10}, // Ascii = [;]
{0x00,0x00,0x0C,0x30,0x40,0x30,0x0C,0x00,0x00,0x00}, // Ascii = [<]
{0x00,0x00,0x00,0x7C,0x00,0x7C,0x00,0x00,0x00,0x00}, // Ascii = [=]
{0x00,0x00,0x60,0x18,0x04,0x18,0x60,0x00,0x00,0x00}, // Ascii = [>]
{0x38,0x44,0x04,0x08,0x10,0x10,0x00,0x10,0x00,0x00}, // Ascii = [?]
{0x38,0x44,0x4C,0x54,0x5C,0x40,0x40,0x38,0x00,0x00}, // Ascii = [@]
{0x10,0x28,0x28,0x28,0x28,0x7C,0x44,0x44,0x00,0x00}, // Ascii = [A]
{0x78,0x44,0x44,0x78,0x44,0x44,0x44,0x78,0x00,0x00}, // Ascii = [B]
{0x38,0x44,0x40,0x40,0x40,0x40,0x44,0x38,0x00,0x00}, // Ascii = [C]
{0x70,0x48,0x44,0x44,0x44,0x44,0x48,0x70,0x00,0x00}, // Ascii = [D]
{0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x7C,0x00,0x00}, // Ascii = [E]
{0x7C,0x40,0x40,0x78,0x40,0x40,0x40,0x40,0x00,0x00}, // Ascii = [F]
{0x38,0x44,0x40,0x40,0x5C,0x44,0x44,0x38,0x00,0x00}, // Ascii = [G]
{0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x44,0x00,0x00}, // Ascii = [H]
{0x38,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00}, // Ascii = [I]
{0x04,0x04,0x04,0x04,0x04,0x04,0x44,0x38,0x00,0x00}, // Ascii = [J]
{0x44,0x48,0x50,0x60,0x50,0x48,0x48,0x44,0x00,0x00}, // Ascii = [K]
{0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7C,0x00,0x00}, // Ascii = [L]
{0x44,0x6C,0x6C,0x54,0x44,0x44,0x44,0x44,0x00,0x00}, // Ascii = [M]
{0x44,0x64,0x64,0x54,0x54,0x4C,0x4C,0x44,0x00,0x00}, // Ascii = [N]
{0x38,0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00,0x00}, // Ascii = [O]
{0x78,0x44,0x44,0x44,0x78,0x40,0x40,0x40,0x00,0x00}, // Ascii = [P]
{0x38,0x44,0x44,0x44,0x44,0x44,0x54,0x38,0x04,0x00}, // Ascii = [Q]
{0x78,0x44,0x44,0x44,0x78,0x48,0x48,0x44,0x00,0x00}, // Ascii = [R]
{0x38,0x44,0x40,0x30,0x08,0x04,0x44,0x38,0x00,0x00}, // Ascii = [S]
{0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00}, // Ascii = [T]
{0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00,0x00}, // Ascii = [U]
{0x44,0x44,0x44,0x28,0x28,0x28,0x10,0x10,0x00,0x00}, // Ascii = [V]
{0x44,0x44,0x54,0x54,0x54,0x6C,0x28,0x28,0x00,0x00}, // Ascii = [W]
{0x44,0x28,0x28,0x10,0x10,0x28,0x28,0x44,0x00,0x00}, // Ascii = [X]
{0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x00,0x00}, // Ascii = [Y]
{0x7C,0x04,0x08,0x10,0x10,0x20,0x40,0x7C,0x00,0x00}, // Ascii = [Z]
{0x18,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x18}, // Ascii = [[]
{0x20,0x20,0x10,0x10,0x10,0x10,0x08,0x08,0x00,0x00}, // Ascii = [\]
{0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x30}, // Ascii = []]
{0x10,0x28,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00}, // Ascii = [^]
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE}, // Ascii = [_]
{0x20,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, // Ascii = [`]
{0x00,0x00,0x38,0x44,0x3C,0x44,0x4C,0x34,0x00,0x00}, // Ascii = [a]
{0x40,0x40,0x58,0x64,0x44,0x44,0x64,0x58,0x00,0x00}, // Ascii = [b]
{0x00,0x00,0x38,0x44,0x40,0x40,0x44,0x38,0x00,0x00}, // Ascii = [c]
{0x04,0x04,0x34,0x4C,0x44,0x44,0x4C,0x34,0x00,0x00}, // Ascii = [d]
{0x00,0x00,0x38,0x44,0x7C,0x40,0x44,0x38,0x00,0x00}, // Ascii = [e]
{0x0C,0x10,0x7C,0x10,0x10,0x10,0x10,0x10,0x00,0x00}, // Ascii = [f]
{0x00,0x00,0x34,0x4C,0x44,0x44,0x4C,0x34,0x04,0x78}, // Ascii = [g]
{0x40,0x40,0x58,0x64,0x44,0x44,0x44,0x44,0x00,0x00}, // Ascii = [h]
{0x10,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x00,0x00}, // Ascii = [i]
{0x10,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0xE0}, // Ascii = [j]
{0x40,0x40,0x48,0x50,0x60,0x50,0x48,0x44,0x00,0x00}, // Ascii = [k]
{0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00}, // Ascii = [l]
{0x00,0x00,0x78,0x54,0x54,0x54,0x54,0x54,0x00,0x00}, // Ascii = [m]
{0x00,0x00,0x58,0x64,0x44,0x44,0x44,0x44,0x00,0x00}, // Ascii = [n]
{0x00,0x00,0x38,0x44,0x44,0x44,0x44,0x38,0x00,0x00}, // Ascii = [o]
{0x00,0x00,0x58,0x64,0x44,0x44,0x64,0x58,0x40,0x40}, // Ascii = [p]
{0x00,0x00,0x34,0x4C,0x44,0x44,0x4C,0x34,0x04,0x04}, // Ascii = [q]
{0x00,0x00,0x58,0x64,0x40,0x40,0x40,0x40,0x00,0x00}, // Ascii = [r]
{0x00,0x00,0x38,0x44,0x30,0x08,0x44,0x38,0x00,0x00}, // Ascii = [s]
{0x20,0x20,0x78,0x20,0x20,0x20,0x20,0x18,0x00,0x00}, // Ascii = [t]
{0x00,0x00,0x44,0x44,0x44,0x44,0x4C,0x34,0x00,0x00}, // Ascii = [u]
{0x00,0x00,0x44,0x44,0x28,0x28,0x28,0x10,0x00,0x00}, // Ascii = [v]
{0x00,0x00,0x54,0x54,0x54,0x6C,0x28,0x28,0x00,0x00}, // Ascii = [w]
{0x00,0x00,0x44,0x28,0x10,0x10,0x28,0x44,0x00,0x00}, // Ascii = [x]
{0x00,0x00,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x60}, // Ascii = [y]
{0x00,0x00,0x7C,0x08,0x10,0x20,0x40,0x7C,0x00,0x00}, // Ascii = [z]
{0x18,0x10,0x10,0x10,0x20,0x20,0x10,0x10,0x10,0x18}, // Ascii = [{]
{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10}, // Ascii = [|]
{0x30,0x10,0x10,0x10,0x08,0x08,0x10,0x10,0x10,0x30}, // Ascii = [}]
{0x00,0x00,0x00,0x74,0x4C,0x00,0x00,0x00,0x00,0x00}, // Ascii = [~]
};

// ----------------------------------------------------------
// Draw line function
// Arguments:
// x1,y1,x2,x2 : coords of beginning and end of line
// color : color of the line
// thicc : thicness of the line
// ----------------------------------------------------------
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

//-----------------------------------------------------------
// Draw rectangle function
// Arguments:
// x1,y1 : coords of top left corner of rectangle
// width : width of the rectangle in pixels
// height: height of the rectangle in pixels
// color : color of the rectangle
// filled: if the rectangle is filled with color or just the outlines
// 1 is filled, 0 is just outlines
// ----------------------------------------------------------
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

//-----------------------------------------------------------
// Draw clearscreen function
// Arguments:
// color : color of the screen to be filled with
// ----------------------------------------------------------
int API_Draw_Clearscreen(uint8_t color)
{
	UB_VGA_FillScreen(color);

	return 0;
}

//API bitmap function
//0 = happy smiley
//1 = sad smiley
// xpos and ypos determine bottom left location
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

//-----------------------------------------------------------
// Draw text function
// Arguments:
// x1,y1 : coords of top left corner of text
// color : color of the text
// text  : the text to be displayed on the screen
// font  : font of the text to be displayed in
// fontsize: size of the letters (1 - 2)
// fontstyle: cursif, bold, normal
// ----------------------------------------------------------
int API_Draw_Text(uint16_t x, uint8_t y, uint8_t color, char* text, char* font, uint8_t fontsize, char* fontstyle)
{
	uint8_t font_type;

	if(strcmp(font, "arial") == 0)
	{
		font_type = ARIAL_NORM;
	}

	for(int i = 0; i < strlen(text); i++){
		API_Draw_Char(x, y, color, text[i], font_type);
		x += 9;
	}

	return 0;
}

//-----------------------------------------------------------
// Draw circle function
// Arguments:
// x1,y1 : coords of middle of circle
// r  	 : radius of circle
// color : color of the circle
// ----------------------------------------------------------
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

//-----------------------------------------------------------
// Draw char function
// Arguments:
// x1,y1 : coords of top left corner of char
// color : color of the char
// font  : font of the letter to be displayed in
// ----------------------------------------------------------
int API_Draw_Char (uint8_t x, uint8_t y, uint8_t color, char character, uint8_t font)
{
	// get character index for bitmap array
	uint16_t index = (uint16_t)character - 32;

	// go through all bytes
	for(int i = 0; i < 10; i++){
		// go through bits in byte
		for (int j = 0; j < 8; j++){
			// if bit is 1 display on screen
			if (Font_Array[index][i] & (0b10000000 >> j))
			{
				UB_VGA_SetPixel(j + x, i + y, color);
			}
		}
	}

	return 0;
}
