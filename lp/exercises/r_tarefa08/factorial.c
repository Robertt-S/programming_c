#include <stdio.h>

int Factorial(int num) {
  
  if (num == 0) {
    printf("Fatorial de %d é: %d.\n", num, 1);
    return 1;
  } else if (num < 0) {
    printf("Fatorial de %d não existe.\n", num);
  } else {
    return (num * Factorial(num - 1));
  }
  
  return num;
}

void Printer(int num, int facNum) {
  
  printf("O fatorial de %d é: %d.\n", num, facNum);
  
  return;
}


int main() {
  int num, facNum;
  
  scanf("%d", &num);
  
  facNum = Factorial(num);
  
  Printer(num, facNum);
  
  return 0;
}