#include "user.h"

char* ReadExpression() {
    char *expression = (char *) malloc(sizeof(char) * 50);
    scanf("%s", expression);
    return expression;
}

void Menu(){
    int option;
    do{
    printf("1 - Modo Expressão\n");
    printf("2 - Modo Calculadora\n");
    printf("3 - Sair\n");
    printf("-> ");
    scanf("%d", &option);
    switch(option){
        case 1:
            ExpressionResolver();
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