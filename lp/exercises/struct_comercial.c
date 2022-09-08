#include <stdio.h>

struct Nome {
  int i;
};


struct Info {
  int num;
  struct Nome j;
};



int main() {
  struct Info info[50] = {0};
  
  scanf("%d", &info[3].j.i);
  
  printf("%d\n", info[3].j.i);
  
  
  return 0;
}