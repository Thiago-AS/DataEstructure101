#include "list.h"
#include "tree.h"
#include "cup.h"
#include "time.h"

void menu(){
    srand(time(NULL));

    int choice;
    List* test;
    Team* player;
    do{
        printf("COPA 2018\n");
        printf("[1] Iniciar copa\n");
        printf("[2] Sair\n");
        printf("-> ");
        scanf("%d",&choice);
        switch(choice){
            case 1:

                test = ReadFile("teams.txt");

                L_element* ptr = test->first;
                t_node* root = tree_create(4);

                t_heap* heap = create_heap();
                heapfy_tree(root, heap);

                int i,leafs;
                leafs = heap->size/2;

                for(i=0; i<16;i++, ptr = ptr->next){
                    heap->array[leafs++]->team = ptr->team;
                }
                ptr = test->first;

                for(i=heap->size/2; i<heap->size;i++){
                    printf("team %d: %s  atack: %d \n", i ,heap->array[i]->team->name, heap->array[i]->team->attack);
                }

//                rounds(heap,1);
//
//                for(i=heap->size/4; i<heap->size/2;i++){
//                    printf("winners first fase: %s  \n", heap->array[i]->team->name);
//                }
//
//                rounds(heap,2);
//
//                for(i=heap->size/8; i<heap->size/4;i++){
//                    printf("winners second fase: %s  \n", heap->array[i]->team->name);
//                }
//
//                rounds(heap,3);
//
//                for(i=heap->size/16; i<heap->size/8;i++){
//                    printf("winners third fase: %s  \n", heap->array[i]->team->name);
//                }
//
//                rounds(heap,4);
//                printf("BIG WINNER: %s  \n", heap->array[0]->team->name);

                player = choose_team(heap);
                rounds(heap,1,player);
                break;

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

    menu();
    return 0;
}