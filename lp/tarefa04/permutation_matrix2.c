#include <stdio.h>
int main() {
  int tamanho, l, c, num[1000][1000] = {0}, somaC = 0, somaL = 0;

  scanf("%d", &tamanho);

  for (l = 0; l < tamanho; l++) {
    for (c = 0; c < tamanho; c++) {
      scanf("%d", &num[l][c]);
    }
  }
  for (l = 0; l < tamanho; l++) {
    for (c = 0; c < tamanho; c++) {
      somaC += num[l][c];
    }
  }
  for (c = 0; c < tamanho; c++) {
    for (l = 0; l < tamanho; l++) {
      somaL += num[l][c];
    }
  }

  if (somaC == tamanho && somaL == tamanho) {
    printf("verdadeiro\n");
  } else {
    printf("falso\n");
  }
  return 0;
}