#include <stdio.h>

/* Testing while loop */
int main() {
  #define eMol 96500
  
  float mass, molarMass, current, t, vary, ceiling;
  int X;
  
  printf("Enter the molar mass[g]: \n");
  scanf("%f", &molarMass);
  
  printf("Enter the electric current[A]: \n");
  scanf("%f", &current);
  
  printf("Enter the time[s]: \n");
  scanf("%f", &t);
  
  printf("Enter the mole electrons number[integer]: \n");
  scanf("%d", &X);
  
  printf("Enter the vary number: \n");
  scanf("%f", &vary);
  
  printf("Enter the ceiling: \n");
  scanf("%f", &ceiling);
  
  while (vary < ceiling) {
    mass = (molarMass * current * t) / (X * eMol);
    printf("Mass: %.4f\n", mass);
    vary++;
  }
  
  return 0;
}