#include <stdio.h>
#include <string.h>

int main() {
  char number[1000];
  
  fgets(number, 10, stdin);
  fputs(number, stdout);
  
  return 0;
}