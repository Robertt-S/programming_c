#include <stdio.h>

int main() {
  int i = 0, j = 10;
  while (i <= j) {
    while (i <= j) {
      if (i <= j) {
        printf("break\n");
        break;
      }
    }
    if (i <= j) {
      printf("...");
    }
    i++;
  }
}