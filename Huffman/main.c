#include <stdio.h>
#include "huffman.h"

int main() {
    char* str = "Brasil campeao";
    t_heap* heap = get_char_frequency(str);
    create_tree(heap);
    printf("Huffman tree (post order): \n");
    print_postorder(heap->array[0]);

    char* binary = encode_huffman(heap->array[0], str);
    printf("Binary output (encoded): %s\n", binary);

    char* str_decoded = decode_huffman(heap->array[0], binary, 8);
    printf("String output (decoded): %s\n", str_decoded);
    return 0;
}