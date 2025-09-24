#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

typedef struct no {
  char nome[TAM];
  int nota;
  struct no *prox;
  struct no *ant;
} jogo;

typedef struct no *jogoPtr;

typedef struct lista {
  jogoPtr topo;
  jogoPtr final;
} lista;

int validaEntrada(); // valida entradas indesejadas de scanf

int menu(); // oferece as opções que o usuário tem para interagir com a
            // biblioteca de jogos

void troca(jogoPtr A[], int a, int b); // troca elementos de um array

int vazia(
    lista x); // verifica se lista está vazia (retorna 1) ou não (retorna 0)

int verificar(lista biblioteca,
              char jogo[]); // verifica se um jogo já está na biblioteca

void addJogo(
    lista *biblioteca, int nota,
    char nome[]); // adiciona jogo na biblioteca (do arquivo e novos jogos)

void removeJogo(lista *biblioteca, int *cont,
                int total); // remove jogo da biblioteca

void mostraBib(lista biblioteca); // mostra jogos na biblioteca

void array(lista *biblioteca, jogoPtr A[], int sinal,
           int cont); // passa elementos da lista para array e vice-versa

void ordena(lista *biblioteca, int cont); // ordena biblioteca

void procura(lista biblioteca, int total); // procura jogo da biblioteca

void edita(lista *biblioteca, int total); // edita jogo da biblioteca

void adicionaNovo(lista *biblioteca,
                  int *cont); // adiciona jogo novo na biblioteca

void getArquivo(FILE *arquivo, lista *biblioteca,
                int *cont); // passa jogos do arquivo para a lista

int main() {
  lista biblioteca;
  biblioteca.topo = NULL;
  biblioteca.final = NULL;
  int cont = 0, opcao;
  FILE *arquivo;
  arquivo = fopen("bibGames.txt", "r+");
  if (arquivo == NULL) {
    arquivo = fopen("bibGames.txt", "w+");
    if (arquivo == NULL)
    printf("deu ruim");
  } else {
    getArquivo(arquivo, &biblioteca, &cont);
    rewind(arquivo);
    fclose(arquivo);
  }
  printf("Bem vindo a sua lista de jogos!!!\n\n");
  printf("O que você gostaria de fazer hoje?\n");
  do {
    opcao = menu();
    switch (opcao) {
    case 1:
      adicionaNovo(&biblioteca, &cont);
      break;
    case 2:
      mostraBib(biblioteca);
      break;
    case 3:
      removeJogo(&biblioteca, &cont, cont);
      break;
    case 4:
      ordena(&biblioteca, cont);
      break;
    case 5:
      procura(biblioteca, cont);
      break;
    case 6:
      edita(&biblioteca, cont);
    }
  } while (opcao != 0);
  jogoPtr aux = biblioteca.topo;
  arquivo = fopen("bibGames.txt", "w");
  while (aux != NULL) {
    fprintf(arquivo, "%s %d\n", aux->nome, aux->nota);
    aux = aux->prox;
  }
  fclose(arquivo);
  return 0;
}

void adicionaNovo(lista *biblioteca, int *cont) {
  int nota, verifica;
  char nome[TAM];
  (*cont)++;
  printf("\nQual o nome do jogo?\n");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = '\0';
  verifica = verificar(*biblioteca, nome);
  if (verifica == 1)
    printf("\nJogo %s já está na biblioteca!\n", nome);
  else {
    printf("\nQual nota de 0 a 10 você dá pro jogo?\n");
    nota = validaEntrada();
    while (nota < 0 || nota > 10) {
      printf("\nNota inválida, digite novamente\n");
      nota = validaEntrada();
    }
    addJogo(biblioteca, nota, nome);
  }
}

void edita(lista *biblioteca, int total) {
  int indice, contador = 1, x = vazia(*biblioteca);
  jogoPtr aux = (*biblioteca).topo;
  if (x == 1) {
    printf("\nVocê ainda não tem jogos adicionados a sua biblioteca!\n");
  } else {
    printf("\nQual jogo você quer editar?\nDigite o índice do jogo:\n");
    indice = validaEntrada();
    if (indice < 1 || indice > total)
      printf("\nIndíce inválido, nenhum jogo encontrado\n");
    else {
      while (aux->prox != NULL && indice != contador) {
        contador++;
        aux = aux->prox;
      }
      printf("\nDigite novo nome do jogo:\n");
      fgets(aux->nome, sizeof(aux->nome), stdin);
      aux->nome[strcspn(aux->nome, "\n")] = '\0';
      printf("\nDigite nova nota:\n");
      aux->nota = validaEntrada();
      while (aux->nota < 0 || aux->nota > 10) {
        printf("\nNota inválida, digite novamente\n");
        aux->nota = validaEntrada();
      }
    }
  }
}

void procura(lista biblioteca, int total) {
  jogoPtr aux = biblioteca.topo;
  int test, indice = 1, x = vazia(biblioteca);
  char busca[TAM];
  if (x == 1)
    printf("\nVocê ainda não tem jogos adicionados na biblioteca!\n");
  else {
    printf("\nQual jogo você está procurando?\n");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';
    while ((strcmp(aux->nome, busca) != 0) && aux->prox != NULL) {
      aux = aux->prox;
      indice++;
    }
    if (indice == total && (strcmp(aux->nome, busca) != 0)) {
      printf("\nJogo não está na biblioteca!\n");
    } else
      printf("\nO jogo está presente na posição %d da "
             "lista!\nNome:%s\nNota:%d\n",
             indice, busca, aux->nota);
  }
}

void ordena(lista *biblioteca, int cont) {
  jogoPtr aux = (*biblioteca).topo, A[cont];
  int sinal = 0, escolha, x = vazia(*biblioteca);
  if (x == 1)
    printf("\nVocê ainda não tem jogos adicionados na biblioteca!\n");
  else {
    printf("\nQual a forma de ordenação desejada?\n");
    printf(
        "(0) - Cancelar ordenação\n(1) - Ordem alfabética 'A' até 'Z'\n(2) - "
        "Ordem alfabética 'Z' até "
        "'A'\n(3) - Ordem crescente de nota\n(4) - Ordem decrescente de "
        "nota\n");
    escolha = validaEntrada();
    while (escolha < 0 || escolha > 4) {
      printf("\nopcao inválida, selecione uma opcao de 0 a 4\n");
      escolha = validaEntrada();
    }
    array(&(*biblioteca), A, sinal, cont);
    switch (escolha) {
    case 0:
      break;
    case 1:
      for (int i = 0; i < cont; i++)
        for (int j = i + 1; j < cont; j++)
          if (strcmp(A[i]->nome, A[j]->nome) > 0) {
            troca(A, i, j);
          }
      break;
    case 2:
      for (int i = 0; i < cont; i++)
        for (int j = i + 1; j < cont; j++)
          if (strcmp(A[i]->nome, A[j]->nome) < 0) {
            troca(A, i, j);
          }
      break;
    case 3:
      for (int i = 0; i < cont; i++)
        for (int j = i + 1; j < cont; j++)
          if (A[i]->nota > A[j]->nota) {
            troca(A, i, j);
          }
      break;
    case 4:
      for (int i = 0; i < cont; i++)
        for (int j = i + 1; j < cont; j++)
          if (A[i]->nota < A[j]->nota) {
            troca(A, i, j);
          }
      break;
    }
    sinal = 1;
    array(biblioteca, A, sinal, cont);
    printf("\nSua biblioteca foi ordenada!\n");
  }
}

void array(lista *biblioteca, jogoPtr A[], int sinal, int cont) {
  if (sinal == 0) {
    int i = 0;
    jogoPtr aux = (*biblioteca).topo;
    while (aux != NULL) {
      A[i] = aux;
      i++;
      aux = aux->prox;
    }
  } else {
    for (int i = 0; i <= cont - 1; i++) {
      if ((cont - 1) == 0) {
        A[i]->ant = NULL;
        A[i]->prox = NULL;
      } else if (i == 0) {
        A[i]->ant = NULL;
        A[i]->prox = A[i + 1];
      } else if (i == cont - 1) {
        A[i]->prox = NULL;
        A[i]->ant = A[i - 1];
      } else {
        A[i]->ant = A[i - 1];
        A[i]->prox = A[i + 1];
      }
    }
    (*biblioteca).topo = A[0];
    (*biblioteca).final = A[cont - 1];
  }
}

void mostraBib(lista biblioteca) {
  jogoPtr aux = biblioteca.topo;
  int contador = 1, x = vazia(biblioteca);
  if (x == 1) {
    printf("\nVocê ainda não tem jogos adicionados a sua biblioteca!\n");
  } else {
    while (aux != NULL) {
      printf("\n%d.%s\nNota:%d\n", contador, aux->nome, aux->nota);
      contador++;
      aux = aux->prox;
    }
  }
}

void removeJogo(lista *biblioteca, int *cont, int total) {
  char imprime[TAM];
  int compara = 1, remove, estadoLista = vazia(*biblioteca);
  jogoPtr aux = (*biblioteca).topo, p;
  if (estadoLista == 1) {
    printf("\nVocê ainda não tem jogos adicionados a sua biblioteca!\n");
  } else {
    printf("\nQual jogo você quer remover da biblioteca?\nDigite o índice do "
           "jogo:\n");
    remove = validaEntrada();
    while (compara != remove && compara < total) {
      compara++;
      aux = aux->prox;
    }
    if (compara == total && compara != remove) {
      printf("\nO jogo não se encontra na biblioteca!\n");
    } else {
      if (aux == (*biblioteca).topo && aux == (*biblioteca).final) {
        (*biblioteca).topo = NULL;
        (*biblioteca).final = NULL;
        strcpy(imprime, aux->nome);
        free(aux);
      } else if (aux == (*biblioteca).topo) {
        (*biblioteca).topo = aux->prox;
        strcpy(imprime, aux->nome);
        free(aux);
        ((*biblioteca).topo)->ant = NULL;
      } else if (aux == (*biblioteca).final) {
        (*biblioteca).final = aux->ant;
        strcpy(imprime, aux->nome);
        free(aux);
        ((*biblioteca).final)->prox = NULL;
      } else {
        (aux->prox)->ant = aux->ant;
        (aux->ant)->prox = aux->prox;
        strcpy(imprime, aux->nome);
        free(aux);
      }
      printf("\n%s removido da biblioteca.\n", imprime);
      (*cont)--;
    }
  }
}

void addJogo(lista *biblioteca, int nota, char nome[]) {
  jogoPtr p = (jogoPtr)malloc(sizeof(jogo));
  int verifica;
  p->prox = NULL;
  p->ant = NULL;
  p->nota = nota;
  strcpy(p->nome, nome);
  if ((*biblioteca).topo == NULL) {
    (*biblioteca).topo = p;
    (*biblioteca).final = p;
  } else {
    p->ant = (*biblioteca).final;
    (p->ant)->prox = p;
    (*biblioteca).final = p;
  }
}

int verificar(lista biblioteca, char jogo[]) {
  jogoPtr aux = biblioteca.topo;
  while (aux != NULL) {
    if (strcmp(aux->nome, jogo) == 0)
      return 1;
    aux = aux->prox;
  }
  return 0;
}

int vazia(lista x) {
  if (x.topo == NULL) {
    return 1;
  } else
    return 0;
}

void troca(jogoPtr A[], int a, int b) {
  jogoPtr aux;
  aux = A[a];
  A[a] = A[b];
  A[b] = aux;
}

int menu() {
  int opcao;
  printf("\nSuas opções:\n");
  printf("(0)Sair da biblioteca\n(1)Adicionar jogo\n(2)Mostrar "
         "biblioteca\n(3)Remover jogo\n(4)Ordenar biblioteca\n(5)Procurar "
         "jogo\n(6)Editar jogo\n");
  opcao = validaEntrada();
  while (opcao < 0 || opcao > 6) {
    printf("\nopcao inválida, selecione uma opcao de 0 a 6\n");
    opcao = validaEntrada();
  }
  return opcao;
}

int validaEntrada() {
  int entrada, valida;
  do {
    valida = 0;
    scanf("%d", &entrada);
    while (getchar() != '\n')
      valida = 1;
    if (valida == 1)
      printf("\nEntrada inválida\n");
  } while (valida == 1);
  return entrada;
}

void getArquivo(FILE *arquivo, lista *biblioteca, int *cont) {
  int nota;
  char nome[TAM];
  while ((fgets(arquivo, "%s", nome) == 1) && (fscanf(arquivo, "%d", &nota)==1)) {
    (*cont)++;
    addJogo(biblioteca, nota, nome);
  }
}