#include <stdio.h>

int main() {
  int n;
  
  printf("Enter a number: \n");
  scanf("%d", &n);
  printf("Floating point test = %f\n", n / (float) 3);
  
  return 0;
}