#include "list.h"

List* ListAlloc(){
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->amount = 0;

    return list;
}

Team* team_create(char* _name, int _attack, int _defense, int _resistance, int _speed){
    Team* team = (Team*) malloc(sizeof(Team));
    team->name = (char*) malloc(sizeof(char)*strlen(_name));
    strcpy(team->name,_name);
    team->attack = _attack;
    team->defense = _defense;
    team->resistance = _resistance;
    team->speed = _speed;

    return team;
}


Element* ElementAlloc(Team* team){
    Element* element = (Element*) malloc(sizeof(Element));

    element->team = team;
    element->next = NULL;
    element->previous = NULL;

    return element;
}

