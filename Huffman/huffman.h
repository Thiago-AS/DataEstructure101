#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node{
    char value;
    float  freq;
    struct t_node* left;
    struct t_node* right;
}t_node;

typedef struct t_heap{
    int amount;
    int capacity;
    t_node** array;
}t_heap;

t_heap* get_char_frequency(char* string);

t_heap* allocate_heap(int capacity);

t_node* allocate_node(char value, float freq);

void bubble_sort(t_heap* heap);

void create_tree(t_heap* heap);

void remove_null(t_heap* heap);

void print_postorder(t_node* root);

void print_array(t_heap* heap);

char* decode_huffman(t_node* root, char* string, int len);

char* encode_huffman(t_node* root, char* string);

void find_char_code(t_node* root, char c, int len, char* code, char* out);


#endif
