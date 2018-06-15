#ifndef WORLDCUP_CUP_H
#define WORLDCUP_CUP_H

#include "structs.h"

Team* team_create(char* _name, int _attack, int _defense, int _resistance, int _speed);

void team_free(Team* team);

Team* match(Team* team_one, Team* team_two, int attribute);

void rounds(t_heap* heap ,int rounds, Team* player);

Team* choose_team(t_heap* heap);

void print_attribute(Team* team, int attribute);

int player_match(Team* player, Team* enemy, int previous_choice);

void result_screen(Team* winner, Team* loser, Team* player, int attribute, int round);


#endif