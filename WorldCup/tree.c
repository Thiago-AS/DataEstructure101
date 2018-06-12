#include "tree.h"

t_node* node_create(){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->team = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}
