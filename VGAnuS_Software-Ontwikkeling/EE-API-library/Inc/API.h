/*
 * API.h
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */

#ifndef INC_API_H_
#define INC_API_H_

#include "main.h"
#include "API_io.h"
#include "API_draw.h"

typedef struct VGA_Command
{
	uint8_t  CMD_Type;		// A specific Type value

	uint16_t X_pos;			// X_LUP, The first X-axis positional value of the item
							// to be displayed on the screen

	uint8_t  Y_pos;			// Y_LUP, The first Y-axis positional value of the item
							// to be displayed on the screen

	uint16_t X_sec_pos;		// X'The second Y-axis positional value of the item
							// to be displayed on the screen

	uint8_t  Y_sec_pos;		// Y' The second Y-axis positional value of the item
							// to be displayed on the screen

	uint16_t Width;			// Width of the item to be displayed in the screen
							// in pixels

	uint8_t  Height;		// Height of the item to be displayed in the screen
							// in pixels

	uint8_t  Filled;		// 1 or 0 to specify if rectangle is filled with
							// color or not

	uint8_t Color;			// Specifies the color of the item to be
							// displayed on the screen

	uint8_t  Number;

	uint8_t  Thickness;

	char*	 Text;			// Text string to be displayed on the screen

	char*	 Font;			// Font of the text to be displayed on the screen
							// Arial or Consolas

	char*  	 Fontstyle;		// Fontstyle of the text to be displayed on the screen
							// Cursive, Bold or normal

	uint8_t  Fontsize;		// Fontsize of the text to be displayed on the screen
							// 1 or 2

	uint8_t Radius;
} VGA_Command;

#define BIT_AMT  27

#define ARIAL_NORM		0x00
#define ARIAL_THICC		0x01
#define ARIAL_CURS		0x02
#define CONSOLAS_NORM	0x03
#define CONSOLAS_THICC	0x04
#define CONSOLAS_CURS	0x05

#define MAX_ERRMSG_SIZE   128

#define LINE 0x1		//lijn
#define RECT 0x2		//Rechthoek
#define TEXT 0x3		//text
#define BITM 0x4		//Bitmap
#define CLRS 0x5		//Clearscreen
#define WAIT 0x6		//Wacht
#define REPT 0x7		//Herhaal
#define CIRC 0x8		//Cirkel
#define FIGU 0x9		//Figuur
#define EXEC 0xA		//Execute

#define ERR_PARSE 			0x10
#define ERR_COLOR 			0x11
#define ERR_EXEC  			0x12
#define ERR_EXEC_NYI	 	0x13
#define ERR_EXEC_UNK	 	0x14
#define ERR_OOR				0x20

#define sgn(x) ((x<0)?-1:((x>0)?1:0)) /* macro to return the sign of a number */

#endif /* INC_API_H_ */
