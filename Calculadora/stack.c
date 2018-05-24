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

float_header* CreateFloatStack(){
    float_header* sHead   = (float_header*) malloc(sizeof(float_header));
    sHead->float_stack    = NULL;
    sHead->amount   = 0;
    return sHead;
}

void PushFloat(float_header* sHead, float value){
    float_stack *element  = (float_stack*) malloc(sizeof(float_stack));
    element->value  = value;
    element->next   = sHead->float_stack;
    sHead->float_stack    = element;
    sHead->amount++;
}

float PopFloat(float_header* sHead){
    float value;
    if(sHead->amount != 0){
        sHead->amount--;
        value    = sHead ->float_stack->value;
        free(sHead->float_stack);
        sHead->float_stack = sHead->float_stack->next;
        return value;
    }
}
