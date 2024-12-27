#include <stdio.h>
#include <stdlib.h>
int main () {
	int n, *p, **q;
	p=&n;
	q=&p;
	scanf("%d", &n);
	printf("Valor inicial da variavel: %d\n", n);
	printf("Valor do ponteiro antes do incremento: %d\n", *p);
	(*p)+=10;
	printf("Valor do ponteiro depois do incremento: %d\n", *p);
	printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **q);
	(**q)+=10;
	printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **q);
	printf("Valor final da variavel: %d\n", n);
	return 0;
}
/*
Implemente um programa que usa ponteiros e ponteiros para ponteiros. O objetivo é realizar a manipulação de uma variável inteira através de ponteiros.

Passos:
1. Leia o valor de uma variável inteira.
2. Crie um ponteiro (*p) que receba o endereço dessa variável e acrescente 10 ao valor da variável através desse ponteiro.
3. Crie um ponteiro para ponteiro (**p) que receba o endereço do ponteiro *p e acrescente mais 10 ao valor da variável através do ponteiro para ponteiro.
4. Imprima o valor inicial da variável, o valor antes e depois do incremento através do ponteiro, e o valor antes e depois do incremento através do ponteiro para ponteiro.
5. Imprima o valor final da variável.

Exemplo de Entrada:
10

Exemplo de Saída:
Valor inicial da variavel : 10
Valor do ponteiro antes do incremento : 10
Valor do ponteiro depois do incremento : 20
Valor do ponteiro para ponteiro antes do incremento : 20
Valor do ponteiro para ponteiro depois da mudanca : 30
Valor final da variavel : 30
*/
