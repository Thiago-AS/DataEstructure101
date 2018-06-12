#ifndef WORLDCUP_LIST_H
#define WORLDCUP_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>


typedef struct team{
    char* name;
    int attack;
    int defense;
    int resistance;
    int speed;
}Team;

typedef struct l_element{
    Team* team;

    struct l_element* previous;
    struct l_element* next;
}L_element;

typedef struct list{
    L_element* first;
    L_element* last;
    int amount;
}List;

List* ListAlloc();

L_element* ElementAlloc(Team* team);

Team* team_create(char* _name, int _attack, int _defense, int _resistance, int _speed);

List* ReadFile(char* file_name);

void InsertElement(L_element* element, List* list);

void team_free(Team* team);

#endif
