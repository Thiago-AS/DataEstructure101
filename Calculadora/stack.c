#include "stack.h"

header* CreateStack(){
    header* sHead   = (header*) malloc(sizeof(header));
    sHead->stack    = NULL;
    sHead->amount   = 0;
    return sHead;
}

void PushChar(header* sHead, char value){
    stack *element  = (stack*) malloc(sizeof(stack));
    element->value  = value;
    element->next   = sHead->stack;
    sHead->stack    = element;
    sHead->amount++;
}

char PopChar(header *sHead){
    char character;
    if(sHead->amount != 0){
        sHead->amount--;
        character    = sHead ->stack->value;
        free(sHead->stack);
        sHead->stack = sHead->stack->next;
        return character;
    }
    else{
        return '\0';
    }
}