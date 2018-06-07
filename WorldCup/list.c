#include "list.h"

List* ListAlloc(){
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->amount = 0;

    return list;
}

Element* ElementAlloc(char* name, int attack, int defense, int resistance, int speed){
    Element* element = (Element*) malloc(sizeof(Element));

    Team* team = (Team*) malloc(sizeof(Team));
    team->name = (char*) malloc(sizeof(char)*strlen(name));
    strcpy(team->name,name);
    team->attack = attack;
    team->defense = defense;
    team->resistance = resistance;
    team->speed = speed;

    element->team = team;
    element->next = NULL;
    element->previous = NULL;

    return element;
}

