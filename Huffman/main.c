#include <stdio.h>
#include "huffman.h"

int main() {
    char* str = "cachorro";
    t_heap* heap = get_char_frequency(str);
    for(int i = 0; i < heap->capacity; i++){
        printf("%c e %f \n", heap->array[i]->value, heap->array[i]->freq);
    }
    printf("\n");
    bubble_sort(heap);
    for(int i = 0; i < heap->capacity; i++){
        printf("%c e %f \n", heap->array[i]->value, heap->array[i]->freq);
    }
    return 0;
}