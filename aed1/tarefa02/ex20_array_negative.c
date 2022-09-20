#include <stdio.h>

int negativos(float *vetor, int N) {
  int i;
  
  printf("\n");
  
  for (i = 0; i < N; i++) {
    printf("Dê-me o número da posição: %d\n", i);
    scanf("%f", vetor+i);
  }
  
  printf("\n");
  
  for (i = 0; i < N; i++) {
    if (*(vetor+i) * (-1) > 0) {
      printf("Número na posição[%d]: %.2f\n", i, *(vetor+i));
    }
  }
  
  return 0;
}




int main() {
  float vetor[1000];
  int tamanhoArray;
  
  printf("Quantas partes do vetor deseja usar?:\n");
  scanf("%d", &tamanhoArray);
  
  negativos(vetor, tamanhoArray);
  
  return 0;
}