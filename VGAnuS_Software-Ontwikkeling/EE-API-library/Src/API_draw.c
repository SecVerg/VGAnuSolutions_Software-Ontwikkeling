/*
 * API_draw.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */
#include "API.h"

// Draw line function
// f = xa + b
// a = dy / dx
// b = y - xa

// inverse for lines with a >1
// f = y/a + b


int API_draw_line(uint16_t x, uint8_t y, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc)
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

int API_draw_rectangle(uint16_t x, uint8_t y, uint16_t width, uint8_t height, uint8_t color, uint8_t filled)
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

