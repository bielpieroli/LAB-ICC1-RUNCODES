#include <stdio.h>

int main (void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Soma: %d\n", a+b);
    printf("Subtracao: %d\n", a-b);
    printf("Multiplicacao: %d\n", a*b);
    printf("Divisao Inteira: %d\n", a/b);
    printf("Divisao Racional: %.3f\n", ((float) a)/b);
    return 0;
}

/*
Implemente um programa em C que leia na entrada padrao dois numeros e execute as 4 principais operacoes da calculadora (Adicao, Subtracao, Multiplicacao e Divisao).  
Imprima na tela o resultado das operacoes. No caso da divisao, lembre-se que pode ser inteira ou racional.  

EXEMPLOS:

Entrada  
20  
5  

Saida  
Soma : 25  
Subtracao : 15  
Multiplicacao : 100  
Divisao Inteira : 4  
Divisao Racional : 4.000  

Entrada  
4  
3  

Saida  
Soma : 7  
Subtracao : 1  
Multiplicacao : 12  
Divisao Inteira : 1  
Divisao Racional : 1.333 
*/