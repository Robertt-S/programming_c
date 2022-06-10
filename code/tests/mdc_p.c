#include <stdio.h>

int main() {
  int num1, num2, primo, mdc = 1;
  
  printf("Dois números: \n");
  scanf("%d%d", &num1, &num2);
  
  while (num1 > 1 && num2 > 1) {
    printf("Número primo: \n");
    scanf("%d", &primo);
    
    if (num1 % primo == 0 && num2 % primo == 0) {
      num1 = num1 / primo;
      num2 = num2 / primo;
      printf("%d  %d\n", num1, num2);
      
      mdc *= primo;
    } else if (num1 % primo == 0) {
      num1 = num1 / primo;
      printf("%d  %d\n", num1, num2);
    } else if (num2 % primo == 0) {
      num2 = num2 / primo;
      printf("%d  %d\n", num1, num2);
    }
  }
  printf("mdc: %d\n", mdc);
}