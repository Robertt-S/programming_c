#include <stdio.h>

#define N_ELEM 5 

int vet[N_ELEM]; //variavel global

void le_vet() {
  int i;

  for (i = 0; i < N_ELEM; i++) {
    printf("vet[%d]: ", i);
    scanf("%d", &vet[i]);
  }
}

void escreve_vet() {
  int i;

  printf("\n");
  for (i = 0; i < N_ELEM; i++) 
    printf("vet[%d]: %d\n", i, vet[i]);
}

int main() {
  le_vet();
  escreve_vet();
  return 0;
}