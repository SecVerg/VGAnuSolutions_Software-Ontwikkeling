/**
 * @file API_draw.c
 * Created on: 29 Apr 2021
 * 	 @authors: Stijn Vergouwen, Maarten van Dijk, Christiaan Meerkerk
 */

#ifndef INC_API_DRAW_H_
#define INC_API_DRAW_H_

#include "API.h"
#include "usart.h"

#define BIT_SHIFTER 1

int API_Draw_Line(uint16_t x, uint8_t y, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc);
int API_Draw_Rectangle(uint16_t x, uint8_t y, uint16_t width, uint8_t height, uint8_t color, uint8_t filled);
void API_Draw_Clearscreen(uint8_t color);
int API_Draw_Bitmap(uint8_t Number, uint16_t X_pos, uint8_t Y_pos);
int API_Draw_Text(uint16_t x, uint8_t y, uint8_t color, char* text, char* font, uint8_t fontsize, char* fontstyle);
int API_Draw_Char (uint8_t x, uint8_t y, uint8_t color, char character, uint8_t font);
int API_Draw_Circle(uint16_t x, uint8_t y, uint16_t r, uint8_t color);
int Special_Char(char c);

#endif /* INC_API_DRAW_H_ */
