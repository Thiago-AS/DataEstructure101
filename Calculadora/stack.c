#include "stack.h"

/**
 *  Aloca o cabeçalho da pilha de char, setando o valor de amount para 0, e
 *  apontando o ponteiro stack para NULL.
 */
header* CreateStack(){
    header* sHead   = (header*) malloc(sizeof(header));
    sHead->stack    = NULL;
    sHead->amount   = 0;
    return sHead;
}

/**
 *  Aloca um elemento stack, insere o valor do parametro no elemento, aponta o
 *  ponteiro next para o topo da pilha, aponta o topo da pilha para o elemento
 *  criado e incrementa a quantidade de elementos na pilha.
 */
void PushChar(header* sHead, char value){
    stack *element  = (stack*) malloc(sizeof(stack));
    element->value  = value;
    element->next   = sHead->stack;
    sHead->stack    = element;
    sHead->amount++;
}

/**
 *  Checa se a pilha contém elementos, caso contenha, salva-se o valor do char em
 *  uma variável, aponta o topo da pilha para o próximo endereço, decrementa-se a
 *  quantidade de elementos da pilha (ammount) e libera-se a memória do elemento a ser
 *  retirado.
 *  Caso não exista elementos na pilha, retorna-se final de string '\0'.
 */
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

/**
 *  Aloca o cabeçalho da pilha de float, setando o valor de amount para 0, e
 *  apontando o ponteiro stack para NULL.
 */
float_header* CreateFloatStack(){
    float_header* sHead   = (float_header*) malloc(sizeof(float_header));
    sHead->float_stack    = NULL;
    sHead->amount   = 0;
    return sHead;
}

/**
 *  Aloca um elemento stack, insere o valor do parametro no elemento, aponta o
 *  ponteiro next para o topo da pilha, aponta o topo da pilha para o elemento
 *  criado e incrementa a quantidade de elementos na pilha.
 */
void PushFloat(float_header* sHead, float value){
    float_stack *element  = (float_stack*) malloc(sizeof(float_stack));
    element->value  = value;
    element->next   = sHead->float_stack;
    sHead->float_stack    = element;
    sHead->amount++;
}

/**
 *  Checa se a pilha contém elementos, caso contenha, salva-se o valor do float em
 *  uma variável, aponta o topo da pilha para o próximo endereço, decrementa-se a
 *  quantidade de elementos da pilha (ammount) e libera-se a memória do elemento a ser
 *  retirado.
 */
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

/**
 *  Defini-se um array de mesmo tamanho da quantidade de elementos da pilha. Itera-se
 *  sobre a pilha com um ponteiro, salvando todos os valores armazenados no array.
 *  Percorre-se o array de trás para frente imprimindo seus valores;
 */
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

/**
 *  Itera-se com um ponteiro sobre todos os elementos da pilha, liberando os espaços
 *  de memória. Por ultimo libera o espaço do cabeçalho da pilha.
 */
void ClearFloatStack(float_header* sHead){
    while(sHead->float_stack != NULL){
        float_stack* pointer;
        pointer = sHead->float_stack;
        sHead->float_stack = sHead->float_stack->next;
        free(pointer);
    }
    free(sHead);
}
