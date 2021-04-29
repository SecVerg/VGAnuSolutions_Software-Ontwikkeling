/*
 * API_draw.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */





// Draw line function
// f = xa + b
// a = dy / dx
// b = y - xa


int API_draw_line(uint16_t x, uint8_t y, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc)
{

	float a;
	float b;
	float f;

	a = (y2 - y) / (x2 - x);
	b = y - x*a;

	for(int i = x; i < x2; i++) // loop for all x coords of the line
	{
		f = (int)(x * a + b);					 // xa+b = y
		UB_VGA_SetPixel(x, f, color);
	}
}

