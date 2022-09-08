#include <stdio.h>

int main() {
  int array[10000];
  int i, j, num, sum, arrayNum, pointNum, arrayLimit, pointLimit;
  
//=== Inicializando o vetor. ===//
  for (i = 0; i < 10000; i++) {
    array[i] = 0;
  }
  
//=== Criando o vetor. ===//
  scanf("%d", &arrayLimit);
  
  arrayLimit *= arrayLimit;
  
  for (i = 0; i < arrayLimit; i++) {
    scanf("%d", &num);
    array[i] = num;
  }
  
//=== Somando os pontos desejados. ===//
  scanf("%d", &pointLimit);
  
  sum = 0;
  for (i = 0; i < pointLimit; i++) {
    scanf("%d", &pointNum);
    sum += array[pointNum];
  }
  
  printf("%d\n", sum);
  
  return 0;
}