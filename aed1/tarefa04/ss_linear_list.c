#include "ss_linear_list.h"

void inicializaLLSE(ListaLinearSE *lista){
  lista->ultimo = 0;
}

void imprimeListaLLSE(ListaLinearSE *lista){
  int i;

  for(i=0;i<lista->ultimo;i++){
    printf("%i %s\n",lista->itens[i].chave,lista->itens[i].nome);
  }
}


int insereNoFinalLLSE(ListaLinearSE *lista, TipoItem novoItem){
  int pos = lista->ultimo;

  if(pos < MAX){
    lista->itens[pos] = novoItem;
    lista->ultimo++;
    return 0;
  }
  else
    return -1;
}

int removeDoFinalLLSE(ListaLinearSE *lista,TipoItem *item){
  int pos = lista->ultimo;

  if(pos>0){
    item->chave = lista->itens[pos-1].chave;
    strcpy(item->nome,lista->itens[pos-1].nome);
    lista->ultimo--;
    return 0;
  }
  else
    return -1;
}

int removeDoComecoLLSE(ListaLinearSE *lista,TipoItem *item){
  int pos = lista->ultimo;
  int i;
  
  if(pos>0){
    item->chave = lista->itens[0].chave;
    strcpy(item->nome,lista->itens[0].nome);
    for(i=1;i<pos;i++){
      lista->itens[i-1].chave = lista->itens[i].chave;
      strcpy(lista->itens[i-1].nome,lista->itens[i].nome);
    }
    lista->ultimo--;
    return 0;
  }
  else
    return -1;
}


int searchItemByName(ListaLinearSE *lista, char name[NAME_MAX]) {
  int i;

  for (i = 0; i < lista->ultimo; i++) {
    if (strcmp(lista->itens[i].nome, name) == 0) {
      printf("item: %s\n", lista->itens[i].nome);
      return lista->itens[i].chave;
    }
  }
  
  return -1;
}