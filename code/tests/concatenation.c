#include <stdio.h>

int main() {
  char text[1000];
  int i;
  
  for (i = 0; i <= 10; i++) {
    scanf("%c", &text[i]);
    
  }
  
  printf("%s", text);
}