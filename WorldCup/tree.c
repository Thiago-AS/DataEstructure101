#include "tree.h"

t_node* node_create(){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->team = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//@TODO: Ask about recursivly function without parameters
t_node* tree_create(int depth){
    t_node* node = node_create();
    node->team = team_create("lael",12,12,12,12);
    if(depth == 0){
        return node;
    }else{
        node->left = tree_create(depth-1);
        node->right = tree_create(depth-1);
    }

    return node;
}

void tree_print_preorder(t_node* root){
    if(root != NULL){
        printf("%d\n", root->team->attack);
        tree_print_preorder(root->left);
        tree_print_preorder(root->right);
    }
}


void tree_free(t_node* tree){
    if(tree!=NULL){
        tree_free(tree->left);
        tree_free(tree->right);
        team_free(tree->team);
        free(tree);
    }
}