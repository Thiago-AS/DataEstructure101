#include <stdio.h>
#include "huffman.h"

int main() {
    char* str = "cachorro";
    t_heap* heap = get_char_frequency(str);
    print_array(heap);
    printf("\n");
    create_tree(heap);
    print_postorder(heap->array[0]);

    char* str_coded = "111001110100010100";
    char* str_decoded;
    str_decoded = decode_huffman(heap->array[0], str_coded, 8);
    printf("\n");
    puts(str_decoded);
    return 0;
}