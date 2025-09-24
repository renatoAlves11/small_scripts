#include <stdio.h>
#define NUM 5
#define DPT 11
struct func {
  int idade;
  int departamento;
};

typedef struct func func;

void inicializa(func v[]) {
  for (int i = 0; i < NUM; i++) {
    v[i].idade = 0;
    v[i].departamento = 10;
  }
}

void exibe(func v[]) {
  int idades[DPT] = {0};
  int quantidade[DPT] = {0};
  printf("ok");
  for (int i = 0; i < NUM; i++) {
    idades[v[i].departamento] += v[i].idade;
    quantidade[v[i].departamento]++;
  }
  printf("ok");
  for (int i = 0; i < NUM; i++) {
    printf("Departamento:%d\nMedia:%d\n", i + 10, idades[i] / quantidade[i]);
  }
}

int main(void) {
  func v[NUM];
  inicializa(v);
  for (int i = 0; i < NUM; i++) {
    printf("Digite idade e departamento\n");
    scanf(" %d", &v[i].departamento);
    scanf(" %d", &v[i].idade);
  }
  exibe(v);
}