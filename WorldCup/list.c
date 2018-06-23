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
    team->name = (char*) malloc(sizeof(char)*strlen(_name)+1);
    strcpy(team->name,_name);
    team->attack = _attack;
    team->defense = _defense;
    team->resistance = _resistance;
    team->speed = _speed;

    return team;
}


L_element* ElementAlloc(Team* team){
    L_element* element = (L_element*) malloc(sizeof(L_element));

    element->team = team;
    element->next = NULL;
    element->previous = NULL;

    return element;
}

void InsertElement(L_element* element, List* list){
    element->next = list->first;

    if(list->first == NULL){
        list->first = element;
        list->last = element;
    }else{
        list->first->previous = element;
        list->first = element;
    }

    list->amount++;
}

List* ReadFile(char* file_name){
    List* list;
    list = ListAlloc();
    int attack, defense, resistance, speed, index, i, count_line,count_index, already_stored;
    setlocale(LC_CTYPE,"pt_BR.UTF-8");
    char line[100];
    char array_teams[32][100];
    int stored_index[16];
    char name[30];
    count_line = 0;
    count_index = 0;
    already_stored = 0;
    FILE * teams = fopen(file_name, "r");

    if(!teams)
        return NULL;


    while (fgets(line, 100, teams) != NULL) {
        strcpy(array_teams[count_line++],line);
    }

//    for(i = 0; i<32;i++){
//        printf("team : %s",array_teams[i]);
//    }

    while(list->amount != 16){
        index = rand() % 31;
        for(i = 0; i< count_index; i++){
            if(index == stored_index[i]){
                already_stored = 1;
                break;
            }else
                already_stored = 0;
        }
        if(!already_stored){
            stored_index[count_index++] = index;
            sscanf(array_teams[index], "%[^,] , %d , %d , %d , %d", name, &attack, &defense, &resistance, &speed);
            InsertElement(ElementAlloc(team_create(name,attack,defense,resistance,speed)),list);
        }
    }
    fclose(teams);
    return list;
}

void team_free(Team* team){
    free(team->name);
    free(team);
}


