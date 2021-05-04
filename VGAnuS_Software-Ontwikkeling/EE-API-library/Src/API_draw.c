/*
 * API_draw.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */
#include "API_draw.h"

// Draw line function
// f = xa + b
// a = dy / dx
// b = y - xa
int API_draw_line(uint16_t x, uint8_t y, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc)
{
	uint8_t err = 0;
	float a;
	float b;
	float f;

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
			f = (int)(y/a + b);
			UB_VGA_SetPixel(i, f, color);
		}
	}

	return err;
}

int API_draw_rectangle(uint16_t x, uint8_t y, uint16_t width, uint8_t height, uint8_t color, uint8_t filled)
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
				if (((((xcount >= x && xcount <= x + 1) || // left
					(xcount >= x + width && xcount <= x + width + 1)) || //right
					((ycount >= y && ycount <= y + 1) || // top
					(ycount >= y + height && ycount <= y + height + 1)))) && // bottom
					((xcount > x && xcount <= x + width) && (ycount > y && ycount <= y + height)))
				{
					UB_VGA_SetPixel(xcount, ycount, color);
				}
			}
		}
	}

	return err;
}

int API_Draw_Clearscreen(uint8_t color)
{
	UB_VGA_FillScreen(color);

	return 0;
}

