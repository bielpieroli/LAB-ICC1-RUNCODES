#include <stdio.h>
#include <stdlib.h>

int
main (void) {
	int centmil,dezuni;
	for (int num=1000; num<9802; num++) {
		centmil=num/100;
		dezuni=(num%1000)%100;
		if (num == (dezuni+centmil)*(dezuni+centmil)) {
			printf("%d\n", num);
		}
	}
	return EXIT_SUCCESS;
}
/*
Implemente um programa que analise todos os numeros de 4 digitos e imprima aqueles cuja raiz quadrada 
seja igual a soma das dezenas formadas pelos dois primeiros e dois ultimos digitos. A raiz quadrada do
numero deve ser comparada com a soma das dezenas. 

Exemplo:
Para o numero 9801, a raiz quadrada de 9801 é 99, que é a soma das dezenas 98 e 01.

Requisitos:
- O programa deve percorrer todos os numeros de 4 digitos.
- Para cada numero, separar as duas primeiras dezenas (dois primeiros digitos) e as duas ultimas dezenas
(dois ultimos digitos).
- Calcular a raiz quadrada do numero e comparar com a soma das dezenas.
- Imprimir apenas os numeros que atenderem à condicao.

Exemplo de Saída:
9801
*/
