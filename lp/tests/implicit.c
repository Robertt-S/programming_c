#include <stdio.h>

int main() {
  int a; short b;
  
  scanf("%d%hd\n", &a, &b);
  
  a = b;
  
  printf("a = %d\n", a);
  
  return 0;
}