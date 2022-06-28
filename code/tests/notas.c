#include <stdio.h>

int main() {

  float nota0[50];
  float nota1[50];
  float nota2[50];
  float nota3[50];

  float media_aluno,media_classe;
  int n, i;

  printf("Número de alunos: ");
  scanf("%d", &n); // n precisa ser até 100

  printf("Nota 0:\n");

  for (i = 0; i < n; i++) {
    printf("Nota do aluno %d: ", i+1);
    scanf("%f", &nota0[i]);
  }

  printf("Nota 1:\n");

  for (i = 0; i < n; i++) {
    printf("Nota do aluno %d: ", i+1);
    scanf("%f", &nota1[i]);
  }

  printf("Nota 2:\n");

  for (i = 0; i < n; i++) {
    printf("Nota do aluno %d: ", i+1);
    scanf("%f", &nota2[i]);
  }

  printf("Nota 3:\n");

  for (i = 0; i < n; i++) {
    printf("Nota do aluno %d: ", i+1);
    scanf("%f", &nota3[i]);
  }

  media_aluno = 0.0; // inicializacao da variavel "media"
  media_classe = 0.0; 

  for (i = 0; i < n; i++){ 
    media_aluno = (nota0[i] + nota1[i] + nota2[i] + nota3[i])/4;
    printf("Media do aluno %d e: %0.1f\n",i+1,media_aluno); 
  }
//  media /= n; // media = media / n  valores reais
 
//  printf("Nota média = %.1f\n", media);

  return 0;

}