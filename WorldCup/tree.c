#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

t_node* node_create(){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->team = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

t_node* tree_create(int depth){
    static int l=0;
    t_node* node = node_create();
    node->team = NULL;
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

t_heap* create_heap(){
    t_heap* heap = (t_heap*) malloc(sizeof(t_heap*));
    heap->capacity = 31;
    heap->size = 0;
    heap->array = (t_node**) malloc(heap->capacity* sizeof(t_node*));

    return heap;
}