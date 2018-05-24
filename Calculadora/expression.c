#include <math.h>
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
                final_expression[y++] = ' ';
                if(sHead->stack != NULL){
                    if(sHead->stack->value == '/'){
                        final_expression[y++] = PopChar(sHead);
                        final_expression[y++] = ' ';
                    }
                }
                PushChar(sHead, expression[x]);
                break;
            case '/':
                final_expression[y++] = ' ';
                if(sHead->stack != NULL){
                    if(sHead->stack->value == '*'){
                        final_expression[y++] = PopChar(sHead);
                        final_expression[y++] = ' ';
                    }
                }
                PushChar(sHead, expression[x]);
                break;
            case '+':
                final_expression[y++] = ' ';
                if(sHead->stack != NULL){
                    while(sHead->stack->value == '*' || sHead->stack->value == '/' || sHead->stack->value == '-'){
                        auxChar = PopChar(sHead);
                        if(auxChar != '('){
                            final_expression[y++] = auxChar;
                            final_expression[y++] = ' ';
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
                final_expression[y++] = ' ';
                if(sHead->stack != NULL){
                    while(sHead->stack->value == '*' || sHead->stack->value == '/' ||  sHead->stack->value == '+'){
                        auxChar = PopChar(sHead);
                        if(auxChar != '('){
                            final_expression[y++] = auxChar;
                            final_expression[y++] = ' ';
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
                        final_expression[y++] = ' ';
                        final_expression[y++] = auxChar;
                    }
                }
                break;
            case '.':
                final_expression[y++] = expression[x];
                break;
            default:
                final_expression[y++] = expression[x];
                break;
        }
    }
    while(sHead->stack != NULL){
        auxChar = PopChar(sHead);
        final_expression[y++] = ' ';
        final_expression[y++] = auxChar;

    }
    final_expression[y] = '\0';
    return final_expression;
}

float PostFixValue(char * expression){
    header *sHead   = CreateStack();
    float_header* fHead = CreateFloatStack();
    float num1, num2, number;
    for(int i=0; i<strlen(expression);i++){
        if(expression[i] != '*' && expression[i] != '/' && expression[i] != '+' && expression[i] != '-' && expression[i] != ' '){
            PushChar(sHead, expression[i]);
        }else{
            switch (expression[i]) {
                case '-':
                    num2 = PopFloat(fHead);
                    num1 = PopFloat(fHead);
                    PushFloat(fHead, (num1-num2));
                    break;
                case '+':
                    num2 = PopFloat(fHead);
                    num1 = PopFloat(fHead);
                    PushFloat(fHead, num1+num2);
                    break;
                case '*':
                    num2 = PopFloat(fHead);
                    num1 = PopFloat(fHead);
                    PushFloat(fHead, num1*num2);
                    break;
                case '/':
                    num2 = PopFloat(fHead);
                    num1 = PopFloat(fHead);
                    PushFloat(fHead, num1/num2);
                    break;
                case ' ':
                    if(expression[i-1] != '*' && expression[i-1] != '/' && expression[i-1] != '+' && expression[i-1] != '-' && expression[i-1] != ' '){
                        number = GetFloat(sHead);
                        PushFloat(fHead, number);
                    }
                    break;
                default:
                    break;
            }
        }
    }

    return PopFloat(fHead);

}

float GetFloat(header* sHead){
    int dot,counter;
    float float_value;
    char value;
    counter = 0;
    float_value = 0;
    dot=0;
    while(sHead->stack != NULL){
        value = PopChar(sHead);
        if(value == '.'){
            dot = counter;
        }else{
            float_value = powf(10,counter)*(value-48) + float_value;
            counter++;
        }
    }

    float_value = float_value / powf(10,dot);
    return float_value;
}
