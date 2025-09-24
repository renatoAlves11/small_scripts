#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int num;
    struct No * prox;
} Node;

typedef Node * noPtr;

typedef struct List{
    noPtr head;
} List;

typedef List * listPtr;

int empty(listPtr);
void add(int, listPtr*);
void out(int, listPtr*);
void list(listPtr);
listPtr newList();

void menu(){
    printf("\nO que você deseja fazer?\n0 - Parar programa\n1 - Adicionar elemento a lista\n2 - Retirar elemento da lista\n3 - Listar lista\n");
}

int main(){
    listPtr lista = newList();
    int op, n;
    do{
    menu();
    scanf(" %d", &op);
    switch(op){
        case 1:  
            printf("\nQual elemento adicionar?\n");
            scanf(" %d", &n);
            add(n, &lista);
            break;
        case 2:
            printf("\nQual elemento retirar?\n");
            scanf(" %d", &n);
            out(n, &lista);
            break;
        case 3:
            list(lista);
    }
    } while(op!=0);
    return 0;
}

void add(int n, listPtr* list){
    noPtr p = (noPtr)malloc(sizeof(Node));
    p->prox = NULL;
    p->num = n;
    if((*list)->head == NULL){
        (*list)->head = p;
    }
    else{
        noPtr aux = (*list)->head;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = p;
    }
}

void out(int n, listPtr* list){
    if(empty(*list)==1){
        printf("\nLista vazia\n");
    }
    else{
        if((*list)->head->num == n){
            noPtr aux = (*list)->head;
            (*list)->head = (*list)->head->prox;
            free(aux);
        }
        else{
            noPtr aux1 = (*list)->head;
            noPtr aux2 = aux1->prox;
            while(aux2->num != n && aux2!=NULL){
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
            if(aux2 != NULL){
                aux1->prox = aux2->prox;
                free(aux2);
            }
        }
    }
}

listPtr newList(){
    listPtr list = (listPtr) malloc(sizeof(List));
    list->head = NULL;
}

void list(listPtr list){
    if(empty(list) == 1){
        printf("\nLista vazia\n");
    }
    else{
        noPtr aux = list->head;
        while(aux != NULL){
            printf("%d\t", aux->num);
            aux = aux->prox;
        }
    }
}

int empty(listPtr list){
    if(list->head == NULL){
        return 1;
    }
    else return 0;
}