#ifndef CALCULADORA_STACK_H
#define CALCULADORA_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    unsigned int value;
    struct stack *next;
}stack;

typedef struct header{
    struct stack* stack;
    int amount;
}header;

header* CreateStack();

void PushChar(header* pHead, char value);

char PopChar(header *pHead);



#endif //CALCULADORA_STACK_H
