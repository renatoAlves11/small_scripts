#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node * prox;
    struct node * ant;
} Node;

typedef Node * noPtr;

void add (noPtr *, noPtr *, int);
void listar (noPtr);

int main ()
{
    int x, op;
    noPtr head = NULL;
    noPtr end = NULL;
    do{
        scanf("%d", &op);
        switch(op){
            case 1:
            printf("\nO que quer adicionar?\n");
            scanf("%d", &x);
            add(&head, &end, x); break;
            case 2:
            listar(head); break;
        }
    }while (op != 0);
    return 0;
}

void add (noPtr *head, noPtr *end, int x){
    noPtr p = (noPtr)malloc(sizeof(Node));
    p->prox = NULL;
    p->ant = NULL;
    p->num = x;
    if (*end == NULL){
    p->prox = p;
    p->ant = p;
    *head = p;
    *end = p;
    }
    else{
    p->prox = *head;
    p->ant = *end;
    (*end)->prox = p;
    (*head)->ant = p;
    *end = p;
    }
}

void listar(noPtr head){
    noPtr aux = head;
    while (aux != head){
    printf ("%d\n", aux->num);
    aux = aux->prox;
    }
}