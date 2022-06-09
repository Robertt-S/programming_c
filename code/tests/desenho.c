#include <stdio.h>

int main() {

  int i, j, base;

  printf("Base: ");
  scanf("%d", &base);

  j = 0;
  while (j < base) {
    i = 0;
    while (i < base - j) {
      printf ("*");
      i++;
    }
    printf ("\n");    
    j++;
  }

}
