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
    stack * free_element;
    if(sHead->amount != 0){
        sHead->amount--;
        character    = sHead ->stack->value;
        free_element = sHead ->stack;
        sHead->stack = sHead->stack->next;
        free(free_element);
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
    float_stack *free_element;
    if(sHead->amount != 0){
        sHead->amount--;
        value    = sHead ->float_stack->value;
        free_element = sHead ->float_stack;
        sHead->float_stack = sHead->float_stack->next;
        free(free_element);
        return value;
    }
}

void InvertAndPrint(float_header* sHead){
    float_stack* pointer;
    float numbers[sHead->amount];
    int i = 0;
    pointer = sHead->float_stack;
    while(pointer != NULL){
        numbers[i++] = pointer->value;
        pointer = pointer->next;
    }
    for(int x = (sHead->amount-1);x>=0;x--){
        printf("%d. %f\n", (x+1), numbers[x]);
    }
}
