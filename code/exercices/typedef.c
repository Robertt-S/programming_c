#include <stdio.h>
#include <string.h>

typedef float grade;

void Receiver(grade *student) {
  
  scanf("%f", student);
  
  return;
}

void Printer(grade student) {
  
  printf("The grade is: %.2f\n", student);
  
  return;
}


int main() {
  grade student;
  
  Receiver(&student);
  Printer(student);
  
  return 0;
}