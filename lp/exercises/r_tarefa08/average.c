#include <stdio.h>

void Average(int numbers[1000], int index, int sum, int count) {
  
  scanf("%d", &numbers[index]);
  
  sum += numbers[index];
  
  if (numbers[index] != 0) {
    count++;
    Average(numbers, (index + 1), sum, count);
  } else {
    printf("A média de %d valore(s) é: %d.\n", count, sum / count);
  }
  
  return;
}


int main() {
  int numbers[1000], index = 0, sum = 0, count = 0, mark;
  
  Average(numbers, index, sum, count);
  
  return 0;
}