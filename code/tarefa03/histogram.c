#include <stdio.h>

int main() {
  int num, num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5;
  int num6 = 6, num7 = 7, num8 = 8, num9 = 9;
  int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
  int count6 = 0, count7 = 0, count8 = 0, count9 = 0;
  
/*
  Pedimos um número e em cada caso somamos 1 para o contador do
  respectivo caso.
*/
  while (num != 0) {
    scanf("%d", &num);
    
    switch (num) {
      case 1:
        count1++;
        break;
      case 2:
        count2++;
        break;
      case 3:
        count3++;
        break;
      case 4:
        count4++;
        break;
      case 5:
        count5++;
        break;
      case 6:
        count6++;
        break;
      case 7:
        count7++;
        break;
      case 8:
        count8++;
        break;
      case 9:
        count9++;
        break;
    }
  }
  
  printf("O histograma é: %d %d %d %d %d %d %d %d %d\n", count1, count2, count3, count4, count5, count6, count7, count8, count9);  
}
