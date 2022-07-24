/*
#include <stdio.h>

struct data {
  char name[100];
  char number[100];
};


void Modifier(struct data info[100]) {
  
  
  scanf("%s", info[1].name);
  scanf("%s", info[1].number);
  
  return;
}


int main() {
  struct data info[100];
  
  Modifier(info);
  
  printf("%s%s", info[1].name, info[1].number);
  
  return 0;
}
*/

//=== Não funciona

#include <stdio.h>

struct data {
  char name[100];
  char number[100];
};


void Modifier() {
  struct data info[100];
  
  scanf("%s", info[1].name);
  scanf("%s", info[1].number);
  
  return;
}


int main() {
  struct data info[100];
  
  Modifier();
  
  printf("%s%s", info[1].name, info[1].number);
  
  return 0;
}
