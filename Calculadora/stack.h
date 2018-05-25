#ifndef CALCULADORA_STACK_H
#define CALCULADORA_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char value;
    struct stack *next;
}stack;

typedef struct header{
    struct stack* stack;
    int amount;
}header;

typedef struct float_stack{
    float value;
    struct float_stack *next;
}float_stack;

typedef struct float_header{
    struct float_stack* float_stack;
    int amount;
}float_header;

header* CreateStack();

float_header* CreateFloatStack();

void PushChar(header* sHead, char value);

char PopChar(header *sHead);

void PushFloat(float_header* sHead, float value);

float PopFloat(float_header* sHead);

void InvertAndPrint(float_header* sHead);

#endif
