/*
 * API_draw.c
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */

#include "API_draw.h"


uint16_t numberArray[][9] = {
// happy smiley
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
};

// Draw line function
// f = xa + b
// a = dy / dx
// b = y - xa

// inverse for lines with a >1
// f = y/a + b
int API_Draw_Line(uint16_t x1, uint8_t y1, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc)
{
	int err = 0;
	int dx,dy,sdx,sdy,px,py,dxabs,dyabs,i;
	float slope;

	dx=x2-x1;      /* the horizontal distance of the line */
	dy=y2-y1;      /* the vertical distance of the line */
	dxabs=abs(dx);
	dyabs=abs(dy);
	sdx=sgn(dx);
	sdy=sgn(dy);

	if (dxabs>=dyabs) /* the line is more horizontal than vertical */
	{
		slope=(float)dy / (float)dx;
		for(i=0;i!=dx;i+=sdx)
		{
		  px=i+x1;
		  py=slope*i+y1;
		  UB_VGA_SetPixel(px,py,color);
		}
	}
	else /* the line is more vertical than horizontal */
	{
		slope=(float)dx / (float)dy;
		for(i=0;i!=dy;i+=sdy)
		{
		  px=slope*i+x1;
		  py=i+y1;
		  UB_VGA_SetPixel(px,py,color);
		}
	}

	return err;
}

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

int API_Draw_Clearscreen(uint8_t color)
{
	UB_VGA_FillScreen(color);

	return 0;
}



int API_Draw_Bitmap(uint8_t Number, uint16_t X_pos, uint8_t Y_pos)
{
	uint8_t err = 0;

	for (int y = 0; y<9;y++)
	{
		for (int x=0; x<10;x++)
		{
			if (numberArray[Number][y] == 1 << x)
			UB_VGA_SetPixel(x + X_pos,y + Y_pos,0);
		}
	}
	return err;
}

