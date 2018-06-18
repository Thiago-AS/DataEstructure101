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

void print_array(t_heap* heap){
    for(int i=0; i<heap->amount;i++){
        printf("%c e %f \n", heap->array[i]->value, heap->array[i]->freq);
    }
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

void create_tree(t_heap* heap){
    while(heap->array[0]->freq != 1){
        bubble_sort(heap);
        t_node* new_node = allocate_node('$',heap->array[0]->freq + heap->array[1]->freq);
        new_node->left = heap->array[0];
        new_node->right = heap->array[1];
        heap->amount--;
        heap->array[0] = new_node;
        heap->array[1] = NULL;
        remove_null(heap);
    }
}

void remove_null(t_heap* heap){
    for(int i = 1; i < heap->amount; i++){
        if(i == heap->amount)
            heap->array[i] = NULL;
        else
            heap->array[i] = heap ->array[i+1];
    }
}

void print_postorder(t_node* root){
    if(root!=NULL){
        printf("%c e %f\n", root->value, root->freq);
        print_postorder(root->left);
        print_postorder(root->right);
    }
}

