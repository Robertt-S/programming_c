#include <stdio.h>
#include <string.h>


struct test {
  char name[100];
  char num[100];
};


int main() {
  struct test info[100];
  
  scanf("%s", info[1].name);
  scanf("%s", info[1].num);
  
  puts(info[1].name);
  
  
  return 0;
}