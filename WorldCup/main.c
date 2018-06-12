#include <stdio.h>
#include "list.h"
#include "tree.h"

int main() {
//    List* test;
//
//    test = ReadFile("teams.txt");
//
//    L_element* ptr = test->first;
//    int i;
//    for(i=0; i < test->amount; i++, ptr = ptr->next){
//        printf("%s %d %d %d %d\n",ptr->team->name, ptr->team->attack, ptr->team->defense, ptr->team->resistance, ptr->team->speed);
//    }
    int depth;
    depth = 4;
    t_node* root = tree_create(4);

    tree_print_preorder(root);

    tree_free(root);
    return 0;
}