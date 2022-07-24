#include <stdio.h>
#include <string.h>

struct information {
  char name[100];
  char number[100];
};


void ExtractingInfo(struct information info[100]) {
  int num = 0;
  int i;
  scanf("%d", &num);
  
  fgets(info[num].name, 300, stdin);
  
  fgets(info[num].number, 200, stdin);
  
  /*
  scanf("%s", info[num].name);
  scanf("%s", info[num].number);
  
  printf("%s\n", info[num].name);
  printf("%s\n", info[num].number);
  */
  return;
}



int main() {
  struct information info[100];
  
  ExtractingInfo(info);
  
}