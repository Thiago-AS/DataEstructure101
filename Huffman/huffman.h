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

void swap(t_node* node1, t_node* node2);

#endif
