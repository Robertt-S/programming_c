#include <stdio.h>
#include <string.h>

void Capsule();

#define NAME_MAX 101
#define NUM_MAX 101
#define INFO_MAX 101

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

int Input() {
  int num;
  
  scanf("%d", &num);
  
  return num;
}

/*
void CharInput(char contact[NAME_MAX]) {
  scanf("%s", contact);
  
  return;
}

void CheckingIndex(struct PersonalInfo info[INFO_MAX],int index) {
  if (index < 1 || index > 100) {
    puts(INDEX_ERROR);
    Capsule(info);
  }
  return;
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

void CheckingList(struct PersonalInfo info[INFO_MAX]) {
  int index, count;
  
  count = 0;
  for (index = 0; index < INFO_MAX; index++) {
    if (strlen(info[index].name) == 0 || strlen(info[index].name) == 1) {
      count++;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == INFO_MAX) {
        puts(EMPTY_LIST);
        Capsule(info);
      }
    }
  }
  return;
}

void PrintingSingleContact(struct PersonalInfo info[INFO_MAX], int contact) {
  printf("Contato[%d]- Nome:%s Tel:%s\n", contact, info[contact].name, info[contact].phoneNumber);
  
  return;
}

void CheckingIndexEmptiness(struct PersonalInfo info[INFO_MAX], int index) {
  if ((strlen(info[index].name) == 0 || strlen(info[index].name) == 1) && (strlen(info[index].phoneNumber) == 0 || strlen(info[index].phoneNumber) == 1)) {
    puts(EMPTY_INDEX);
    Capsule(info);
  }
  return;
}

void DeletingPrintingContactList(struct PersonalInfo info[INFO_MAX]) {
  int contact;
  
  for (contact = 0; contact < INFO_MAX; contact++) {
    if (strlen(info[contact].name) == 0 || strlen(info[contact].name) == 1) {
      continue;
    }
    PrintingSingleContact(info, contact);
  }
  
  Capsule(info);
  
  return;
}

int CheckingNameContact(struct PersonalInfo info[INFO_MAX], char contact[NAME_MAX]) {
  int index, count, mark;
  
  count = 0;
  for (index = 0; index < INFO_MAX; index++) {
    if (strcmp(info[index].name, contact) == 0) {
      count++;
      mark = index;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == 0) {
        puts(NULL_CONTACT);
        //Capsule();
      }
    }
  }
  return mark;
}
*/

//=============================================================================


//=== 1 - Cadastra nome e número de telefone.
void GetNamePhone(struct PersonalInfo info[INFO_MAX]) {
  int index;
  
  index = Input();
  
  if (index < 1 || index > 100) {
    puts(INDEX_ERROR);
    Capsule(info);
  }
  
  scanf("%s", info[index].name);
  scanf("%s", info[index].phoneNumber);
  
  while (strlen(info[index].phoneNumber) != 10 && strlen(info[index].phoneNumber) != 11) {
    puts(PHONE_ERROR);
    scanf("%s", info[index].phoneNumber);
  }
  
  puts(SUCCESSFUL_REGISTRATION);
  
  Capsule(info);
  
  return;
}

//===  2- Exibidor da lista de contatos inteira.
void PrintingContactList(struct PersonalInfo info[INFO_MAX]) {
  int index, count;
  
  count = 0;
  for (index = 0; index < INFO_MAX; index++) {
    if (strlen(info[index].name) == 0 || strlen(info[index].name) == 1) {
      count++;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == INFO_MAX) {
        puts(EMPTY_LIST);
        Capsule(info);
      }
    }
  }
  
  for (index = 0; index < INFO_MAX; index++) {
    if (strlen(info[index].name) == 0 || strlen(info[index].name) == 1) {
      continue;
    }
    printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
  }
  
  Capsule(info);
  
  return;
}

//=== 3 - Exibidor de um único contato.
void ShowingSingleContact(struct PersonalInfo info[INFO_MAX]) {
  int index, count;
  
  index = Input();
  
  if (index < 1 || index > 100) {
    puts(INDEX_ERROR);
    Capsule(info);
  }
  
  if (strlen(info[index].name) == 0 || strlen(info[index].name) == 1) {
    puts(EMPTY_INDEX); // NULL_CONTACT
    Capsule(info);
  } else {
    printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
  }
  
  count = 0;
  for (index = 0; index < INFO_MAX; index++) {
    if (strlen(info[index].name) == 0 || strlen(info[index].name) == 1) {
      count++;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == INFO_MAX) {
        puts(EMPTY_LIST);
        Capsule(info);
      }
    }
  }
  
  Capsule(info);
  
  return;
}

//=== 4 - Deleção através do índice do contato.
void PhoneDeletingContact(struct PersonalInfo info[INFO_MAX]) {
  char cleaner[2] = {' '};
  int index;
  
  index = Input();
  
  if (index < 1 || index > 100) {
    puts(INDEX_ERROR);
    Capsule(info);
  }
  
  if ((strlen(info[index].name) == 0 || strlen(info[index].name) == 1) && (strlen(info[index].phoneNumber) == 0 || strlen(info[index].phoneNumber) == 1)) {
    puts(EMPTY_INDEX);
    Capsule(info);
  }
  
  strcpy(info[index].name, cleaner);
  strcpy(info[index].phoneNumber, cleaner);
  
  puts(REMOVED_CONTACT);
  
  for (index = 0; index < INFO_MAX; index++) {
    if (strlen(info[index].name) == 0 || strlen(info[index].name) == 1) {
      continue;
    }
    printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
  }
  
  Capsule(info);
  
  return;
}

//=== 5 - Deleção através do nome.
void NameDeletingContact(struct PersonalInfo info[INFO_MAX]) {
  char contact[NAME_MAX], cleaner[4] = {' '};
  int index, count, mark;
  
  scanf("%s", contact);
  
  mark = 0;
  count = 0;
  for (index = 0; index < INFO_MAX; index++) {
    if (strcmp(info[index].name, contact) == 0) {
      count++;
      mark = index;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == 0) {
        puts(NULL_CONTACT);
        //Capsule();
      }
    }
  }
  
  //CheckingNameEmptiness(info, contact);
  
  if (count != 0) {
    strcpy(info[mark].name, cleaner);
    strcpy(info[mark].phoneNumber, cleaner);
  
    puts(REMOVED_CONTACT);
  }
  
  for (index = 0; index < INFO_MAX; index++) {
    if (strlen(info[index].name) == 0 || strlen(info[index].name) == 1) {
      continue;
    }
    printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
  }
  
  Capsule(info);
  
  return;
}

//=== Saída da aplicação.
void End() {
  puts(END);
  
  return;
}

//=== Opções para serem escolhidas.
void Capsule(struct PersonalInfo info[INFO_MAX]) {
  int chooseOption;
  
  chooseOption = Input();
  
  while (chooseOption < 0 || chooseOption > 5) {
    puts(END_CHOOSE);
    chooseOption = Input();
  }
  
  if (chooseOption == 1) {
    GetNamePhone(info);
  } else if (chooseOption == 2) {
    PrintingContactList(info);
  } else if (chooseOption == 3) {
    ShowingSingleContact(info);
  } else if (chooseOption == 4) {
    PhoneDeletingContact(info);
  } else if (chooseOption == 5) {
    NameDeletingContact(info);
  } else if (chooseOption == 0) {
    End();
    return;
  }
  return;
}




int main() {
  struct PersonalInfo info[INFO_MAX] = {0};
  
  Capsule(info);
  
  return 0;
}