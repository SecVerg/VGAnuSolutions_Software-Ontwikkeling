/*
 * Front_Layer.h
 *
 *  Created on: 29 Apr 2021
 *      Author: secve
 */

#ifndef INC_FRONT_LAYER_H_
#define INC_FRONT_LAYER_H_

#include "main.h"

#define TOK_AMT 11
#define TOK_LEN 128

typedef char pTokenArrayType[TOK_AMT][TOK_LEN];
typedef char pTokenType[TOK_LEN];

uint8_t FL_Color_Parse(char *text);
int FL_Parse(char *buf);
pTokenType* FL_Token_Alloc(void);
void Free_Tokens(pTokenType* pToken);

#endif /* INC_FRONT_LAYER_H_ */
