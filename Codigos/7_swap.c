#include <stdio.h>
#include <stdlib.h>
int main () {
	int a, b, temp, *p, *q;
	p=&a;
	q=&b;
	scanf("%d %d", &a, &b);
	temp=*p;
	*p=*q;
	p=&temp;
	*q=*p;
	printf("%d %d", a, b);
	return 0;
}

/*
Implemente um programa que utilize ponteiros para trocar os valores de duas variáveis inteiras.
A função Swap irá trocar os valores das variáveis, utilizando ponteiros para acessar e modificar os valores delas.

Instruções:
- Leia dois números inteiros com `scanf`.
- Troque os valores dessas variáveis usando ponteiros.
- Imprima os valores trocados utilizando `printf`.

Exemplo de Entrada:
-50 100

Exemplo de Saída:
100 -50
*/
