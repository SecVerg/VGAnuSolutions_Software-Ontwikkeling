/**
 * @file Front_Layer.h
 *
 *  Created on: 29 Apr 2021
 *    @authors: Stijn Vergouwen, Maarten van Dijk, Christiaan Meerkerk
 */

#ifndef INC_FRONT_LAYER_H_
#define INC_FRONT_LAYER_H_

#include "main.h"
#include "usart.h"
#include "Logic_Layer.h"

#define TOK_AMT 11
#define TOK_LEN 128

#define LIJN		"lijn"
#define RECHTHOEK	"rechthoek"
#define TEKST		"tekst"
#define BITMAP		"bitmap"
#define CLEARSCHERM	"clearscherm"
#define WACHT		"wacht"
#define HERHAAL		"herhaal"
#define CIRKEL		"cirkel"
#define FIGUUR		"figuur"

typedef char pTokenType[TOK_LEN];

uint8_t FL_Color_Parse(char *text);
int FL_Parse(char *buf);
void FL_Write_Error(int err);
int strtopos(char* str, char xy);

#endif /* INC_FRONT_LAYER_H_ */
