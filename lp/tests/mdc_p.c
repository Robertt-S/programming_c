#include <stdio.h>

int main() {
  int num1, num2, prime, mdc = 1;
  int i, num, numi = 2, result = 0;
  
  printf("Two numbers: \n");
  scanf("%d%d", &num1, &num2);
  
  if (num1 < num2) {
    num = num1;
  } else {
    num = num2;
  }
  
  while (num1 > 1 && num2 > 1) {
    while (numi <= num) {
      i = 2;
      while (i <= numi / 2) {
        if (numi % i == 0) {
          result++;
          break;
        }
        i++;
      }
      
      prime = numi;
      while (num1 % prime == 0 || num2 % prime == 0) {
        if (num1 % prime == 0 && num2 % prime == 0) {
          num1 = num1 / prime;
          num2 = num2 / prime;
          printf("%.4d  %.4d\n", num1, num2);
          mdc *= prime;
        } else if (num1 % prime == 0) {
          num1 = num1 / prime;
          printf("%.4d  %.4d\n", num1, num2);
        } else if (num2 % prime == 0) {
          num2 = num2 / prime;
          printf("%.4d  %.4d\n", num1, num2);
        }
      }
      
      result = 0;
      numi++;
    }
  }
  printf("mdc: %d\n", mdc);
    /*Achar prime;
    Perguntar se o if abaixo funciona para ele, se sim, faça;
    Perguntar se o if abaixo funciona novamente com o mesmo prime, se sim, faça;
    Se não escale o prime;*/
}

/*150 20 2 *
75  10 2
75  5  5 *
15 1
*/