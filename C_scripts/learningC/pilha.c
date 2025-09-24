#include <stdio.h>
#include <stdlib.h>
typedef struct no {
  int info;
  struct no *prox;
} no;
typedef struct no *noPtr;
noPtr topo = NULL;
void menu() {
  printf(
      "Digite o que quer fazer:\n(1)-Empilhar\n(2)-Desempilhar\n(3)-Listar\n");
}
void listar() {
  noPtr aux = topo;
  printf("Do último ao primeiro elemento:\n");
  while (aux != NULL) {
    printf("%i\t", aux->info);
    aux = aux->prox;
  }
  printf("\n");
}
int listaVazia() {
  if (topo == NULL)
    return 0;
  else
    return 1;
}
void push() {
  noPtr p;
  int valor;
  p = (noPtr)malloc(sizeof(struct no));
  printf("Digite valor do elemento:\n");
  scanf("%d", &valor);
  p->info = valor;
  p->prox = topo;
  topo = p;
}
void pop() {
  noPtr p = topo;
  int x = listaVazia();
  if (x != 0) {
    topo = p->prox;
    free(p);
    printf("O elemento foi retirado da pilha\n");
  } else
    printf("Lista vazia\n");
}
int main() {
  int op;
  do {
    menu();
    scanf("%d", &op);
    switch (op) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      listar();
      break;
    }
  } while (op != 0);
  return 0;
}