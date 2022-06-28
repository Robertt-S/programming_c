#include <stdio.h>                                                                                                                                                     

int main() {
  int matrix[1000][1000], pointStorage[10000];
  int i, j, num, sum, matrixNum, matrixLimit, pointLimit;
  
//=== Inicializando a matriz. ===//
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      matrix[i][j] = 0;
    }
  }
  
//=== Criando a matriz. ===//
  scanf("%d", &matrixLimit);
  
  for (i = 0; i < matrixLimit; i++) {
    for (j = 0; j < matrixLimit; j++) {
      scanf("%d", &num);
      matrix[i][j] = num;
    }
  }
  
//=== Pedindo e somando os pontos desejados ===//
  scanf("%d", &pointLimit);
  
  sum = 0;
  for (i = 0; i < pointLimit; i++) {
    scanf("%d", &pointStorage[i]);
  }
  
  sum = 0;
  for (i = 0; i < pointLimit - 1; i++) {
    sum += matrix[pointStorage[i]][pointStorage[i+1]];
  }
  
  printf("%d\n", sum);
  
  return 0;
}