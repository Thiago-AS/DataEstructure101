#include "list.h"

/**
 *  Aloca a estrutura team dinamicamente, incializando os atributos nome, ataque, defesa, resistencia e velocidade por
 *  cópia. Ao final retorna o endereço para estrutura Team alocada
 */
Team* team_create(char* _nome, int _ataque, int _defesa, int _resistencia, int _velocidade){
    Team* team = (Team*) malloc(sizeof(Team));
    team->name = (char*) malloc(sizeof(char)* (strlen(_nome)+1));
    strcpy(team->name,_nome);
    team->attack = _ataque;
    team->defense = _defesa;
    team->resistance = _resistencia;
    team->speed = _velocidade;

    return team;
}

/**
 *  Aloca a estrutura List dinamicamente, tendo como quantidade 0 e apontando o primeiro e ultimo elemento para NULL.
 *  Retorna o endereço para estrutura List alocada.
 */
List* list_alloc(){
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->amount = 0;

    return list;
}

/**
 *  Aloca a estrutura L_element dinamicamente, tendo como time o parametro team fornecido e os ponteiros para o proximo
 *  elemento e o elemento anterior como NULL. Retorna o endereço para estrutura L_element alocada.
 */
L_element* element_alloc(Team *team){
    L_element* element = (L_element*) malloc(sizeof(L_element));

    element->team = team;
    element->next = NULL;
    element->previous = NULL;

    return element;
}

/**
 *  Aloca-se primeiramente uma lista duplamente encadeada, lê-se o arquivo fornecido armazenando todas as linhas em um
 *  array de strings.
 *
 *  Escolhe-se de forma aleatoria o indice, itera-se sobre um array suporte que guarda os indices ja armazenados,
 *  caso o indice não tenha sido escolhido, inseri-se o indice no array suporte e aloca o elemento na lista criada.
 *  Repete-se o passo até que exista 16 elementos na lista.
 *
 *  Após escolher aleatoriamente os times, fecha-se o arquivo e retorna o endereço da lista contendo os 16 times.
 */
List* read_file(char *file_name){
    List* list;
    list = list_alloc();
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
            insert_element(element_alloc(team_create(name, attack, defense, resistance, speed)), list);
        }
    }
    fclose(teams);
    return list;
}

/**
 *  Inseri um elemento na lista duplamente encadeada previamente alocada. Caso não exista elementos, o primeiro e ultimo
 *  elemento são o elemento de parametro, case exista, inseri no inicio da lista.
 */
void insert_element(L_element *element, List *list){
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

/**
 *  Libera todos os espaços de memoria da lista duplamente encadeada iterando sobre a lista,e dando free nos elementos
 *  que ela compõe, e por fim, libera a lista em si (cabeçalho).
 */
void list_free(List* list){
    L_element* ptr = list->first;

    if(list->first != NULL && list->last != NULL){
        while(ptr != NULL){
            list->first = list->first->next;
            team_free(ptr->team);
            free(ptr);
            ptr = list->first;
        }
    }

    free(list);
}

/**
 *  Libera a memoria da estrutura team, liberando tambem o ponteiro de char que guarda a string do nome do time.
 */
void team_free(Team* team){
    free(team->name);
    free(team);
}



