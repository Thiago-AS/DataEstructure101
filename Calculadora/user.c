#include "user.h"

char* ReadExpression() {
    char *expression = (char *) malloc(sizeof(char) * 50);
    scanf("%s", expression);
    return expression;
}

void Menu(){
    int option;
    char* expression;
    char* postfix;
    do{
    printf("1 - Modo Expressão\n");
    printf("2 - Modo Calculadora\n");
    printf("3 - Sair\n");
    printf("-> ");
    scanf("%d", &option);
    switch(option){
        case 1:
            system("clear");
            printf("Digite sua expressão: ");
            expression = ReadExpression();
            if(ValidateInfix(expression)){
                printf("Expressão válida\n");
                postfix = InfixToPosFix(expression);
                printf("Forma posfixa: %s\n", postfix);
                printf("Resultado: %f \n", PostFixValue(postfix));
                printf("-----------------------------------------------\n");
                free(expression);
                free(postfix);
            }
            else{
                printf("Expressão inválida\n");
                printf("-----------------------------------------------\n");
            }
            break;

        case 2:
            Calculator();
            break;

        case 3:
            break;
        default:
            printf("Escolha uma das opções acima\n");
            break;
    }
    }while(option != 3);
}