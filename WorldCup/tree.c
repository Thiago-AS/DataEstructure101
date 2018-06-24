#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

/**
 *  Aloca a estrutura node dinamicamente, apontando todos seus atributos para NULL. Retorna o endereço para a estrutura.
 */
t_node* node_create(){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->team = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/**
 *  Cria um nó e para cada nó a esquerda e direita, cria uma subarvore de maneira recurssiva de profundidade depth - 1.
 *  Quando depth = 0 (Atingida profundidade desejada), retorna-se os endereços dos nós, definindo assim na volta da
 *  recurssão os nós a direi e a esquerda.
 *
 *  Retorna o endereço do nó raiz.
 */
t_node* create_levels(int depth){
    t_node* node = node_create();
    node->team = NULL;
    if(depth == 0){
        return node;
    }else{
        node->left = create_levels(depth-1);
        node->right = create_levels(depth-1);
    }

    return node;
}

/**
 *  Invoca a funçã que cria de maneira recurssiva os niveis, passando como parametro a quantidade de niveis desejados.
 *  Retorna o nó raiz da arvore criada.
 */
t_node* tree_create(){
    return create_levels(4);
}

/**
 *  Percorre a árvore de maneira recurssiva pre-fixamente, onde para cada visita de nó, verifica-se se existe um time
 *  alocado, caso exista, este é imprimido na tela.
 */
void tree_print_preorder(t_node* root){
    if(root != NULL){
        if(root->team != NULL){
            printf("nome: %s ataque: %d defesa: %d resistencia: %d velocidade: %d\n", root->team->name,root->team->attack
            , root->team->defense, root->team->resistance, root->team->speed);
        }
        tree_print_preorder(root->left);
        tree_print_preorder(root->right);
    }
}

/**
 *  Percorre a árvore de maneira recurssiva pre-fixamente, onde a cada visita libera-se a memoria alocada dinamicamente
 *  do nó.
 */
void tree_free(t_node* tree){
    if(tree!=NULL){
        tree_free(tree->left);
        tree_free(tree->right);
        free(tree);
    }
}

/**
 *  Percorre a arvore salvando os nós filhos em suas respectivas posições na estrutura heap (Nó a esquerda = 2*i+1
 *  Nó a direita = 2*i+2).
 */
void heapfy_tree(t_node* root, t_heap* heap){
    int i;
    i = 0;
    heap->array[i] = root;
    heap->size++;
    while(heap->size != 31){
        if(heap->array[i]->left != NULL){
            heap->array[(2*i)+1] = heap->array[i]->left;
            heap->size++;
        }
        if(heap->array[i]->right != NULL){
            heap->array[(2*i)+2] = heap->array[i]->right;
            heap->size++;
        }
        i++;
    }

}

/**
 *  Aloca dinamicamente a estrutura t_heap, tendo como como atributo size 0, capacity 31 (Quantidade total de nós na
 *  arvore binaria de 4 niveis) e alocando o array que guarda os nós.
 *
 *  Retorna o endereço da estrutura alocada.
 */
t_heap* create_heap(){
    t_heap* heap = (t_heap*) malloc(sizeof(t_heap));
    heap->capacity = 31;
    heap->size = 0;
    heap->array = (t_node**) malloc(heap->capacity * sizeof(t_node*));

    return heap;
}