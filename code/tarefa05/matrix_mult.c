#include <stdio.h>

int Receiver() {
  int num;
  
  scanf("%d", &num);
  /*
  scanf("%d%d", &orderA0, &orderA1);
  scanf("%d%d", &orderB0, &orderB1);
  */
  return num;
}

void MatrixA(int orderA0, int orderA1) {
  int matrixA[100][100];
  
  
  return;
}

void MatrixB() {
  int matrixB[100][100];
  
  
  return;
}

void MatrixResult() {
  int matrixResult[100][100];
  
  return;
}

int main() {
  int orderA0, orderA1, orderB0, orderB1, i, j, k;
  
  
  
  
  
//=== Passando os elementos da matriz A e B
  if (orderA1 != orderB0) {
    printf("Não é possível realizar a operação, pois as matrizes não seguem a regra MxN, NxO = MxO.\n");
  } else {
    for (i = 0; i < orderA0; i++) {
      for (j = 0; j < orderA1; j++) {
        scanf("%d", &matrixA[i][j]);
      }
    }
    
    for (i = 0; i < orderB0; i++) {
      for (j = 0; j < orderB1; j++) {
        scanf("%d", &matrixB[i][j]);
      }
    }
    
    for (i = 0; i < orderA0; i++) {
      for (j = 0; j < orderB1; j++) {
        matrixResult[i][j] = 0;
        for (k = 0; k < orderB0; k++) {
          matrixResult[i][j] += matrixA[i][k]*matrixB[k][j];
        }
      }
    }
    
//=== Mostrando as matrizes A e B
    
    printf("\nMatriz 1 (%dx%d)\n", orderA0, orderA1);
    for (i = 0; i < orderA0; i++) {
      for (j = 0; j < orderA1; j++) {
        if (j == orderA1 - 1) {
          printf("%d\n", matrixA[i][j]);
        } else {
          printf("%d ", matrixA[i][j]);
        }
      }
    }
    
    
    printf("\nMatriz 2 (%dx%d)\n", orderB0, orderB1);
    for (i = 0; i < orderB0; i++) {
      for (j = 0; j < orderB1; j++) {
        if (j == orderB1 - 1) {
          printf("%d\n", matrixB[i][j]);
        } else {
          printf("%d ", matrixB[i][j]);
        }
      }
    }
    
//=== Matriz resultante.
    
    printf("\nMatriz 1 * Matriz 2 (%dx%d)\n", orderA0, orderB1);
    for (i = 0; i < orderA0; i++) {
      for (j = 0; j < orderB1; j++) {
        printf("%d ", matrixResult[i][j]);
      }
      printf("\n");
    }
  }
  
  return 0;
}

int main() {
  int orderA0, orderA1, orderB0, orderB1;
  int matrixA[100][100], matrixB[100][100], matrixResult[100][100];
  
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      matrixA[i][j] = 0;
      matrixB[i][j] = 0;
      matrixResult[i][j] = 0;
    }
  }
  
  orderA0 = Receiver();
  orderA1 = Receiver();
  orderB0 = Receiver();
  orderB1 = Receiver();
  
  return 0;
}