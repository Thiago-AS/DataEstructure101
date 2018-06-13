#ifndef WORLDCUP_TREE_H
#define WORLDCUP_TREE_H

#include "list.h"

typedef struct node{
    Team* team;
    struct node* left;
    struct node* right;
}t_node;

typedef struct heap{
    int size;
    int capacity;
    t_node** array;
}t_heap;

t_node* node_create();

//@TODO: Ask about recursivly function without parameters
t_node* tree_create(int depth);

void tree_free(t_node* tree);

void tree_print_preorder(t_node* root);

void heapfy_tree(t_node* root, t_heap* heap);

t_heap* create_heap();


#endif
