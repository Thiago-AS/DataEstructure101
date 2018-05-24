#include "user.h"

char* readExpression() {
    char *expression = (char *) malloc(sizeof(char) * 50);
    scanf("%s", expression);
    return expression;
}

void menu(){
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
            expression = readExpression();
            if(ValidateInfix(expression)){
                printf("Expressão válida\n");
                postfix = InfixToPosFix(expression);
                printf("Forma posfixa: %s\n", postfix);
                printf("Resultado: %f \n", PostFixValue(postfix));
            }
            else
                printf("Expressao invalida");

            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Escolha uma das opções acima");
            break;
    }
    }while(option != 3);
}