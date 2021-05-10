/*
 * API_Font.h
 *
 *  Created on: May 10, 2021
 *      Author: secve
 */

#ifndef INC_API_FONT_H_
#define INC_API_FONT_H_

#include "API.h"

#define MAX_FONT_BYTES 		26
#define CHAR_AMT			100
#define FONT_AMT			6
#define SPECIAL_CHAR_AMT	6

extern const char Font_Array[FONT_AMT][CHAR_AMT][MAX_FONT_BYTES];
extern const char Special_Char_Array[SPECIAL_CHAR_AMT];

#endif /* INC_API_FONT_H_ */
