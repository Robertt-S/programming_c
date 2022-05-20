#include <stdio.h>

int main() {
  int i, j, m;
  
  printf("Enter your integer numbers: \n");
  scanf("%d\n%d\n%d", &i, &j, &m);
  
  if (i >= j) {
    if (i >= m) {
      printf("Bigger one: %d\n", i);
    } else {
      printf("Bigger one: %d\n", m);
    }
  } else if (j >= m) {
    printf("Bigger one: %d\n", j);
  } else {
    printf("Bigger one: %d\n", m);
  }
  
  return 0;
}