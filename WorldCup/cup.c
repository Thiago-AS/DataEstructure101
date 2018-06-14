#include "cup.h"

Team* match(Team* team_one, Team* team_two, int attribute){
    switch(attribute){
        case 1:
            if(team_one->attack < team_two->attack)
                return team_two;
            break;
        case 2:
            if(team_one->defense < team_two->defense)
                return team_two;
            break;
        case 3:
            if(team_one->resistance < team_two->resistance)
                return team_two;
            break;
        case 4:
            if(team_one->speed < team_two->speed)
                return team_two;
            break;
        default:
            break;
    }

    return team_one;
}

void rounds(t_heap* heap,int rounds){
    int i;
    switch(rounds){
        case 1:
            for(i = (heap->size/2); i < heap->size; i=i+2){
                heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,1);
            }
            break;
        case 2:
            for(i = (heap->size/4); i < (heap->size/2); i=i+2){
                heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,1);
            }
            break;
        case 3:
            for(i = (heap->size/8); i < (heap->size/4); i=i+2){
                heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,1);
            }
            break;
        case 4:
            for(i = (heap->size/16); i < (heap->size/8); i=i+2){
                heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,1);
            }
            break;

        default:
            break;
    }
}
