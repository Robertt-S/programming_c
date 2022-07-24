#include <stdio.h>
#include <string.h>

enum month {
  January = 1,
  February, 
  March, 
  April, 
  May, 
  June, 
  July, 
  August, 
  September, 
  October, 
  November, 
  December
};

int main() {
  enum month birthDayMonth;
  
  birthDayMonth = February;
  
  printf("%d\n", birthDayMonth);
  
  return 0;
}