#ifndef WORLDCUP_STRUCTS_H
#define WORLDCUP_STRUCTS_H

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

typedef struct node{
    Team* team;
    struct node* left;
    struct node* right;
}t_node;

typedef struct heap{
    int size;
    int capacity;
    t_node** array;
}t_heap;

typedef struct game_log{
    int round_player_lost;
    int choices[15];
    int index;
}game_log;

#endif
