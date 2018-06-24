/** @file tree.h
 *  @brief Define as funções de manipulação da árvore.
 *
 *  Arquivo que define todas as funções de criação e manipulação da arvore binária de 4 niveis utilizada.
 */
#ifndef WORLDCUP_TREE_H
#define WORLDCUP_TREE_H

#include "structs.h"

/** @brief Cria um nó da árvore.
 *  @return Retorna o endereço para estrutura t_node criada.
 */
t_node* node_create();

/** @brief Cria os níveis da árvore.
 *  @param depth Profundidade da árvore a ser criada.
 *  @return Retorna o endereço para a raiz da arvore de depth niveis.
 */
t_node* create_levels(int depth);

/** @brief Cria a árvore binaria de 4 niveis.
 *  @return Retorna o endereço para a raiz da arvore de 4 niveis.
 */
t_node* tree_create();

/** @brief Imprime os nós da árvore em pre ordem.
 *  @param root Nó raiz da arvore a ser imprimida.
 */
void tree_print_preorder(t_node* root);

/** @brief Libera a memória alocada da árvore.
 *  @param root Nó raiz da arvore a ser liberada.
 */
void tree_free(t_node* tree);

/** @brief Coloca os nós da árvore em uma estrutura heap.
 *  @param root Nó raiz da arvore.
 *  @param heap Estrutura heap.
 */
void heapfy_tree(t_node* root, t_heap* heap);

/** @brief Aloca e cria uma estrutura heap.
 *  @return Retorna o endereço da estrutura heap.
 */
t_heap* create_heap();


#endif
