#include "list.h"
#include "tree.h"
#include "cup.h"
#include "time.h"

void menu(){
    int choice, inner_choice;
    List* test;
    Team* player;
    do{
        system("clear");
        printf("COPA 2018\n");
        printf("[1] Iniciar copa\n");
        printf("[2] Sair\n");
        printf("-> ");
        scanf("%d",&choice);
        switch(choice){
            case 1:

                test = ReadFile("teams.txt");

                L_element* ptr = test->first;
                t_node* root = tree_create();

                t_heap* heap = create_heap();
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

                game_log* log = (game_log*) malloc(sizeof(game_log));
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
                    break;
                }else{
                    choice = 2;
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

int main() {
    srand(time(NULL));
    menu();
    return 0;
}