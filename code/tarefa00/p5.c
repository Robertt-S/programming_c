#include <stdio.h>

int main() {
  char receive = "10.20";
  char spliting = strtok(receive, ".");
  printf("%s\n", spliting);
  
  return 0;
}
