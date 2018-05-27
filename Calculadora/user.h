/** @file user.h
 *  @brief Define as iterações com o usuário.
 *
 *  Arquivo que define as funções em que o usuário interage com o programa diretamente.
 */

#ifndef CALCULADORA_USER_H
#define CALCULADORA_USER_H

#include "expression.h"
#include "stack.h"

/** @brief Lê a entrada digitada pelo usuário.
 *  @return Retorna um ponteiro de char guardando a string digitada.
 */
char* ReadExpression();

/** @brief Gera um menu para o usuário.
 */
void Menu();

#endif
