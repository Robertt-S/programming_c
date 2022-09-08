#include <stdio.h>                                                                                                                                                     

int main() {
  int matrix[1000][1000];
  int i, j, num, sum, matrixNum, pointNum, matrixLimit, pointLimit;
  
//=== Inicializando o vetor. ===//
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      matrix[i][j] = 0;
    }
  }
  
//=== Criando o vetor. ===//
  scanf("%d\n", &matrixLimit);
  
  for (i = 0; i < matrixLimit; i++) {
    for (j = 0; j < matrixLimit; j++) {
      scanf("%d\n", &num);
      matrix[i][j] = num;
    }
  }

//=== Somando os pontos desejados ===//
  scanf("%d\n", &pointLimit);
  
  j = 0;
  sum = 0;
  for (i = 0; i < pointLimit; i++) {
    scanf("%d\n", &pointNum);
    
    while (pointNum >= matrixLimit) {
      pointNum -= matrixLimit;
      j++;
    }
    
    sum += matrix[j][pointNum];
    
    j = 0;
  }
  
  printf("%d\n", sum);
  
  return 0;
}
/*
  00 01 02    6 >= 3 j = 0 
  10 11 12    3 >= 3 j = 1
  20 21 22    0 j = 2
*/