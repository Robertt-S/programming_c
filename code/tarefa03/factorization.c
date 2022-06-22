#include <stdio.h>

int main() {
  int num, omegaNum, prime, count = 0;
  int i, numi = 2, result = 0;
  
  scanf("%d", &num);
  
  omegaNum = num;
  
  while (num > 1) {
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
      while (num % prime == 0) {
        if (num % prime == 0) {
          num = num / prime;
          count++;
        }
      }
      result = 0;
      numi++;
    }
  }
  
  printf("Omega(%d)=%d\n", omegaNum, count);
  
  return 0;
}