/*
 * Front_Layer.h
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */

#ifndef INC_FRONT_LAYER_H_
#define INC_FRONT_LAYER_H_

#include "main.h"

VGA_Command FL_Parse(char *buf);
int FL_Color_Parse(char *text);

#endif /* INC_FRONT_LAYER_H_ */
