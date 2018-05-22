#include "expression.h"
#include "stack.h"

int ValidateInfix(char* expression){
    header *sHead = CreateStack();
    for(int x=0; x<strlen(expression); x++){
        switch(expression[x]){
            case '(':
                PushChar(sHead, expression[x]);
                break;

            case ')':
                if(sHead->amount == 0){
                    free(sHead);
                    return FALSE;
                }
                if(sHead->amount != 0){
                    PopChar(sHead);
                }
                break;

            default:
                break;
        }
    }
    if(sHead->amount == 0){
        free(sHead);
        return TRUE;
    }
    else{
        free(sHead);
        return FALSE;
    }

}

