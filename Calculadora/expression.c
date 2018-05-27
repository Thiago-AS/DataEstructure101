#include <math.h>
#include "expression.h"
#include "user.h"

/**
 *  Inicia-se uma pilha vazia e itera-se sobre a expressão informada, onde se um
 *  parenteses de abertura for encontrado, o mesmo é empilhado. Se um parenteses de
 *  fechamento é encontrado, verifica-se se a pilha se encontra vaiza, caso esteja
 *  vazia, então a equação não é valida, caso tenha elementos, um elemento é desempilhado.
 *
 *  Ao final da verificação a pilha deve se encontrar vazia, caso não se encontre
 *  vazia, a expressão é invalidada.
 */
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

/**
 *  Inicia-se uma pilha vazia e itera-se sobre a expressão informada, copia-se todos
 *  os operandos encontrados diretamente para a expressão de saida.
 *
 *  Ao encontrar uma operação, caso a pilha não esteja vazia e houver um operador
 *  de maior prioriade no topo, desempilha-se o operar e o copia na saída, se não
 *  apenas empilha o operador.
 *
 *  Ao encontrar um parenteses de abertura, este é empilhado. Ao encontrar um parenteses
 *  de fechamento, remove-se os elementos da pilha e os copia na saída, até que o
 *  parenteses de abertura seja desempilhado.
 *
 *  Para que fosse possível a converção para float posteriormente, adicionou-se um caractére
 *  especial após cada operando ou operação, sendo este um espaço vazio ' '.
 */
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
    free(sHead);
    return final_expression;
}

/**
 *  Inicia-se duas pilhas vazias, uma de char e outra de float. Itera-se sobre
 *  a expressão fornecida, onde copia-se os operandos para a pila de char.
 *
 *  Ao encontrar um espaço vazio, e seu valor anterior ser um digito, utiliza-se da
 *  função GetFloat, onde transforma-se o valor antes em string para um float, e empilha-o
 *  na pilha de floats.
 *
 *  Ao encontrar uma operação, então seus operandos se encontram na pilha de floats.
 *  Os dois valores correspondentes a operação específica são desempilhados e a operação
 *  é realizada, o resultado é novamente empilhado.
 *
 *  Ao final, a pilha conterá apenas o valor final da expressão que é retornado.
 */
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
    number = PopFloat(fHead);
    free(sHead);
    free(fHead);
    return number;

}

/**
 *  Recebe uma pilha contendo uma string de um valor decomposto em digitos char.
 *
 *  Desempilha-se os valores até encontrar o ponto, realizando uma operação para deixar
 *  os digitos em suas respectivas casas decimais (Valor_float = powf(10, contador)
 *  *(Valor_char - 48) + Valor_float)
 *
 *  Ao encontrar o ponto, salva-se sua posição na devida casa decimal, para que
 *  seja possivel dividir o valor final por dez elevado a posição decimal do ponto,
 *  obtendo assim o valor em float.
 */
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

/**
 *  Inicia uma pilha de float vazia e aguarda pela entrada de dados. Assim que um número é digitado
 *  , este é empilhado.
 *
 *  Assim que uma operação é digitada, os operandos necessários são desempilhados, é realizada
 *  a operação e o resultado é empilhado novamente.
 *
 *  Quando a quantidade de operando for insuficiente, uma mensagem de erro é exibida.
 *
 *  Enquanto a calculadora esta em execução, esta imprime constantemente a pilha em
 *  forma inversa.
 */
void Calculator(){
    char* expression = NULL;
    header* sHead = CreateStack();
    float_header* fHead = CreateFloatStack();
    float num1,num2;
    do{
        system("clear");
        printf("Modo Calculadora (Digite 'sair' para voltar ao menu)\n");
        if(fHead->float_stack == NULL){
            printf("Pilha vazia!\n");
        }else{
            InvertAndPrint(fHead);
        }
        if(expression == NULL){
            expression = ReadExpression();
        }else{
            free(expression);
            expression = ReadExpression();
        }
        switch(expression[0]){
            case '-':
                if(fHead->amount == 1){
                    printf("Número de operadores insuficiente!\n");
                }else{
                    if(expression[1] == '!'){
                        while(fHead->amount!=1){
                            num2 = PopFloat(fHead);
                            num1 = PopFloat(fHead);
                            PushFloat(fHead, (num1-num2));
                        }
                    }else{
                        num2 = PopFloat(fHead);
                        num1 = PopFloat(fHead);
                        PushFloat(fHead, (num1-num2));
                    }
                }
                break;
            case '+':
                if(fHead->amount == 1){
                    printf("Número de operadores insuficiente!\n");
                }else{
                    if(expression[1] == '!'){
                        while(fHead->amount!=1){
                            num2 = PopFloat(fHead);
                            num1 = PopFloat(fHead);
                            PushFloat(fHead, (num1+num2));
                        }
                    }else{
                        num2 = PopFloat(fHead);
                        num1 = PopFloat(fHead);
                        PushFloat(fHead, (num1+num2));
                    }
                }
                break;
            case '*':
                if(fHead->amount == 1){
                    printf("Número de operadores insuficiente!\n");
                }else{
                    if(expression[1] == '!'){
                        while(fHead->amount!=1){
                            num2 = PopFloat(fHead);
                            num1 = PopFloat(fHead);
                            PushFloat(fHead, (num1*num2));
                        }
                    }else{
                        num2 = PopFloat(fHead);
                        num1 = PopFloat(fHead);
                        PushFloat(fHead, (num1*num2));
                    }
                }
                break;
            case '/':
                if(fHead->amount == 1){
                    printf("Número de operadores insuficiente!\n");
                }else{
                    if(expression[1] == '!'){
                        while(fHead->amount!=1){
                            num2 = PopFloat(fHead);
                            num1 = PopFloat(fHead);
                            PushFloat(fHead, (num1/num2));
                        }
                    }else{
                        num2 = PopFloat(fHead);
                        num1 = PopFloat(fHead);
                        PushFloat(fHead, (num1/num2));
                    }
                }
                break;
            case 'c':
                if(fHead->amount == 1){
                    printf("Número de operadores insuficiente!\n");
                }else{
                    num2 = PopFloat(fHead);
                    num1 = PopFloat(fHead);
                    for(int i=0; i<num2;i++){
                        PushFloat(fHead, num1);
                    }
                }
                break;
            default:
                for(int i=0;i<strlen(expression);i++){
                    PushChar(sHead, expression[i]);
                }
                PushFloat(fHead,GetFloat(sHead));
                break;
        }
    }while(strcmp(expression,"sair")!=0);
    ClearFloatStack(fHead);
    free(sHead);
    free(expression);
    system("clear");
}

/**
 *  Invoca todas as funções necessárias para o funcionamento da resolução de expressão.
 *
 *  Primeiramente a expressão do usuário é informada, valida-se a expressão, caso inválida
 *  volta para o menu, caso válida transforma a expressão para sua forma posfixa e imprime
 *  tal expressão, obtem-se a resolução da expressão e imprime o valor final do resultado.
 */
void ExpressionResolver(){
    char* expression;
    char* postfix;
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
        free(expression);
        printf("Expressão inválida\n");
        printf("-----------------------------------------------\n");
    }
}
