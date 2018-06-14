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

void rounds(t_heap* heap,int rounds, Team* player){
    int i, player_choice = 0;
    switch(rounds){
        case 1:
            for(i = (heap->size/2); i < heap->size; i=i+2){
                if(heap->array[i]->team == player){
                    player_choice =  player_match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                }else if(heap->array[i+1]->team == player){
                    player_choice =  player_match(heap->array[i+1]->team,heap->array[i]->team, player_choice);
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                }else{
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,rand()%4+1);
                }
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

Team* choose_team(t_heap* heap){
    int i, counter, choice;
    do{
        counter = 1;
        system("clear");
        printf("Escolha seu time\n");
        printf("\n");
        for(i=heap->size/2; i<heap->size;i++){
            printf("Time %d :\n", counter++);
            print_attribute(heap->array[i]->team,rand()%4 + 1);
            printf("\n");
        }
        printf("-> ");
        scanf("%d",&choice);
        if(choice > 16 || choice < 1){
            system("clear");
            printf("Escolha um dos times a baixo\n");
        }
    }while(choice > 16 || choice < 1);

    return heap->array[(heap->size/2) + choice-1]->team;
}

void print_attribute(Team* team, int attribute){
    switch(attribute){
        case 1:
            printf("Ataque: %d  Defesa: ??  Resistencia: ??  Velocidade: ?? \n", team->attack);
            break;
        case 2:
            printf("Ataque: ??  Defesa: %d  Resistencia: ??  Velocidade: ?? \n", team->defense);
            break;
        case 3:
            printf("Ataque: ??  Defesa: ??  Resistencia: %d  Velocidade: ?? \n", team->resistance);
            break;
        case 4:
            printf("Ataque: ??  Defesa: ??  Resistencia: ??  Velocidade: %d \n", team->speed);
            break;
        default:
            break;
    }
}

int player_match(Team* player, Team* enemy, int previous_choice){
    int choice;
    system("clear");
    do{
        printf("Seu time: %s\n", player->name);
        switch(previous_choice){
            case 1:
                printf("1) XX: XX\n");
                printf("2) Defesa: %d\n", player->defense);
                printf("3) Resistencia: %d\n", player->resistance);
                printf("4) Velocidade: %d\n", player->speed);
                printf("Seu adversario: %s\n", enemy->name);
                printf("Selecione um atributo: ");
                scanf("%d", &choice);
                break;
            case 2:
                printf("1) Ataque: %d\n", player->attack);
                printf("2) XX: XX\n");
                printf("3) Resistencia: %d\n", player->resistance);
                printf("4) Velocidade: %d\n", player->speed);
                printf("Seu adversario: %s\n", enemy->name);
                printf("Selecione um atributo: ");
                scanf("%d", &choice);
                break;
            case 3:
                printf("1) Ataque: %d\n", player->attack);
                printf("2) Defesa: %d\n", player->defense);
                printf("3) XX: XX\n");
                printf("4) Velocidade: %d\n", player->speed);
                printf("Seu adversario: %s\n", enemy->name);
                printf("Selecione um atributo: ");
                scanf("%d", &choice);
                break;
            case 4:
                printf("1) Ataque: %d\n", player->attack);
                printf("2) Defesa: %d\n", player->defense);
                printf("3) Resistencia: %d\n", player->resistance);
                printf("4) XX: XX\n");
                printf("Seu adversario: %s\n", enemy->name);
                printf("Selecione um atributo: ");
                scanf("%d", &choice);
                break;
            default:
                printf("1) Ataque: %d\n", player->attack);
                printf("2) Defesa: %d\n", player->defense);
                printf("3) Resistencia: %d\n", player->resistance);
                printf("4) Velocidade: %d\n", player->speed);
                printf("\n");
                printf("Seu adversario: %s\n", enemy->name);
                printf("\n");
                printf("Selecione um atributo: ");
                scanf("%d", &choice);
                break;
        }
        if(choice > 4 || choice < 1){
            system("clear");
            printf("Selecione um dos atributos disponiveis a baixo\n");
        }
    }while(choice > 4 || choice < 1);

    return choice;
}
