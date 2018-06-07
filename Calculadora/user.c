#include "user.h"

/**
 *  Aloca-se um espaço de memoria para 50 caracteres, registra-se a expressão
 *  digitada pelo usuário, e retorna-se a mesma.
 */
char* ReadExpression() {
    char *expression = (char *) malloc(sizeof(char) * 50);
    scanf("%s", expression);
    return expression;
}

/**
 *  Cria um menu para acessar os modos disponíveis pela calculadora, o usuário
 *  decide através da leitura de um inteiro (1,2 ou 3). 1 - Modo de resolução de
 *  expressões, 2 - Modo de pilha calculadora, 3 - Sair do programa.
 *
 */
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
