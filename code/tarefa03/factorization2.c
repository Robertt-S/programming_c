#include <stdio.h>

int main() {
  int num, omegaNum, prime, count = 0;
  int i, numi = 2;
  
  scanf("%d", &num);
  
  omegaNum = num;
  
  while (num > 1) {
    while (numi <= num) {
      prime = numi;
      while (num % prime == 0) {
        num = num / prime;
        count++;
      }
      numi++;
    }
  }
  printf("Omega(%d)=%d\n", omegaNum, count);
  return 0;
}