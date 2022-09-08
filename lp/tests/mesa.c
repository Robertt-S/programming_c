#include <stdio.h>

int main() {
  int i, j, resultado = 0;
  
  for(i=0; i<=10; i++) {
    for(j=0; j<=5; j++) {
      if ((i+j)%5 == 0){
        printf("i= %d, j= %d, resultado= %d\n", i, j, resultado);
        resultado +=i; 
      }
    }
  }
  
  printf("i= %d, j= %d, resultado= %d\n", i, j, resultado);
}