/** @file stack.h
 *  @brief Define as pilhas utilizadas.
 *
 *  Arquivo que define as structs e as funções utilizadas para definir as pilhas.
 */

#ifndef CALCULADORA_STACK_H
#define CALCULADORA_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief Define os elementos da pilha de char.
 *
 *  Define uma struct que representa um elemento da pilha de char, tendo como
 *  elementos, o valor do char, e um ponteiro o próximo elemento.
 */
typedef struct stack{
    char value; /**< Valor do char armazenado.*/
    struct stack *next; /**< Ponteiro apontando para o próximo valor da pilha.*/
}stack; /**< Variável da struct stack*/

/** @brief Define o cabeçalho da pilha de char.
 *
 *  Define uma struct que representa o topo da pilha, onde temos um ponteiro
 *  sempre apontando para o topo da pilha.
 */
typedef struct header{
    struct stack* stack; /**< Ponteiro apontando para o topo da pilha*/
    int amount; /**< Guarda a quantidade de elementos armazenados na pilha*/
}header; /**< Variável da struct header*/

/** @brief Define os elementos da pilha de float.
 *
 *  Define uma struct que representa um elemento da pilha de float, tendo como
 *  elementos, o valor do float, e um ponteiro o próximo elemento.
 */
typedef struct float_stack{
    float value; /**< Valor do float armazenado.*/
    struct float_stack *next; /**< Ponteiro apontando para o próximo valor da pilha.*/
}float_stack; /**< Variável da struct float_stack*/

/** @brief Define o cabeçalho da pilha de float.
 *
 *  Define uma struct que representa o topo da pilha, onde temos um ponteiro
 *  sempre apontando para o topo da pilha.
 */
typedef struct float_header{
    struct float_stack* float_stack; /**< Ponteiro apontando para o topo da pilha*/
    int amount; /**< Guarda a quantidade de elementos armazenados na pilha*/
}float_header; /**< Variável da struct float_header*/

/** @brief Criar a pilha de char.
 *  @return Retorna o ponteiro apontando para a pilha criada.
 */
header* CreateStack();

/** @brief Cria a pilha de float.
 *  @return Retorna o ponteiro apontando para a pilha criada.
 */
float_header* CreateFloatStack();

/** @brief Insere elemento a pilha de char.
 *  @param sHead Cabeçalho que define a pilha a ser inserido o elemento.
 *  @param value Valor a ser inserido na pilha.
 */
void PushChar(header* sHead, char value);

/** @brief Remove elemento da pilha de char.
 *  @param sHead Cabeçalho que define a pilha a ser removido o elemento.
 *  @return Retorna o valor char salvo no elemento.
 */
char PopChar(header *sHead);

/** @brief Insere elemento a pilha de float.
 *  @param sHead Cabeçalho que define a pilha a ser inserido.
 *  @param value Valor a ser inserido na pilha.
 */
void PushFloat(float_header* sHead, float value);

/** @brief Remove elemento da pilha de float.
 *  @param sHead Cabeçalho que define a pilha a ser removido o elemento.
 *  @return Retorna o valor float salvo no elemento.
 */
float PopFloat(float_header* sHead);

/** @brief Imprime a pilha da base ao topo (forma inversa).
 *  @param sHead Cabeçalho que define a pilha a ser impressa.
 */
void InvertAndPrint(float_header* sHead);

/** @brief Libera todos os espaços de memória da pilha.
 *  @param sHead Cabeçalho que define a pilha a ser destruida.
 */
void ClearFloatStack(float_header* sHead);

#endif
