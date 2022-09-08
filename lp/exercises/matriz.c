#include <stdio.h>

int main() {
  int i, j, k, row1, column1, row2, column2, num;
  int matrix1[100][100], matrix2[100][100], matrixResult[100][100];
  
  scanf("%d%d%d%d", &row1, &column1, &row2, &column2);
  
  if (row1 != column2) {
    printf("Não é possível realizar a multiplicação.\n");
    return 0;
  }
  
  for (i = 0; i < row1; i++) {
    for (j = 0; j < column1; j++) {
      scanf("%d", &num);
      matrix1[j][i] = num;
    }
  }
  
  for (i = 0; i < row2; i++) {
    for (j = 0; j < column2; j++) {
      scanf("%d", &num);
      matrix2[j][i] = num;
    }
  }
  
  for (i = 0; i < row1; i++) {
    for (j = 0; j < column2; j++) {
      for (k = 0; k < row2; k++) {
        matrixResult[j][i] += matrix1[k][i]*matrix2[j][k];
      }
    }
  }
  
  
  
  
  printf("Matriz 1 (%dx%d)\n", row1, column1);
  for (i = 0; i < row1; i++) {
    for (j = 0; j < column1; j++) {
      if (j == column1 - 1) {
        printf("%d\n", matrix1[j][i]);
      } else {
        printf("%d\t", matrix1[j][i]);
      }
    }
  }
  
  //printf("\n");
  
  printf("Matriz 2 (%dx%d)\n", row2, column2);
  for (i = 0; i < row2; i++) {
    for (j = 0; j < column2; j++) {
      if (j == column2 - 1) {
        printf("%d\n", matrix2[j][i]);
      } else {
        printf("%d\t", matrix2[j][i]);
      }
    }
  }
  
  //printf("\n");
  
  printf("Matriz 1 * Matriz 2 (%dx%d)\n", row1, column2);
  for (i = 0; i < row1; i++) {
    for (j = 0; j < column2; j++) {
      if (j == column2 - 1) {
        printf("%d\n", matrixResult[j][i]);
      } else {
        printf("%d\t", matrixResult[j][i]);
      }
    }
  }
  
  return 0;
}