/*
 * API_draw.h
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */

#ifndef INC_API_DRAW_H_
#define INC_API_DRAW_H_

#include "API.h"
#include "usart.h"

int API_Draw_Line(uint16_t x, uint8_t y, uint16_t x2, uint8_t y2, uint8_t color, uint8_t thicc);
int API_draw_rectangle(uint16_t x, uint8_t y, uint16_t width, uint8_t height, uint8_t color, uint8_t filled);
int API_Draw_Clearscreen(uint8_t color);

#endif /* INC_API_DRAW_H_ */
