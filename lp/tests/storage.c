#include <stdio.h>

int main() {
  int i = 0, j = 10, k = 0;
  
  while (i <= j) {
    k += j;
    i++;
    printf("%d\n", k); 
  }
  printf("Test: %d\n", k); 
  
  //printf("\n%d\n", 1%2);
}