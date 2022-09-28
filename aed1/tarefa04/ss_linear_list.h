#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define NAME_MAX 50

typedef struct{
  int chave;
  char nome[50];
} TipoItem;

typedef struct{
  TipoItem itens[MAX];
  int ultimo;
} ListaLinearSE;

void inicializaLLSE(ListaLinearSE*);
void imprimeListaLLSE(ListaLinearSE*);
int insereNoFinalLLSE(ListaLinearSE*,TipoItem);
int removeDoFinalLLSE(ListaLinearSE*,TipoItem*);
int removeDoComecoLLSE(ListaLinearSE*,TipoItem*);
int searchItemByName(ListaLinearSE*, char string[]);