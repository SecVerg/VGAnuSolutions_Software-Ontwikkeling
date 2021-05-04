/*
 * API_draw.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */
#include "API_draw.h"


//uint16_t numberArray[][9] = {

//for (int y = 0; y<9;y++)
//{
//	for (int x=0; x<10;x++)
//	{
//		if (numberArray[0][0] == 0b0000000001 << 0)
//		{
//			UB_VGA_SetPixel(x + X_pos,y + Y_pos,0);
//			HAL_UART_Transmit_DMA(&huart2, (uint8_t *)"tet\n", 4);
//		}
//	}
//}
uint64_t numberArray[][39] = {

{
0b0011111000,
0b0100000100,
0b1000000010,
0b1010001010,
0b1000000010,
0b1010001010,
0b1001110010,
0b0100000100,
0b0011111000,
},
// sad smiley
{
0b0011111000,
0b0100000100,
0b1000000010,
0b1010001010,
0b1000000010,
0b1001110010,
0b1010001010,
0b0100000100,
0b0011111000,
},

{
0b0000000000000000000000000000000000000000000,
0b0000000000000000011111100000000000000000000,
0b0000000000000111111111111110000000000000000,
0b0000000000011111111111111111100000000000000,
0b0000000001111111100000011111111000000000000,
0b0000000011111000000000000001111100000000000,
0b0000000111110000000000000000111110000000000,
0b0000001111000000000000000000001111000000000,
0b0000011110000001000000000110000111100000000,
0b0000011100000111110000011111000011100000000,
0b0000111000001111111000111111100001110000000,
0b0000111000011110111101111011110001110000000,
0b0001110000011100011101110001110000111000000,
0b0001110000011100011101110000110000111000000,
0b0011100000011100011101110001110000011100000,
0b0011100000011111111100111111110000011100000,
0b0011100000001111111000111111100000011100000,
0b0011100000000111110000001111000000011100000,
0b0011100000000000000000000000000000011100000,
0b0011100000000000000000000000000000011100000,
0b0011100000000000000000000000000000011100000,
0b0011100000000000000000000000000000011100000,
0b0011100000000000000000000000000000011100000,
0b0011100000110000000000000000011000011100000,
0b0011100000111000000000000000111100011100000,
0b0001110000111100000000000001111000111000000,
0b0001110000011110000000000011110000111000000,
0b0000111000001111100000000111100001110000000,
0b0000111000000111110000011111000001110000000,
0b0000011100000011111111111110000011100000000,
0b0000011110000000111111111000000111100000000,
0b0000001111000000001111100000001111000000000,
0b0000000111110000000000000000011110000000000,
0b0000000011111000000000000001111100000000000,
0b0000000001111111000000001111111000000000000,
0b0000000000011111111111111111100000000000000,
0b0000000000000111111111111110000000000000000,
0b0000000000000000011111100000000000000000000,
0b0000000000000000000000000000000000000000000,
0b0101010101010101010101010101010101010101010,


},

};

// Draw line function
// f = xa + b
// a = dy / dx
// b = y - xa

// inverse for lines with a >1
// f = y/a + b


int API_Draw_Line(uint16_t x, uint8_t y, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc)
{
	uint8_t err = 0;
	float a;
	float b;
	int f;

	a = (y2 - y) / (x2 - x);
	b = y - x*a;

	if (a <= 1 || a >= -1)
	{
		for(int i = x; i < x2; i++) // loop for all x coords of the line
		{
			f = (int)(i * a + b);					 // xa+b = y
			UB_VGA_SetPixel(i, f, color);
		}
	}
	else
	{
		for (int i = y; i < y2; i++)
		{
			f = (int)(i/a + b/a);
			UB_VGA_SetPixel(i, f, color);
		}
	}

	return err;
}

int API_Draw_Rectangle(uint16_t x, uint8_t y, uint16_t width, uint8_t height, uint8_t color, uint8_t filled)
{
	uint8_t err = 0;
	uint16_t xcount, ycount;

	if(filled)
	{
		for(ycount = 0; ycount < VGA_DISPLAY_Y; ycount++)
		{
			for(xcount = 0; xcount < VGA_DISPLAY_X; xcount++)
			{
				if (ycount >= y && xcount >= x && xcount <= x + width && ycount <= y + height)
				{
					UB_VGA_SetPixel(xcount, ycount, color);
				}
			}
		}
	}
	else
	{
		for(xcount = x; xcount < x + width; xcount++)		// Top line
		{
			UB_VGA_SetPixel(xcount, y, color);
		}

		for(ycount = y; ycount < y + height; ycount++)		// Left line
		{
			UB_VGA_SetPixel(x, ycount, color);
		}

		for(xcount = x; xcount <= x + width; xcount++)		// Bottom line
		{
			UB_VGA_SetPixel(xcount, ycount, color);
		}

		for(ycount = y; ycount <= y + height; ycount++)		// Right line
		{
			UB_VGA_SetPixel(xcount, ycount, color);
		}
	}

	return err;
}

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
	for (uint64_t y = 0; y<39;y++)
	{
		for (uint64_t x=0; x<43;x++)
		{
			if (numberArray[Number][y] & (0b0000000000000000000000000000000000000000001 << x))
			{
				UB_VGA_SetPixel(x + X_pos,y + Y_pos,0);
			}
		}
	}
	return err;
}
