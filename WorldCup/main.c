#include <stdio.h>
#include "list.h"

int main() {
    List* test;

    test = ReadFile("teams.txt");

    L_element* ptr = test->first;
    int i;
    for(i=0; i < test->amount; i++, ptr = ptr->next){
        printf("%s %d %d %d %d\n",ptr->team->name, ptr->team->attack, ptr->team->defense, ptr->team->resistance, ptr->team->speed);
    }
    return 0;
}