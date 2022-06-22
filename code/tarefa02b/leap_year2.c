#include <stdio.h>

int main() {
  int num, year, i;
  
  scanf("%d", &num);
  
  for (i = 1; i <= num; i++) {
    year += 4;
    if (i == num) {
      if (year % 400 == 0) {
        printf("%.4d - ano: %4d", i, year);
      } else if (year % 400 == 0 && year % 100 != 0) {
        printf("%.4d - ano: %4d", i, year);
      } else if (year % 4 == 0 && year % 100 != 0) {
        printf("%.4d - ano: %4d", i, year);
      }
    } else if (year % 400 == 0) {
      printf("%.4d - ano: %4d\n", i, year);
    } else if (year % 400 == 0 && year % 100 != 0) {
      printf("%.4d - ano: %4d\n", i, year);
    } else if (year % 4 == 0 && year % 100 != 0) {
      printf("%.4d - ano: %4d\n", i, year);
    }
  }
  return 0;
}