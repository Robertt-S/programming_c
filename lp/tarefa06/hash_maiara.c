#include <stdio.h>
#include <string.h>

void Receber_texto(char texto[100], char texto2[100]) {
  fgets(texto, 100, stdin);
  fgets(texto2, 100, stdin);
  return;
}



void Contar(char texto[100], char texto2[100], int *soma, int *soma2) {
  int i;
  *soma = 0;
  *soma2 = 0;

  for(i = 0; i < strlen(texto); i++) {
    (*soma) += texto[i];

  }

  for(i = 0; i < strlen(texto2); i++) {
    (*soma2) += texto2[i];

  }


  for (i = 0; i < strlen(texto); i++) {
    if (i == strlen(texto) - 1) {
      texto[i] = 0;
    }
  }

  for (i = 0; i < strlen(texto2); i++) {
    if (i == strlen(texto2) - 1) {
      texto2[i] = 0;
    }
  }

  return;
}

void Imprimir(char texto[100], char texto2[100], int *soma, int *soma2) {

  printf("Str1: %s - Codificaçao Hash: %d\n", texto, (*soma));
  printf("Str2: %s - Codificaçao Hash: %d", texto2, (*soma2));
  return;
}

//////////
int main() {
  char texto[100];
  char texto2[100];
  int soma, soma2;

  Receber_texto(texto, texto2);
  Contar (texto, texto2, &soma, &soma2);
  Imprimir(texto, texto2, &soma, &soma2);

  return 0;
}