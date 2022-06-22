#include <stdio.h>

int main() {
  int num, count = 1, year = 0;
  
  scanf("%d", &num);
  
  while (count <= num) {
    year += 4;
    if (count == num) {
      if (year % 100 == 0 && year % 400 == 0) {
        ;
      } else if (year % 4 == 0 && year % 100 == 0) {
        ;
      } else {
        printf("%.4d - ano: %4d", count, year);
        count++;
      }
    } else if (year % 100 == 0 && year % 400 == 0) {
      ;
    } else if (year % 4 == 0 && year % 100 == 0) {
      ;
    } else {
      printf("%.4d - ano: %4d\n", count, year);
      count++;
    }
  }
}