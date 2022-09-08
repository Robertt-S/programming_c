#include <stdio.h>

int main() {
  int num, rest;
  
  printf("Give me a number: \n");
  scanf("%d", &num);
  
  while (num > 1) {
    rest = num % 2;
    printf("%d\n", rest);
    num /= 2;
  }
  printf("1\n");
  return 0;
}

//--- reverse

/*int main() {
  int num, rest;
  
  printf("Give me a number: \n");
  scanf("%d", &num);
  
  while (num > 1) {
    rest = num % 2;
    printf("%d\n", rest);
    num /= 2;
  }
  printf("1\n");
  return 0;
}*/