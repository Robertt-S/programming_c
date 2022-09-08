#include <stdio.h>
 
int main(){
  float num;
  scanf("%f", &num);
  printf("A parte inteira: %.0f\n", num);
  printf("A parte decimal: %.0f\n", (num - (int)num)*100);
}