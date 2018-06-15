#ifndef WORLDCUP_TREE_H
#define WORLDCUP_TREE_H

#include "structs.h"
#include "cup.h"


t_node* node_create();

t_node* tree_create();

void tree_free(t_node* tree);

void tree_print_preorder(t_node* root);

void heapfy_tree(t_node* root, t_heap* heap);

t_heap* create_heap();


#endif
