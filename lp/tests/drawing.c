#include <stdio.h>

int main() {
  int i, j, k;
  
  scanf("%d", &j);
  
  i = 0;
  while (j > i) {
    k = i;
    while (j > k) {
      printf("*");
      k++;
    }
    printf("\n");
    i++;
  }
  
  return 0;
}