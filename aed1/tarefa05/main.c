#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaLinearED.h"

void imprimeMenu();
void leDadosAluno(TipoItem*);
void imprimeDadosAluno(TipoItem);

int main(){
  ListaLinearED turmaAED;
  int op = 0, RA, pos;
  TipoItem item;
  
  inicializaListaLLED(&turmaAED);
  
  while(op != 5){
    imprimeMenu();
    printf("Opcao: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosAluno(&item);
        if(insereNoFinalLLED(&turmaAED,item)){
          printf("\nAluno matriculado!\n");
        }
        else{
          printf("\nNão foi possível matricular o aluno!\n");
        }
        break;
      case 2:
        break;
      case 3:
        printf("RA a ser buscado: ");
        scanf("%i",&RA);
        if(buscaItemNaListaLLED(&turmaAED,RA,&item,&pos)){
          printf("\nAluno:\n");
          imprimeDadosAluno(item);
        }
        else{
          printf("\nAluno não encontrado!\n");
        }
        break;
      case 4:
        if(!listaVaziaLLED(&turmaAED)){
          printf("\nAlunos:\n");
          imprimeListaLLED(&turmaAED);
        }
        else{
          printf("\nNenhum aluno matriculado!\n");
        }
        break;
      case 5:
        destroiListaLLED(&turmaAED);
        printf("\nFim!\n");
        break;
      default:
        printf("\nOpção incorreta!\n");
        break;
    }
  }
}

void imprimeMenu(){
  printf("\nMenu:");
  printf("\n1 - Inserir aluno.");
  printf("\n2 - Retirar aluno.");
  printf("\n3 - Buscar aluno pelo RA.");
  printf("\n4 - Listar Alunos.");
  printf("\n5 - Sair.");
}

void leDadosAluno(TipoItem *item){
  int i;
  printf("\nRA: ");
  scanf("%i",&item->RA);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&item->notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&item->freq);
}

void imprimeDadosAluno(TipoItem item){
  int i;
  printf("\nRa: %i",item.RA);
  printf("\nNome: %s",item.nome);
  for(i=0;i<3;i++){
    printf("\nNota %i: %.1f",i+1,item.notas[i]);
  }
  printf("\nFrequencia: %i\n",item.freq);
}


/*


*/