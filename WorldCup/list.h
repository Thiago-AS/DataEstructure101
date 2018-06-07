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

typedef struct element{
    Team* team;

    struct element* previous;
    struct element* next;
}Element;

typedef struct list{
    Element* first;
    Element* last;
    int amount;
}List;

List* ListAlloc();

Element* ElementAlloc(char* name, int attack, int defense, int resistance, int speed);

List* ReadFile(char* file_name);

#endif
