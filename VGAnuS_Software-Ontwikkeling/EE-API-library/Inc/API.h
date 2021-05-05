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

#define BIT_AMT  27

#define ARIAL_NORM		0x00
#define ARIAL_THICC		0x01
#define ARIAL_CURS		0x02
#define CONSOLAS_NORM	0x03
#define CONSOLAS_THICC	0x04
#define CONSOLAS_CURS	0x05

#define sgn(x) ((x<0)?-1:((x>0)?1:0)) /* macro to return the sign of a number */

#endif /* INC_API_H_ */
