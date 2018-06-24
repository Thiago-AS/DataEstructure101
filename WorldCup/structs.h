/** @file structs.h
 *  @brief Define as estruturas utilizadas.
 *
 *  Arquivo que define todas as estruturas utilizadas ao longo do trabalho.
 *
 */
#ifndef WORLDCUP_STRUCTS_H
#define WORLDCUP_STRUCTS_H

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

/** @brief Define os times a serem representados.
 *
 *  Define uma struct que representa um time da copa, contendo seu nome e seus atributos.
 */
typedef struct team{
    char* name; /**< Nome do time.*/
    int attack; /**< Valor de ataque do time.*/
    int defense; /**< Valor de defesa do time.*/
    int resistance; /**< Valor de resistencia do time.*/
    int speed; /**< Valor de velocidade do time.*/
}Team; /**< Variável da struct team*/

/** @brief Define os elementos da lista.
 *
 *  Define uma struct que representa um elemento da lista duplamente encadeada a ser implementada
 *  , contendo o time e um ponteiro para o pŕoximo elemento, e o elemento anterior.
 */
typedef struct l_element{
    Team* team; /**< Struct do time.*/

    struct l_element* previous; /**< Elemento anterior.*/
    struct l_element* next; /**< Proximo elemento.*/
}L_element; /**< Variável da struct l_element*/

/** @brief Define o cabeçalho da lista.
 *
 *  Define uma struct que representa o cabeçalho da lista duplamente encadeada a ser implementada
 *  , contendo o primeiro elemento, ultimo elemento e a quantidade de elementos armazenada.
 */
typedef struct list{
    L_element* first; /**< Primeiro elemento.*/
    L_element* last; /**< Ultimo elemento.*/
    int amount; /**< Quantidade de elementos.*/
}List; /**< Variável da struct list*/

/** @brief Define o nó da árvore.
 *
 *  Define uma struct que representa o nó da árvore a ser implementada, contendo o time,
 *  o nó a esquerda e o nó a direita.
 */
typedef struct node{
    Team* team; /**< Struct do time*/
    struct node* left; /**< Filho esquerdo*/
    struct node* right; /**< Filho direito*/
}t_node;/**< Variável da struct node*/

/** @brief Define o cabeçalho de uma estrutura heap.
 *
 *  Define uma struct que representa o cabeçalho de uma estrutura heap, com o objetivo
 *  de representar a árvore binaria criada, facilitando assim sua manipulação.
 */
typedef struct heap{
    int size; /**< Quantidade de elementos*/
    int capacity; /**< Capacidade máxima*/
    t_node** array; /**< Array contendo os nós da arvore*/
}t_heap; /**< Variável da struct heap*/

/** @brief Define uma estrutura que armazena os eventos ocorridos.
 *
 *  Define uma struct que representa um historico das partidas ocorridas,
 *  com o objetivo de armazenar este log para depois ser mostrado.
 */
typedef struct game_log{
    int round_player_lost; /**< Etapa que o jogador perdeu*/
    int choices[15]; /**< Atributos selecionados*/
    int index; /**< Indice dos atributos selecionados*/
}game_log; /**< Variável da struct game_log*/

#endif
