#include <stdio.h>

int main() {
  
  int num, i, numi = 2, result = 0;

  scanf("%d", &num);
  
  while (numi <= num) {   
    i = 2;
    while (i <= numi / 2) {
      if (numi % i == 0) {
        result++;
        break;
      }
      i++;
    }
     if (result == 0) {
      printf("%d\n", numi);
     }
    result = 0;
    numi++;
  }
  
  return 0;
}