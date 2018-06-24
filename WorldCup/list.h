#ifndef WORLDCUP_LIST_H
#define WORLDCUP_LIST_H

#include "structs.h"

List* ListAlloc();

L_element* ElementAlloc(Team* team);

List* ReadFile(char* file_name);

void InsertElement(L_element* element, List* list);

void list_free(List* list);

#endif
