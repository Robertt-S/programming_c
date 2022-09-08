#include <stdio.h>

int Prime(int num, int base, int *count) {
  
  if (base < num) {
    if (num % base == 0) {
      (*count)++;
      //printf("count: %d\n", (*count));
      //return 0;
    } else {
      //printf("count: %d\n base: %d\n", (*count), base);
      Prime(num, base + 1, count);
    }
  }
  
  return 0;
}

void Printer() {
  int num, base = 2, count;
  
  scanf("%d", &num);
  
  Prime(num, base, &count);
  
  //printf("%d\n", count);
  
  if (num == 0 || num == 1) {
    printf("%d não é primo.\n", num);
  } else if (count != 0) {
    printf("%d não é primo.\n", num);
  } else {
    printf("%d é primo \n", num);
  }
  
  return;
}


int main() {
  
  Printer();
  
  return 0;
}