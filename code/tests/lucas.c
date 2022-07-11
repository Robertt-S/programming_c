#include <stdio.h>

int Receber_valores(int num){
    scanf("%d", &num);
    return (num);
}

int Somar_valores(int num1, int num2){
    int soma;
    soma = num1 + num2;
    return soma;
}

void Imprimir_valores(int result){
    printf("%d", result);
    return;
}

int main(){
    int num, num1, num2, resultado;
    num1 = Receber_valores(num);
    num2 = Receber_valores(num);
    
    resultado = Somar_valores(num1, num2);
    
    Imprimir_valores(resultado);
    
    return 0;
}

/*
#include <stdio.h>

int Receber_valores(int num1, int num2){
    int valor;
    scanf("%d", &valor);
    return valor;
}

int Somar_valores(int num1, int num2){
    int soma;
    soma = num1 + num2;
    return soma;
}

void Imprimir_valores(result){
    int result;
    printf("%d", result);
    return;
}

int main(){
    int num1, num2, resultado;
    num1 = Receber_valores(num1,num2);
    num2 = Receber_valores(num1,num2);
    
    resultado = Somar_valores(num1,num2);
    
    Imprimir_valores(resultado);
    
    return 0;
}
*/