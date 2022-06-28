#include <stdio.h>                                                                                                                                                     

int main() {
  int matrix[1000][1000];
  int i, j, num, sum, matrixNum, pointNum, matrixLimit, pointLimit;
  int line;
  
//=== Inicializando o vetor. ===//
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      matrix[i][j] = 0;
    }
  }
  
//=== Criando o vetor. ===//
  scanf("%d", &matrixLimit);
  
  for (i = 0; i < matrixLimit; i++) {
    for (j = 0; j < matrixLimit; j++) {
      scanf("%d", &num);
      matrix[i][j] = num;
    }
  }

//=== Somando os pontos desejados ===//
  scanf("%d", &pointLimit);
  
  sum = 0;
  for (i = 0; i < pointLimit; i++) {
    if (i == 0) {
      scanf("%d", &line);
      sum += matrix[line][0];  // No exemplo o 0 parece escolher a linha, logo, haveria um número inicial que escolheria qual linha seria a usada (line).
      continue;
    }
    scanf("%d", &pointNum);
    sum += matrix[line][pointNum];
  }
  
  printf("%d\n", sum);
  
  return 0;
}