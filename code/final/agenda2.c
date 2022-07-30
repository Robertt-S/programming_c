#include <stdio.h>
#include <string.h>

#define NAME_MAX 100
#define NUM_MAX 100
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

void CharInput(char contactName[NAME_MAX]) {
  scanf("%s", contactName);
  
  return;
}

/*
void GetNamePhone(struct PersonalInfo info[INFO_MAX]) {
  int index, sum;
  
  sum = 0;
  
  scanf("%d", &index);
  
  if (index < 1 || index > 100) {
    printf("Índice digitado não existe [1,100]!\n");
  } else {
    scanf("%s", info[index].name);
    scanf("%s", info[index].phoneNumber);
    sum = strlen(info[index].phoneNumber);
    
    if (((strlen(info[index].phoneNumber)) == 10) || (strlen(info[index].phoneNumber)) == 11) {
      printf("Contato cadastrado com sucesso!\n");
    } else {
      do {
        printf("Telefone não tem 10 ou 11 dígitos! Favor digite novamente.\n");
        scanf("%s", info[index].phoneNumber);
      } while (((strlen(info[index].phoneNumber)) != 10) && (strlen(info[index].phoneNumber)) != 11);
      printf("Contato cadastrado com sucesso!\n");
    }
  }
  return;
}
*/

//=== 1 - Cadastra nome e número de telefone.
void GetNamePhone(struct PersonalInfo info[INFO_MAX]) {
  int index;
  
  index = Input();
  
  if (index < 1 || index > 100) {
    puts(INDEX_ERROR);
    return;
  } else {
    scanf("%s", info[index].name);
    scanf("%s", info[index].phoneNumber);
    
    while (strlen(info[index].phoneNumber) != 10 && strlen(info[index].phoneNumber) != 11) {
      puts(PHONE_ERROR);
      scanf("%s", info[index].phoneNumber);
    }
    puts(SUCCESSFUL_REGISTRATION);
    return;
  }
}



// Dá 93
void PrintContactList(struct PersonalInfo info[INFO_MAX]) {
  int i, j, count;
  
  count = 0;
  for (i = 1; i < INFO_MAX; i++) {
    if (((strlen(info[i].phoneNumber)) == 10) || (strlen(info[i].phoneNumber)) == 11) {
      count++;
    }
  }
    
  if (count == 0) {
    printf("Agenda vazia!\n");
    return;
  } else {
    for (j = 1; j < INFO_MAX; j++) {
      if (((strlen(info[j].phoneNumber)) == 10) || (strlen(info[j].phoneNumber)) == 11) {
        printf("Contato[%d]- Nome:%s Tel:%s\n", j, info[j].name, info[j].phoneNumber);
      }
    }
    return;
  }
}

/*=== 2 - Exibidor da lista de contatos inteira.
void PrintContactList(struct PersonalInfo info[INFO_MAX]) {
  int index, count;
  
  count = 0;
  for (index = 1; index <= INFO_MAX; index++) {
    if (strlen(info[index].name) == 0) {
      count++;
    }
    
    if (index == INFO_MAX) {
      if (count == INFO_MAX) {
        puts(EMPTY_LIST);
        return;
      } else {
        for (index = 1; index <= INFO_MAX; index++) {
          if (strlen(info[index].name) == 0) {
            continue;
          }
          printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
        }
      } 
      
    }
  }
  return;
}
*/






/*
void ShowingSingleContact(struct PersonalInfo info[INFO_MAX]) {
  int index, i, count;
  
  count = 0;
  for (i = 1; i < INFO_MAX; i++) {
    if (((strlen(info[i].phoneNumber)) == 10) || (strlen(info[i].phoneNumber)) == 11) {
      count++;
    }
    
    if (i == INFO_MAX - 1) {
      if (count == 0) {
        printf("Agenda vazia!\n");
        return;
      }
    }
  }
  
  
  scanf("%d", &index);
  if (index < 1 || index > 100) {
    printf("Índice digitado não existe [1,100]!\n");
  } else if (((strlen(info[index].phoneNumber)) == 10) || (strlen(info[index].phoneNumber)) == 11) {
    printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
  } else {
    printf("Índice está vazio!\n");
  }
  
  return;
}
*/



//=== 3 - Exibidor de um único contato.
void ShowingSingleContact(struct PersonalInfo info[INFO_MAX]) {
  int index, count;
  
  count = 0;
  for (index = 1; index < INFO_MAX; index++) {
    if (strlen(info[index].phoneNumber) == 0) {
      count++;
    }
  }
  
  if (count == INFO_MAX) {
    //printf("%s\n" EMPTY_LIST);
    puts(EMPTY_LIST);
    return;
  }
  
  scanf("%d", &index);
  
  if (index < 1 || index > 100) {
    //printf("%s\n", INDEX_ERROR);
    puts(INDEX_ERROR);
    return;
  }
  
  if (strlen(info[index].phoneNumber) == 0) {
    //printf("%s\n", EMPTY_INDEX);
    puts(EMPTY_INDEX); // NULL_CONTACT
  } else {
    printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
    return;
  }
}






/*
void PhoneDeletingContact(struct PersonalInfo info[INFO_MAX]) {
  int index, j;
  
  scanf("%d", &index);
  if (index < 0 || index > 100) {
    printf("Índice digitado não existe [1,100]!\n");
  } else {
    if (((strlen(info[index].phoneNumber)) == 10) || (strlen(info[index].phoneNumber)) == 11) {
      strcpy(info[index].phoneNumber, "0");
      printf ("Contato removido com sucesso!\n");
      for (j = 1; INFO_MAX > j; j++) {
        if (((strlen(info[j].phoneNumber)) == 10) || (strlen(info[j].phoneNumber)) == 11) {
          printf("Contato[%d]- Nome:%s Tel:%s\n", j, info[j].name, info[j].phoneNumber);
        }
      }
    } else {
      printf ("Índice digitado está vazio!\n");
    }
  }
  return;
}
*/


//=== 4 - Deleção através do índice do contato.
void PhoneDeletingContact(struct PersonalInfo info[INFO_MAX]) {
  char cleaner[1] = {'\0'};
  int index = 0;
  
  index = Input();
  
  if (index < 1 || index > 100) {
    puts(INDEX_ERROR);
    return;
  } else if (strlen(info[index].name) == 0) {
    puts(EMPTY_INDEX); // NULL_CONTACT
    return;
  } else {
    strcpy(info[index].name, cleaner);
    strcpy(info[index].phoneNumber, cleaner);
    
    puts(REMOVED_CONTACT);
  }
  
  for (index = 1; index < INFO_MAX; index++) {
    if (strlen(info[index].name) != 0) {
      printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
    }
  }
  return;
}







/*
void DeletingContactName(struct PersonalInfo info[INFO_MAX]) {
  int i, count;
  char nameAux[INFO_MAX];
  
  scanf("%s", nameAux);
  
  count = 0;
  
  for (i = 1; INFO_MAX > i; i++) {
    if ((strcmp(nameAux, info[i].name)) == 0) {
      count++;
    }
  }
  
  if (count == 0) {
    printf("Contato digitado não existe!\n");
  } else {
    for (int i = 0; i < INFO_MAX; i++) {
      if (strcmp(nameAux, info[i].name) == 0) {
        strcpy(info[i].phoneNumber, "0");
        printf("Contato removido com sucesso!\n");
      }
    }
  }
  return;
}
*/


//=== 5 - Deleção através do nome.
void DeletingContactName(struct PersonalInfo info[INFO_MAX]) {
  char contactName[NAME_MAX], cleaner[1] = {'\0'};
  int index, count, mark;
  
  CharInput(contactName);
  
  mark = 0;
  count = 0;
  for (index = 1; index < INFO_MAX; index++) {
    if (strcmp(info[index].name, contactName) == 0) {
      count++;
      mark = index;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == 0) {
        puts(NULL_CONTACT);
        return;
      } else {
        strcpy(info[mark].name, cleaner);
        strcpy(info[mark].phoneNumber, cleaner);
        
        puts(REMOVED_CONTACT);
      }
    }
  }
  
  for (index = 1; index < INFO_MAX; index++) {
    if (strlen(info[index].name) != 0) {
      printf("Contato[%d]- Nome:%s Tel:%s\n", index, info[index].name, info[index].phoneNumber);
    }
  }
  return;
}


//=== Saída da aplicação.
void End() {
  puts(END);
  return;
}


//=== Menu de opções.
int main() {
  struct PersonalInfo info[INFO_MAX] = {'\0'};
  int chooseOption = 0;
  
  do {
    chooseOption = Input();
    
    if (chooseOption < 0 || chooseOption > 5) {
      puts(END_CHOOSE);
      continue;
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
    }
  } while (chooseOption != 0);
  
  return 0;
}


/*
1
1
Fabio
1234567890
1
2
Vitor
1234567891
2 =
1
7
Sergio
111111111
1111111111 ==
3
6 ===
2 +
3 ++
7
4 !!!
2 !!!
5 ???
Fabi ???
5 ;;;
Fabio ;;;
2
0

Saída 4:
Contato cadastrado com sucesso!
Contato cadastrado com sucesso!
Contato[1]- Nome:Fabio Tel:1234567890
Contato[2]- Nome:Vitor Tel:1234567891  =
Telefone não tem 10 ou 11 dígitos! Favor digite novamente.
Contato cadastrado com sucesso! ==
Índice digitado está vazio! ===
Contato[1]- Nome:Fabio Tel:1234567890 +
Contato[2]- Nome:Vitor Tel:1234567891 +
Contato[7]- Nome:Sergio Tel:1111111111 +
Contato[7]- Nome:Sergio Tel:1111111111 ++
Contato removido com sucesso! !!!
Contato[1]- Nome:Fabio Tel:1234567890 !!!
Contato[7]- Nome:Sergio Tel:1111111111 !!!
Contato digitado não existe! ???
Contato removido com sucesso! ;;;
Contato[7]- Nome:Sergio Tel:1111111111
Contato[7]- Nome:Sergio Tel:1111111111
Tchau!
*/
