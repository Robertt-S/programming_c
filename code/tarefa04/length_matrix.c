#include <stdio.h>

int main() {
  int array[100000];
  int i, j, num, sum, pointNum, arrayLimit, pointLimit;
  
//=== Inicializando o vetor. ===//
  for (i = 0; i < 100000; i++) {
    array[i] = 0;
  }
  
//=== Criando o vetor. ===//
  scanf("%d", &arrayLimit);
  
  arrayLimit *= arrayLimit;
  
  for (i = 0; i < arrayLimit; i++) {
    scanf("%d", &num);
    array[i] = num;
  }

//=== Somando os pontos desejados ===//
  scanf("%d", &pointLimit);
  
  sum = 0;
  for (i = 0; i < pointLimit; i++) {
    scanf("%d", &pointNum);
    sum += array[pointNum];
  }
  
  printf("%d", sum);
  
  return 0;
}