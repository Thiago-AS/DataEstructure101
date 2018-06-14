#ifndef WORLDCUP_CUP_H
#define WORLDCUP_CUP_H

#include "structs.h"

Team* team_create(char* _name, int _attack, int _defense, int _resistance, int _speed);

void team_free(Team* team);

//@TODO ask about attribute being int;
Team* match(Team* team_one, Team* team_two, int attribute);

void rounds(t_heap* heap ,int rounds);

#endif