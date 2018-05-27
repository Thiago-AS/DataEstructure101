/** @file expression.h
 *  @brief Define as funções de resolução de expressões e Calculadora.
 *
 *  Arquivo que define as funções utilizadas quanto ao ambito de resolução matemática
 *  do programa.
 */

#ifndef CALCULADORA_EXPRESSION_H
#define CALCULADORA_EXPRESSION_H

#include "stack.h"

#define TRUE 1
#define FALSE 0

/** @brief Valida a expressão digitada pelo usuário.
 *  @param expression Expressão matemática infixa.
 *  @return Retorna 1 caso expressão seja válida, ou 0 caso seja inválida.
 */
int ValidateInfix(char* expression);

/** @brief Transforma uma expressão infixa para posfixa.
 *  @param expression Expressão matemática infixa.
 *  @return Retorna um ponteiro de char contendo a string com a expressão posfixa.
 */
char* InfixToPosFix(char * expression);

/** @brief Soluciona expressão posfixa.
 *  @param expression Expressão matemática posfixa.
 *  @return Retorna o valor da expressão em float.
 */
float PostFixValue(char * expression);

/** @brief Converte um valor em string para um valor em float.
 *  @param sHead Pilha contendo valor em char.
 *  @return Retorna o valor em float.
 */
float GetFloat(header* sHead);

/** @brief Invoca as ações do modo calculadora em pilha.
 */
void Calculator();

/** @brief Invoca as ações do modo de resolução de expressões.
 */
void ExpressionResolver();

#endif
