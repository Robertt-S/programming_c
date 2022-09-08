#include <stdio.h>
#include <string.h>

struct personalInfo {
  char name[100];
  int pin;
  int phone;
};


void AskingInformation(struct personalInfo *info) {
  
  printf("Give me your name: \n");
  scanf("%s", info->name);
  
  printf("Give me your personal identification (without spaces): \n");
  scanf("%d", &info->pin);
  
  printf("Give me your phone number: \n");
  scanf("%d", &info->phone);
  
  return;
}


void InformationPrinter(struct personalInfo info) {
  
  printf("\nName: %s\nPersonal identification: %d\nPhone number: %d\n", info.name, info.pin, info.phone);
  
  return;
}




int main() {
  struct personalInfo info;
  
  AskingInformation(&info);
  InformationPrinter(info);
  
  return 0;
}