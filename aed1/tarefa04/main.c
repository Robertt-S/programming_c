#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ss_linear_list.c"

int main(){
  ListaLinearSE lista;
  TipoItem item;
  int i,n;
  char compareName[NAME_MAX];
  
  inicializaLLSE(&lista);
  
  printf("Número de itens a serem inseridos: ");
  scanf("%i",&n);
  for(i=0;i<n;i++){
    printf("Item %i\n",i+1);
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    item.nome[strlen(item.nome)-1] = '\0';
    if(insereNoFinalLLSE(&lista,item)<0){
      printf("Erro! Tamanho limite excedido!\n");
      break;
    }
  }

  printf("\nItens na lista:\n");
  imprimeListaLLSE(&lista);

  if(removeDoFinalLLSE(&lista,&item)<0){
    printf("Erro! Lista Vazia!\n");
  }
  printf("\nItem removido: %i %s",item.chave,item.nome);

  printf("\nItens na lista:\n");
  imprimeListaLLSE(&lista);

  if(removeDoComecoLLSE(&lista,&item)<0){
    printf("Erro! Lista Vazia!\n");
  }
  printf("\nItem removido: %i %s",item.chave,item.nome);

  printf("\nItens na lista:\n");
  imprimeListaLLSE(&lista);
  
  printf("Dê-me o nome a buscar: ");
  scanf("%s", compareName);
  searchItemByName(&lista, compareName);
  
  
  return 0;
}