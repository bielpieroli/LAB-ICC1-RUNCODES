#include <stdio.h>
#include <stdlib.h>

int soma_recursiva(int a, int b) {
    if(b == 0) {
        return a;
    }
    return soma_recursiva(++a,--b);
}
int main (void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", soma_recursiva(a,b));
}
/*
Faça um programa RECURSIVO que some 2 números inteiros, NÃO negativos !!!!! Só vale com recursão.....
EXEMPLO:
 - ENTRADA:
4
5
 - SAIDA:
9
*/