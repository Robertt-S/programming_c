#include <stdio.h>

struct Text {
  char text[100];
};

//typedef struct Text Adjective; 

struct PersonalInfo {
  char name[100];
  int phoneNumber;
  struct Text characteristic;
};

int main() {
  struct PersonalInfo info = {0};
  
  scanf("%s", info.name);
  scanf("%d", &info.phoneNumber);
  scanf("%s", info.characteristic.text);
  
  printf("%s\n%d\n%s\n", info.name, info.phoneNumber, info.characteristic.text);
  
  return 0;
}