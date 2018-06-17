#include "huffman.h"

t_heap* allocate_heap(int capacity){
    t_heap* heap = (t_heap*)malloc(sizeof(t_heap));
    heap->amount = 0;
    heap->capacity = capacity;
    heap->array = (t_node**) malloc(sizeof(t_node*)*heap->capacity);;

    return heap;
}

t_node* allocate_node(char value, float freq){
    t_node* node = malloc(sizeof(node));
    node->value = value;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

t_heap* get_char_frequency(char* string){
    int freq[256] = {0};
    int capacity = 0;
    int j = 0;

    for(int i=0; i < strlen(string); i++){
        freq[(int)string[i]]++;
    }

    for(int i=0; i<256; i++){
        if(freq[i] > 0){
            capacity++;
        }
    }

    t_heap* heap = allocate_heap(capacity);

    for(int i=0; i<256; i++){
        if(freq[i] > 0){
            t_node* node = allocate_node((char) i,freq[i]);
            node->freq = node->freq / strlen(string);
            heap->array[j++] = node;
            heap->amount++;
        }
    }

    return heap;
}

void bubble_sort(t_heap* heap){
    t_node* aux;
    for(int i = 0; i < heap->amount - 1; i++){
        for(int j = 0; j < heap->amount - i - 1; j++){
            if(heap->array[j]->freq > heap->array[j+1]->freq){
                aux = heap->array[j];
                heap->array[j] = heap->array[j+1];
                heap->array[j+1] = aux;
            }
        }
    }
}
