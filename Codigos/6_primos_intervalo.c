#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main () {
	int a, b, primomaior=0, primomenor=0;
	bool primo;
	scanf("%d %d", &a, &b);
	for(int i=a; i<=b; i++) {
	    primo=1;
	    if (i==1) {
	        primo=0;
	    }
	    for (int j=2; j*j<=i; j++) {
	        if(i%j==0) {
	            primo=0;
	            break;
	        }

	    }
	    if(primo==1) {
	            primomaior=i;
	       }
	       if(primomenor==0 && primo==1) {
	            primomenor=i;
	    }
	}
	if (primomenor==0 && primomaior==0) {
        printf("nenhum primo no intervalo\n");
    } else {
	printf("menor primo: %d\nmaior primo: %d\n", primomenor, primomaior);
    }
	return (0);
}
/*
Implemente um programa que leia dois inteiros a e b e encontre o menor e o maior numero primo
no intervalo fechado [a, b]. O programa deve verificar se existem primos nesse intervalo e, se 
existirem, imprimir o menor e o maior primo encontrados.

Requisitos:
- O programa deve ler dois inteiros a e b.
- Verificar se existem números primos no intervalo entre a e b (inclusive).
- Se houver primos, imprimir o menor e o maior deles.
- Se não houver primos, imprimir a mensagem "nenhum primo no intervalo".

Exemplo de Saída:
Para a entrada 10 32, a saída deve ser:
menor primo : 11
maior primo : 31
*/
