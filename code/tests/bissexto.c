#include <stdio.h>

int main() {
  int ano;
  
  scanf("%d", &ano);
  
  if (ano % 4 == 0) {
    printf("%d é\n", ano);
  } else {
    printf("%d não é\n", ano);
  }
}