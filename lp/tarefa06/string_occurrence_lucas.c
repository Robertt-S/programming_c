#include <stdio.h>
#include <string.h>

void Receber_String(char string1[1000], char string2[1000]) {
  fgets(string1, 1000, stdin);
  fgets(string2, 1000, stdin);
  return;
}

void Inicializar_string(int i, char string[i]) {
  for (i = 0; i < 1000; i++) {
    string[i] = ' ';
  }
  return;
}

int Comparar_Strings(int i, char string1[i], int k, char string2[k], int ocor, int auxI, int auxK) {
  ocor = 0;

  for (k = 0; k < strlen(string2) - 1; k++) {
    for (i = 0; i < strlen(string1) - 1; i++) {
      if (string2[k] == string1[i]){
        auxI = i;
        auxK = k;
        i++;
        k++;
        if (string2[k] == string1[i]) {
          ocor++;
        } else {
         k = auxK;
         i = auxI;
         continue;
        }
        k = auxK;
        i = auxI;
      } else {
        continue;
      }
    }
  }
  return ocor;
}

void Quantidade_Ocorrencias(int ocor) {
  printf("\nNúmero de ocorrência: %d", ocor);
  return;
}

int main() {
  char string1[1000], string2[1000];
  int i, k, ocor, x, auxK, auxI;

  Inicializar_string(i, &string1[i]);
  Inicializar_string(i, &string2[i]);

  Receber_String(string1, string2);

  x = Comparar_Strings(i, &string1[i], k, &string2[k], ocor, auxI, auxK);
  Quantidade_Ocorrencias(x);

  return 0;
}