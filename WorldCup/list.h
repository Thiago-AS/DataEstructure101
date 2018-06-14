#ifndef WORLDCUP_LIST_H
#define WORLDCUP_LIST_H

#include "structs.h"

List* ListAlloc();

L_element* ElementAlloc(Team* team);

//@TODO ask about random function to get random line from text file;
List* ReadFile(char* file_name);

void InsertElement(L_element* element, List* list);

#endif
