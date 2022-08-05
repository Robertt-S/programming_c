#include <stdio.h>
#define TAM 100
/*le os num até digitar 0 e printa o maior digitado*/
int Leia(int vetor[]) {
  int qtd,
  n = 1;
  for(qtd = 0; n != 0; qtd++) {
    scanf("%d", &vetor[qtd]);
    n = vetor[qtd];
  }
  return qtd;
}

int Maior(int vetor[], int qtd, int n, int a) {

  if(n == qtd) {
    return a;
  }
  else {
    if(vetor[n] >= a) {
      a = vetor[n];
    }
    //n++;
    return Maior(vetor, qtd, n + 1, a);
  }
}

void Imprime(int maior) {
  printf("%d\n", maior);
  return;
}

int main() {
  int vetor[TAM], qtd, a = 1, maior, n = 0;
  qtd = Leia(vetor);
  maior = Maior(vetor, qtd, n, a);
  Imprime(maior);
  return 0;
}