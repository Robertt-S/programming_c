#include <stdio.h>

int Bigger(int numbers[1000], int index, int bigger) {
  
  scanf("%d", &numbers[index]);
  
  if (numbers[index] >= bigger) {
    bigger = numbers[index];
  }
  
  if (numbers[index] == 0) {
    printf("%d\n", bigger);
    return bigger;
  } else if (index < 1000) {
    Bigger(numbers, (index + 1), bigger);
    printf("Recursiva: %d\n", bigger);
    return bigger;
  }
  
  return 0;
}

int main() {
  int numbers[1000], index = 0, bigger = 0, mark;
  
  //Bigger(numbers, index, bigger);
  
  printf("Teste: %d\n", Bigger(numbers, index, bigger));
  
  return 0;
  
}