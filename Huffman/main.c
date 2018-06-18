#include <stdio.h>
#include "huffman.h"

int main() {
    char* str = "bccabbddaeccbbaeddcc";
    t_heap* heap = get_char_frequency(str);
    print_array(heap);
    printf("\n");
    create_tree(heap);
    print_postorder(heap->array[0]);
    return 0;
}