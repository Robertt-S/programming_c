#include <stdio.h>
#include <string.h>
#define TAM 100

struct Notas {
  int p1;
  int p2;
  int p3;
};

void Ler(struct Notas *valores) {

  scanf("%d", &valores->p1);
  scanf("%d", &valores->p2);
  scanf("%d", &valores->p3);

  return;
}

void Imprimir(struct Notas *valores) {

  printf("nota p1: %d\n", valores->p1);
  printf("nota p2: %d\n", valores->p2);
  printf("nota p3: %d", valores->p3);

  return;
}

int main() {

  struct Notas valores = {0};

  Ler(&valores);
  Imprimir(&valores);

  return 0;
}