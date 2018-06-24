#include "cup.h"
#include "list.h"
#include "tree.h"

/**
 *  Compara o valor do atributo definido por attribute do team_one com o do team_two, retornando o ponteiro para
 *  o time vencedor. Em caso de empate, o ponteiro para team_one é retornado.
 */
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

/**
 *  Imprime o resultado da rodada atribuida por round. Caso winner seja igual a player, imprime vitoria e sua respectiva
 *  partida, caso winner seja diferente de player, imprime derrota, terminando assim a copa para o usuario.
 */
void result_screen(Team *winner, Team *loser, Team *player, int attribute, int round){
    system("clear");
    switch(round){
        case 1:
            printf("Oitavas de final: Resultado\n");
            break;
        case 2:
            printf("Quartas de final: Resultado\n");
            break;
        case 3:
            printf("Semifinal: Resultado\n");
            break;
        case 4:
            printf("Final: Resultado\n");
            break;
        default:
            break;
    }
    if(winner == player && round != 4){
        printf("VITORIA\n");
        print_attribute(winner, loser, attribute);
        printf("%s ganhou a partida\n", winner->name);
        printf("Pressione ENTER para continuar\n");
        char ch = getchar();
        while(getchar() != '\n');
    }else if(winner == player && round == 4){
        printf("CAMPEAO\n");
        print_attribute(winner, loser, attribute);
        printf("%s ganhou a partida\n", winner->name);
    }else{
        printf("Derrota\n");
        print_attribute(winner, loser, attribute);
        printf("%s ganhou a partida\n", winner->name);
    }
}

/**
 *  Imprime os nomes e os respectivos atributos dos times fornecidos, team1 e team2.
 */
void print_attribute(Team *team1, Team *team2, int attribute){

    switch(attribute){
        case 1:
            printf("%s (Ataque %d) x %s (Ataque %d)\n", team1->name, team1->attack, team2->name, team2->attack);
            break;
        case 2:
            printf("%s (Defesa %d) x %s (Defesa %d)\n", team1->name, team1->defense, team2->name, team2->defense);
            break;
        case 3:
            printf("%s (Resistencia %d) x %s (Resistencia %d)\n", team1->name, team1->resistance, team2->name, team2->resistance);
            break;
        case 4:
            printf("%s (Velocidade %d) x %s (Velocidade %d)\n", team1->name, team1->speed, team2->name, team2->speed);

            break;
        default:
            break;
    }
}

/**
 *  Realiza a rodada fornecida por rounds. Para cada rodada, itera-se sobre os nos correspondetes da rodada (nivel),
 *  caso um dos nós seja o time do usuario, realiza a jogada do usuario atraves da função player_choice, guarda o valor
 *  do atributo escolhido no log das partidas, imprime o respectivo resultado atraves da funcao result_screen e reserva
 *  o vencedor em sua respectiva posição na estrutura heap.
 *
 *  Caso não seja encontrado o time do usuario, realiza uma partida entre os respectivos nós, escolhendo o atributo de
 *  maneira aleatória, e reservando o vencedor em sua respectiva posição na estrutura heap.
 */
void rounds(t_heap* heap,int rounds, Team* player, game_log* log){
    int i;
    static int player_choice;
    int ai_choice;
    switch(rounds){
        case 1:
            player_choice=0;
            for(i = (heap->size/2); i < heap->size; i=i+2){
                if(heap->array[i]->team == player){
                    player_choice =  player_match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 1);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 1);
                    }
                }else if(heap->array[i+1]->team == player){
                    player_choice =  player_match(heap->array[i+1]->team,heap->array[i]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 1);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 1);
                    }
                }else{
                    ai_choice = rand()%4+1;
                    log->choices[log->index++] = ai_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, ai_choice);
                }
            }
            break;
        case 2:
            for(i = (heap->size/4); i < (heap->size/2); i=i+2){
                if(heap->array[i]->team == player){
                    player_choice =  player_match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 2);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 2);
                    }
                }else if(heap->array[i+1]->team == player){
                    player_choice =  player_match(heap->array[i+1]->team,heap->array[i]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 2);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 2);
                    }
                }else{
                    ai_choice = rand()%4+1;
                    log->choices[log->index++] = ai_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,ai_choice);
                }
            }
            break;
        case 3:
            for(i = (heap->size/8); i < (heap->size/4); i=i+2){
                if(heap->array[i]->team == player){
                    player_choice =  player_match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 3);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 3);
                    }
                }else if(heap->array[i+1]->team == player){
                    player_choice =  player_match(heap->array[i+1]->team,heap->array[i]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 3);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 3);
                    }
                }else{
                    ai_choice = rand()%4+1;
                    log->choices[log->index++] = ai_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,ai_choice);

                }
            }
            break;
        case 4:
            for(i = (heap->size/16); i < (heap->size/8); i=i+2){
                if(heap->array[i]->team == player){
                    player_choice =  player_match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 4);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 4);
                    }
                }else if(heap->array[i+1]->team == player){
                    player_choice =  player_match(heap->array[i+1]->team,heap->array[i]->team, player_choice);
                    log->choices[log->index++] = player_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team, player_choice);
                    if(heap->array[(i-1)/2]->team == player){
                        log->round_player_lost = 0;
                        result_screen(heap->array[i + 1]->team, heap->array[i]->team, player, player_choice, 4);
                    }
                    else{
                        log->round_player_lost = rounds;
                        result_screen(heap->array[i]->team, heap->array[i + 1]->team, player, player_choice, 4);
                    }
                }else{
                    ai_choice = rand()%4+1;
                    log->choices[log->index++] = ai_choice;
                    heap->array[(i-1)/2]->team = match(heap->array[i]->team,heap->array[i+1]->team,ai_choice);
                }
            }
            break;

        default:
            break;
    }
}

/**
 *  Imprime os 16 times selecionados aleatoriamente do arquivo seguidos de um atributo aleatorio, permitindo que o
 *  usuario escolha um dos times para representa-lo.
 */
Team* choose_team(t_heap* heap){
    int i, counter, choice;
    do{
        counter = 1;
        system("clear");
        printf("Escolha seu time\n");
        printf("\n");
        for(i=heap->size/2; i<heap->size;i++){
            printf("Time %d :\n", counter++);
            print_random_attribute(heap->array[i]->team,rand()%4 + 1);
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

/**
 *  Imprime o atributo aleatorio fornecido do time.
 */
void print_random_attribute(Team* team, int attribute){
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

/**
 *  Realiza a respectiva partida do jogador, imprimindo suas opções de atributos baseado na sua escolha anterior, e o
 *  nome de seu oponente.
 *
 *  Retorna a opção de atributo escolhida pelo jogador.
 */
int player_match(Team* player, Team* enemy, int previous_choice){
    int choice;
    system("clear");
        switch(previous_choice){
            case 1:
                do{
                    printf("Seu time: %s\n", player->name);
                    printf("1) XX: XX\n");
                    printf("2) Defesa: %d\n", player->defense);
                    printf("3) Resistencia: %d\n", player->resistance);
                    printf("4) Velocidade: %d\n", player->speed);
                    printf("\n");
                    printf("Seu adversario: %s\n", enemy->name);
                    printf("\n");
                    printf("Selecione um atributo: ");
                    scanf("%d", &choice);
                    if(choice != 2 && choice != 3 && choice != 4){
                        system("clear");
                        printf("Selecione um dos atributos disponiveis a baixo\n");
                    }
                }while(choice != 2 && choice != 3 && choice != 4);
                break;
            case 2:
                do{
                    printf("Seu time: %s\n", player->name);
                    printf("1) Ataque: %d\n", player->attack);
                    printf("2) XX: XX\n");
                    printf("3) Resistencia: %d\n", player->resistance);
                    printf("4) Velocidade: %d\n", player->speed);
                    printf("\n");
                    printf("Seu adversario: %s\n", enemy->name);
                    printf("\n");
                    printf("Selecione um atributo: ");
                    scanf("%d", &choice);
                    if(choice != 1 && choice != 3 && choice != 4){
                        system("clear");
                        printf("Selecione um dos atributos disponiveis a baixo\n");
                    }
                }while(choice != 1 && choice != 3 && choice != 4);
                break;
            case 3:
                do{
                    printf("Seu time: %s\n", player->name);
                    printf("1) Ataque: %d\n", player->attack);
                    printf("2) Defesa: %d\n", player->defense);
                    printf("3) XX: XX\n");
                    printf("4) Velocidade: %d\n", player->speed);
                    printf("\n");
                    printf("Seu adversario: %s\n", enemy->name);
                    printf("\n");
                    printf("Selecione um atributo: ");
                    scanf("%d", &choice);
                    if(choice != 1 && choice != 2 && choice != 4){
                        system("clear");
                        printf("Selecione um dos atributos disponiveis a baixo\n");
                    }
                }while(choice != 1 && choice != 2 && choice != 4);
                break;
            case 4:
                do{
                    printf("Seu time: %s\n", player->name);
                    printf("1) Ataque: %d\n", player->attack);
                    printf("2) Defesa: %d\n", player->defense);
                    printf("3) Resistencia: %d\n", player->resistance);
                    printf("4) XX: XX\n");
                    printf("\n");
                    printf("Seu adversario: %s\n", enemy->name);
                    printf("\n");
                    printf("Selecione um atributo: ");
                    scanf("%d", &choice);
                    if(choice != 1 && choice != 2 && choice != 3){
                        system("clear");
                        printf("Selecione um dos atributos disponiveis a baixo\n");
                    }
                }while(choice != 1 && choice != 2 && choice != 3);
                break;
            default:
                do{
                    printf("Seu time: %s\n", player->name);
                    printf("1) Ataque: %d\n", player->attack);
                    printf("2) Defesa: %d\n", player->defense);
                    printf("3) Resistencia: %d\n", player->resistance);
                    printf("4) Velocidade: %d\n", player->speed);
                    printf("\n");
                    printf("Seu adversario: %s\n", enemy->name);
                    printf("\n");
                    printf("Selecione um atributo: ");
                    scanf("%d", &choice);
                    if(choice != 1 && choice != 2 && choice != 3 && choice != 4){
                        system("clear");
                        printf("Selecione um dos atributos disponiveis a baixo\n");
                    }
                }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
                break;
        }

    return choice;
}

/**
 *  Realiza a respectiva partida do jogador, imprimindo suas opções de atributos baseado na sua escolha anterior, e o
 *  nome de seu oponente.
 *
 *  Retorna a opção de atributo escolhida pelo jogador.
 */
void print_log(t_heap* heap, game_log* log) {
    int i,j;
    j = 0;
    printf("Jogos da Copa\n");
    printf("Oitavas de final:\n");
    for (i = (heap->size / 2); i < heap->size; i = i + 2) {
        print_attribute(heap->array[i]->team, heap->array[i+1]->team,log->choices[j++]);
    }

    if(log->round_player_lost == 1){
        return;
    }
    printf("\n");
    printf("Quartas de final:\n");
    for (i = (heap->size / 4); i < (heap->size/2); i = i + 2) {
        print_attribute(heap->array[i]->team, heap->array[i+1]->team,log->choices[j++]);
    }
    if(log->round_player_lost == 2){
        return;
    }
    printf("\n");
    printf("Semifinal:\n");
    for (i = (heap->size / 8); i < (heap->size/4); i = i + 2) {
        print_attribute(heap->array[i]->team, heap->array[i+1]->team,log->choices[j++]);
    }
    if(log->round_player_lost == 3){
        return;
    }
    printf("\n");
    printf("Final:\n");
    for (i = (heap->size / 16); i < (heap->size/8); i = i + 2) {
        print_attribute(heap->array[i]->team, heap->array[i+1]->team,log->choices[j++]);
    }
}

/**
 *  Imprime o menu para o usuario, e inicializa todos os passos necessarios para acontecer a copa como ler o arquivo,
 *  invocar as partidas das respectivas rodadas, imprimir o historico de partida entre outros.
 *
 */
void menu(){
    int choice, inner_choice;

    do{
        List* test;
        Team* player;
        t_node* root = tree_create();
        t_heap* heap = create_heap();
        game_log* log = (game_log*) malloc(sizeof(game_log));

        system("clear");
        printf("COPA 2018\n");
        printf("[1] Iniciar copa\n");
        printf("[2] Sair\n");
        printf("-> ");
        scanf("%d",&choice);
        switch(choice){
            case 1:

                test = read_file("teams.txt");

                L_element* ptr = test->first;

                heapfy_tree(root, heap);

                int i,leafs;
                leafs = heap->size/2;

                for(i=0; i<16;i++, ptr = ptr->next){
                    printf("team: %s\n", ptr->team->name);
                }

                ptr=test->first;
                for(i=0; i<16;i++, ptr = ptr->next){
                    heap->array[leafs++]->team = ptr->team;
                }

                log->index = 0;
                log->round_player_lost = 0;

                player = choose_team(heap);
                rounds(heap,1,player, log);
                rounds(heap,2,player, log);
                rounds(heap,3,player, log);
                rounds(heap,4,player, log);
                printf("\n");
                print_log(heap,log);
                do{
                    printf("\n");
                    printf("[1] Voltar ao menu principal\n");
                    printf("[2] Sair\n");
                    printf("->");
                    scanf("%d", &inner_choice);
                }while(inner_choice != 1 && inner_choice != 2);
                if(inner_choice == 1){
                    clear_game(heap,test,log);
                    break;
                }else{
                    choice = 2;
                    clear_game(heap,test,log);
                    break;
                }

            case 2:
                break;

            default:
                system("clear");
                printf("Escolha uma das opções a baixo\n");
                break;
        }
    }while(choice!=2);

}

/**
 *  Libera a memoria da arvore criada, libera a memoria da lista duplamente encadeada criada, libera a memoria
 *  da estrutura heap utilizada e por fim libera a memoria do historico de partidas.
 *
 */
void clear_game(t_heap* heap, List* list, game_log* log){
    tree_free(heap->array[0]);
    list_free(list);
    free(heap->array);
    free(heap);
    free(log);
}
