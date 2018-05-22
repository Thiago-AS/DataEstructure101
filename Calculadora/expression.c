#include "expression.h"

int ValidateInfix(char* expression){
    header *sHead   = CreateStack();
    for(int i=0; i<strlen(expression); i++){
        switch(expression[i]){
            case '(':
                PushChar(sHead, expression[i]);
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

char* InfixToPosFix(char * expression){
    header *sHead   = CreateStack();
    int y=0;
    char* final_expression = (char*) malloc(sizeof(char)*50);
    char auxChar;

    for(int x=0; x<strlen(expression); x++){
        switch (expression[x]) {
            case '*':
                if(sHead->stack != NULL){
                    if(sHead->stack->value == '/'){
                        final_expression[y++] = PopChar(sHead);
                    }
                }
                PushChar(sHead, expression[x]);
                break;
            case '/':
                if(sHead->stack != NULL){
                    if(sHead->stack->value == '*'){
                        final_expression[y++] = PopChar(sHead);
                    }
                }
                PushChar(sHead, expression[x]);
                break;
            case '+':
                if(sHead->stack != NULL){
                    while(sHead->stack->value == '*' || sHead->stack->value == '/' || sHead->stack->value == '-'){
                        auxChar = PopChar(sHead);
                        if(auxChar != '('){
                            final_expression[y++] = auxChar;
                        }
                        else{
                            break;
                        }
                        if(sHead->stack == NULL){
                            break;
                        }
                    }
                }
                PushChar(sHead, expression[x]);
                break;
            case '-':
                if(sHead->stack != NULL){
                    while(sHead->stack->value == '*' || sHead->stack->value == '/' ||  sHead->stack->value == '+'){
                        auxChar = PopChar(sHead);
                        if(auxChar != '('){
                            final_expression[y++] = auxChar;
                        }
                        else{
                            break;
                        }
                        if(sHead->stack == NULL){
                            break;
                        }
                    }
                }
                PushChar(sHead, expression[x]);
                break;
            case '(':
                PushChar(sHead, expression[x]);
                break;
            case ')':
                while(sHead->stack != NULL){
                    auxChar = PopChar(sHead);
                    if(auxChar == '('){
                        break;
                    }
                    else{
                        final_expression[y++] = auxChar;
                    }
                }
                break;
            default:
                final_expression[y++] = expression[x];
                break;
        }
    }
    while(sHead->stack != NULL){
        auxChar = PopChar(sHead);
        final_expression[y++] = auxChar;
    }
    final_expression[y] = '\0';
    return final_expression;
}

