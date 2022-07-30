#include <stdio.h>
#include <string.h>

#define NAME_MAX 100
#define NUM_MAX 100
#define INFO_MAX 100

#define SUCCESSFUL_REGISTRATION "Contato cadastrado com sucesso!"
#define INDEX_ERROR "Índice digitado não existe [1, 100]!"
#define PHONE_ERROR "Telefone não tem 10 ou 11 dígitos! Favor digite novamente."
#define EMPTY_LIST "Agenda Vazia!"
#define REMOVED_CONTACT "Contato removido com sucesso!"
#define EMPTY_INDEX "Índice digitado está vazio!"
#define NULL_CONTACT "Contato digitado não existe!"
#define END_CHOOSE "Escolha valores entre 0 e 5!"
#define END "Tchau!"

struct PersonalInfo {
  char name[NAME_MAX];
  char phoneNumber[NUM_MAX];
};

//==== Funções usadas posteriormente

int Input() {
  int num;
  
  scanf("%d", &num);
  
  return num;
}

void CharInput(char contactName[NAME_MAX]) {
  scanf("%s", contactName);
  
  return;
}

int CheckingIndex(struct PersonalInfo info[INFO_MAX],int index) {
  if (index < 1 || index > 100) {
    return 0;
  }
  return 1;
}

void SettingNamePhone(struct PersonalInfo info[INFO_MAX], int index) {
  scanf("%s", info[index].name);
  scanf("%s", info[index].phoneNumber);
  
  return;
}

void CheckingPhone(struct PersonalInfo info[INFO_MAX], int index) {
  while (strlen(info[index].phoneNumber) != 10 && strlen(info[index].phoneNumber) != 11) {
    puts(PHONE_ERROR);
    scanf("%s", info[index].phoneNumber);
  }
  return;
}

int CheckingList(struct PersonalInfo info[INFO_MAX]) {
  int index, count;
  
  count = 0;
  for (index = 1; index <= INFO_MAX; index++) {
    if (strlen(info[index].name) == 0) {
      count++;
    }
    
    if (index == INFO_MAX) {
      if (count == INFO_MAX) {
        return 0;
      }
    }
  }
  return 1;
}

void PrintingSingleContact(struct PersonalInfo info[INFO_MAX], int contactIndex) {
  printf("Contato[%d]- Nome:%s Tel:%s\n", contactIndex, info[contactIndex].name, info[contactIndex].phoneNumber);
  
  return;
}

void PrintingContactList(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  for (contactIndex = 1; contactIndex <= INFO_MAX; contactIndex++) {
    if (strlen(info[contactIndex].name) == 0) {
      continue;
    }
    PrintingSingleContact(info, contactIndex);
  }
  return;
}

void CheckingContactEmptiness(struct PersonalInfo info[INFO_MAX], int contactIndex) {
  if (strlen(info[contactIndex].name) == 0 || strlen(info[contactIndex].name) == 1) {
    puts(EMPTY_INDEX); // NULL_CONTACT
  } else {
    PrintingSingleContact(info, contactIndex);
  }
  return;
}

int CheckingIndexEmptiness(struct PersonalInfo info[INFO_MAX], int index) {
  if ((strlen(info[index].name) == 0 || strlen(info[index].name) == 1) && (strlen(info[index].phoneNumber) == 0 || strlen(info[index].phoneNumber) == 1)) {
    return 0;
  }
  return 1;
}

void DeletingPrintingContactList(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  for (contactIndex = 1; contactIndex <= INFO_MAX; contactIndex++) {
    if (strlen(info[contactIndex].name) == 0 || strlen(info[contactIndex].name) == 1) {
      continue;
    }
    PrintingSingleContact(info, contactIndex);
  }
  return;
}

int CheckingContactName(struct PersonalInfo info[INFO_MAX], char contactName[NAME_MAX]) {
  int index, count, mark;
  
  mark = 0;
  count = 0;
  for (index = 1; index <= INFO_MAX; index++) {
    if (strcmp(info[index].name, contactName) == 0) {
      count++;
      mark = index;
    }
    
    if (index == INFO_MAX) {
      if (count == 0) {
        puts(NULL_CONTACT);
      }
    }
  }
  return mark;
}

void Cleaner(struct PersonalInfo info[INFO_MAX], int contactIndex) {
  char cleaner[INFO_MAX] = {0};
  
  strcpy(info[contactIndex].name, cleaner);
  strcpy(info[contactIndex].phoneNumber, cleaner);
  
  puts(REMOVED_CONTACT);
  
  return;
}


//=============================================================================


//=== 1 - Cadastra nome e número de telefone.
void GetNamePhone(struct PersonalInfo info[INFO_MAX]) {
  int index;
  
  index = Input();
  
  if (CheckingIndex(info, index) == 0) {
    puts(INDEX_ERROR);
  } else {
    SettingNamePhone(info, index);
    CheckingPhone(info, index);
    puts(SUCCESSFUL_REGISTRATION);
  }
  return;
}

//=== 2 - Exibidor da lista de contatos inteira.
void PrintContactList(struct PersonalInfo info[INFO_MAX]) {
  
  if (CheckingList(info) == 0) {
    puts(EMPTY_LIST);
  } else {
    PrintingContactList(info);
  }
  return;
}

//=== 3 - Exibidor de um único contato.
void ShowingSingleContact(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  if (CheckingList(info) == 0) {
    puts(EMPTY_LIST);
    return;
  }
  
  contactIndex = Input();
  
  if (CheckingIndex(info, contactIndex) == 0) {
    puts(INDEX_ERROR);
    return;
  }
  
  CheckingContactEmptiness(info, contactIndex);
  
  return;
}

//=== 4 - Deleção através do índice do contato.
void PhoneDeletingContact(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  contactIndex = Input();
  
  if (CheckingIndex(info, contactIndex) == 0) {
    puts(INDEX_ERROR);
    return;
  } else if (CheckingIndexEmptiness(info, contactIndex) == 0) {
    puts(EMPTY_INDEX);
    return;
  }
  
  Cleaner(info, contactIndex);
  DeletingPrintingContactList(info);
  
  return;
}

//=== 5 - Deleção através do nome.
void DeletingContactName(struct PersonalInfo info[INFO_MAX]) {
  char contactName[NAME_MAX];
  int index;
  
  CharInput(contactName);
  
  index = CheckingContactName(info, contactName);
  
  if (index != 0) {
   Cleaner(info, index);
   DeletingPrintingContactList(info);
  }
  return;
}

//=== Saída da aplicação.
int End() {
  puts(END);
  
  return 0;
}



//=== Menu de opções.
int main() {
  struct PersonalInfo info[INFO_MAX] = {0};
  int chooseOption = 10;
  
  while (chooseOption != 0) {
    chooseOption = Input();
    
    while (chooseOption < 0 || chooseOption > 5) {
      puts(END_CHOOSE);
      chooseOption = Input();
    }
    
    if (chooseOption == 1) {
      GetNamePhone(info);
    } else if (chooseOption == 2) {
      PrintContactList(info);
    } else if (chooseOption == 3) {
      ShowingSingleContact(info);
    } else if (chooseOption == 4) {
      PhoneDeletingContact(info);
    } else if (chooseOption == 5) {
      DeletingContactName(info);
    } else if (chooseOption == 0) {
      End();
      return 0;
    }
  }
  return 0;
}