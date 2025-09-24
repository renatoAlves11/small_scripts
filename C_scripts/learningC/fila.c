#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *prox;
} no;

typedef struct no *noPtr;

typedef struct lista {
  noPtr topo;
  noPtr final;
} lista;

typedef struct lista* listaPtr;

int listaVazia1(noPtr topo1) {
  if (topo1 == NULL)
    return 1;
  else
    return 0;
}

void menu() {
  printf("Digite o que quer fazer:\n(0)Sair do programa\n(1)Enfileirar\n(2)Desenfileirar\n(3)Listar\n");
  printf("(4)Percorre\n(5)Quantos maior que N\n(6)Concatenar listas\n(7)Ordenar elementos\n");
  printf("(8)Retira elementos N\n");
}

void listar(noPtr *topo1) {
  int x = listaVazia1(*topo1);
  if (x == 1) {
    printf("Lista vazia bro\n");
  }
  if (x == 0) {
    noPtr aux;
    aux = *topo1;
    printf("Os elementos da fila são:\n");
    while (aux != NULL) {
      printf("%d\t", aux->valor);
      aux = aux->prox;
    }
    printf("\n");
  }
}

void enqueue(noPtr *topo1, noPtr *final1) {
  int x = listaVazia1(*topo1);
  noPtr p = (noPtr)malloc(sizeof(struct no));
  printf("Digite o valor do elemento:\n");
  scanf("%d", &p->valor);
  p->prox = NULL;
  if (x == 1) {
    *topo1 = p;
    *final1 = p;
  } else {
    (*final1)->prox = p;
    *final1 = p;
  }
}

void dequeue(noPtr *topo1, noPtr *final1) {
  noPtr p;
  int x = listaVazia1(*topo1);
  if (x == 1) {
    printf("Lista vazia bro\n");
  } else {
    p = *topo1;
    *topo1 = (*topo1)->prox;
    free(p);
    printf("O elemento foi retirado\n");
  }
}

int percorre(noPtr *topo1) {
  int x = 0;
  noPtr aux = *topo1;
  while (aux != NULL) {
    x++;
    aux = aux->prox;
  }
  return x;
}

int percorreMaiorN(noPtr *topo1) {
  int x, y = 0;
  printf("Maior do que qual numero?\n");
  scanf("%d", &x);
  noPtr aux = *topo1;
  while (aux != NULL) {
    if (aux->valor > x) {
      y++;
    }
    aux = aux->prox;
  }
  return y;
}

void concatena(noPtr *a, noPtr *b) {
  noPtr aux = *a, aux2 = *b, f;
  while (aux->prox != NULL) {
    aux = aux->prox;
  }
  aux->prox = *b;
  while (aux2->prox != NULL) {
    aux2 = aux2->prox;
  }
  aux = NULL;
  aux2 = NULL;
}

void bubbleList(noPtr *topo) {
  int aux;
  noPtr auxP = *topo, auxP1 = *topo;
  while (auxP != NULL) {
    while (auxP1 != NULL) {
      if (auxP->valor < auxP1->valor) {
        aux = auxP->valor;
        auxP->valor = auxP1->valor;
        auxP1->valor = aux;
      }
      auxP1 = auxP1->prox;
    }
    auxP = auxP->prox;
    auxP1 = auxP;
  }
}

void excluiN(noPtr *topo, int n)
{
  noPtr aux = *topo, aux2, p;
  int retirados=0;
  while (aux->prox != NULL)
  {
    aux2=aux->prox;
    if(aux->valor == n && aux == *topo)
    {
      p=aux;
      aux=aux->prox;
      aux2=aux->prox;
      *topo = (*topo)->prox;
      free(p);
      retirados++;
    }
    else if(aux2->valor == n)
    {
      aux2=aux2->prox;
      free(aux->prox);
      aux->prox=aux2;
      retirados++;
    }
    else if(aux!=NULL){
    aux=aux->prox;
    }
  }
  if(retirados==0) printf("Elemento não está presente na lista\n");
  else printf("%d nós retirados\n", retirados);
}

listaPtr criaLista ()
{
  listaPtr p = (listaPtr) malloc (sizeof(struct lista));
  p->topo=NULL;
  p->final=NULL;
}

void maiorSuc (noPtr *topo)
{
  noPtr aux=*topo, maior, prox;
  while (aux!=NULL)
  {
    if (aux==*topo) {
      maior=aux;
      prox=aux->prox;}
    else if (aux->valor>maior->valor) {
      maior=aux;
      prox=maior->prox;}
      aux=aux->prox;
  }
  if(maior==NULL) printf("Lista vazia bro\n");
  else if(prox==NULL) printf ("Maior = %d, não existe proximo\n", maior->valor);
  else printf("Maior = %d e proximo = %d\n"), maior->valor, prox->valor;
}

int main() {
  int op, x, y, n, z, a, b, qualL=0; listaPtr lis;
  noPtr topo1 = NULL;
  noPtr final1 = NULL;
  noPtr topo2 = NULL;
  noPtr final2 = NULL;
  do {
    menu();
    scanf("%d", &op);
    switch (op) {
    case 1:
      printf("Lista 1 ou 2?\n");
      scanf("%d", &n);
      if (n == 1)
        enqueue(&topo1, &final1);
      if (n == 2)
        enqueue(&topo2, &final2);
      break;
    case 2:
      printf("Lista 1 ou 2?\n");
      scanf("%d", &n);
      if (n == 1)
        dequeue(&topo1, &final1);
      if (n == 2)
        dequeue(&topo2, &final2);
      break;
    case 3:
      printf("Lista 1 ou 2?\n");
      scanf("%d", &n);
      if (n == 1)
        listar(&topo1);
      if (n == 2)
        listar(&topo2);
      break;
    case 4:
      printf("Lista 1 ou 2?\n");
      scanf("%d", &n);
      if (n == 1) {
        x = percorre(&topo1);
        printf("%d nós\n", x);
      }
      if (n == 2) {
        x = percorre(&topo2);
        printf("%d nós\n", x);
      }
      break;
    case 5:
      printf("Lista 1 ou 2?\n");
      scanf("%d", &n);
      if (n == 1) {
        y = percorreMaiorN(&topo1);
        printf("%d nós maiores que numero escolhido\n", y);
      }
      if (n == 2) {
        y = percorreMaiorN(&topo2);
        printf("%d nós maiores que numero escolhido\n", y);
      }
      break;
    case 6:
      concatena(&topo1, &topo2);
      printf("Lista 1 + Lista 2 = Lista 1\n");
      break;
    case 7:
      printf("Lista 1 ou 2?\n");
      scanf("%d", &z);
      if(z==1)
      bubbleList(&topo1);
      if(z==2)
      bubbleList(&topo2);
      break;
    case 8:
      printf("Retirar qual numero?\n");
      scanf("%d", &a);
      printf("De qual lista?\n");
      scanf("%d", &b);
      if (b==1){
      excluiN(&topo1, a);}
      if (b==2){
      excluiN(&topo2, a);}
      break;
    case 9:
      maiorSuc(&topo1);
    }
  } while (op != 0);
  return 0;
}