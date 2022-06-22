#include <stdio.h>

int main() {
  int num, count = 1, year = 0;
  
  scanf("%d", &num);
  
  while (count <= num) {
    year += 1;
    if (count == num) {
      if (year % 400 == 0) {
        printf("%.4d - ano:%4d", count, year);
        count++;
      } else if (year % 4 == 0 && year % 100 != 0) {
        printf("%.4d - ano:%4d", count, year);
        count++;
      }
    } else if (year % 400 == 0) {
      printf("%.4d - ano:%4d\n", count, year);
      count++;
    } else if (year % 4 == 0 && year % 100 != 0) {
      printf("%.4d - ano:%4d\n", count, year);
      count++;
    }
  }
}