#include <stdio.h>
#include <string.h>


int main() {
  char string0[100];
  char cleaner[2] = {' '};
  
  
  scanf("%s", string0);
  
  puts(string0);
  
  strcpy(string0, cleaner);
  
  puts(string0);
  
  
  return 0;
}