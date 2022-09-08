#include <stdio.h>

void Printer(int count) {
  
  if (count < 10) {
    printf("count: %d\n", count);
    Printer(count + 1);
    printf("count after all recursions: %d\n", count);
  } 
  
  
  return;
}


int main() {
  int count = 0;
  
  Printer(count);
  
  
  return 0;
}