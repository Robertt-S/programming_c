#include <stdio.h>                                                                                                                                                     

int main() {
  int matrix[1000][1000];
  int i, j, num, sum, matrixNum, pointNum, matrixLimit, pointLimit;
  
//=== Inicializando a matriz ===//
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      matrix[i][j] = 0;
    }
  }
  
//=== Criando o vetor. ===//
  scanf("%d", &matrixLimit);
  printf("\n");
  
  for (i = 0; i < matrixLimit; i++) {
    for (j = 0; j < matrixLimit; j++) {
      if (j == matrixLimit - 1) {
        scanf("%d", &num);
        matrix[i][j] = num;
        printf("\n");
      } else {
        scanf("%d", &num);
        matrix[i][j] = num;
      }
    }
  }
  
//=== Somando os pontos desejados ===//
  scanf("%d", &pointLimit);
  printf("\n");
  
  j = 0;
  sum = 0;
  for (i = 0; i < pointLimit; i++) {
    scanf("%d", &pointNum);
    
    while (pointNum >= matrixLimit) {
      pointNum -= matrixLimit;
      j++;
    }
    
    sum += matrix[j][pointNum];
    j = 0;
  }
  
  printf("\n");
  
  printf("%d\n", sum);
}