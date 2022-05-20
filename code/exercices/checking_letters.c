#include <stdio.h>                                                                                                                                                                                                                                                             

int main() {
  char character;
  
  printf("Give me a letter: \n");
  scanf("%c\n", &character);
  
  if ((int) character == 65 || (int) character == 69 || (int) character == 73 || (int) character == 79 || (int) character == 85 || (int) character == 97 || (int) character == 101 || (int) character == 105 || (int) character == 111 || (int) character == 117) {
    printf("The letter %c is vowel\n", character); 
  } else {
    printf("The letter %c is not a vowel\n", character);
  }
  return 0;
}

