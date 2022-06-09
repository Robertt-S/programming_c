#include <stdio.h>

int main() {
  int num, i, result = 0;
  
  scanf("%d", &num);
    
  i = 2;
  while (i <= num / 2) {    // We can use i < num, but using divided by 2, we do less math   
    if (num % i == 0) {
      result++;
      break;
    }
    i++;
  }
  
  if (num == 0 || num == 1) {
    printf("O número %d não é primo!\n", num);
  } else if (result == 0) {
    printf("O número %d é primo!\n", num);
  } else {
    printf("O número %d não é primo!\n", num);
    }
    
   return 0;
}