/*
#include <stdio.h>

// Retorna a soma de m + m + 1 + ... + n - 1 + n 

int soma(int m, int n) {
  if (m == n)
    return n;
  else
    return m + soma(m+1, n);
}

int main() {
  int m, n, s;
  
  printf("Digite m: ");
  scanf("%d", &m);
  printf("Digite n: ");
  scanf("%d", &n);  
  s = soma(m, n);
  printf("Soma de %d a %d = %d\n", m, n, s);
  return 0;
}
*/



#include <stdio.h>


int Scalable(int n, int m) {

  if (n == m) {
    printf("%d e %d\n", n, m);
    return 1;
  } 

  printf("%d e %d\n", n, m);
  return n + Scalable((n + 1), m);
  
}


int main() {
  
  Scalable(1, 6);
  
  return 0;
}
