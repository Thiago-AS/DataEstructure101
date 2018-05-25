#ifndef CALCULADORA_EXPRESSION_H
#define CALCULADORA_EXPRESSION_H

#define TRUE 1
#define FALSE 0

#include "stack.h"

int ValidateInfix(char* expression);

char* InfixToPosFix(char * expression);

float PostFixValue(char * expression);

float GetFloat(header* sHead);

void Calculator();

#endif
