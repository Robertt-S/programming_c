#include <stdio.h>

#define MAX 6 // Mude essa constante para alterar
              // a quantidade de números passados.

void preencherVetor(int vetor[]) {
  int i;
  
  printf("Dê-me %d números:\n\n", MAX);
  
  for (i = 0; i < MAX; i++) {
    printf("Número %d será:\n", i + 1);
    scanf("%d", &vetor[i]);
  }
  
  return;
}


void minMax(int vetor[], int *min, int *max) {
  int i;
  
  preencherVetor(vetor);
  
  *min = vetor[0];
  for (i = 0; i < MAX; i++) {
    if (*min <= vetor[i]) {
      ;
    } else {
      *min = vetor[i];
    }
  }
  
  *max = vetor[0];
  for (i = 0; i < MAX; i++) {
    if (*max >= vetor[i]) {
      ;
    } else {
      *max = vetor[i];
    }
  }
  
  return;
}




int main() {
  int min, max, vetor[MAX];
  
  minMax(vetor, &min, &max);
  
  printf("O mínimo: %d\nO máximo: %d\n", min, max);
  
  return 0;
}