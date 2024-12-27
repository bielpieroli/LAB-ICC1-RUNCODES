#include <stdio.h>
#include <stdlib.h>

int
main (void) {
	unsigned int n;
	float res = 0;
	scanf("%ud", &n);
	for (int i=1; i<=n; i++) {
		if (i%2==0) 
			res= res - 1.0/i;
		else
			res= res + 1.0/i;
			
	} 
	printf("%.4f", res);
	return EXIT_SUCCESS;
}

/*
Implemente um programa em C que leia um número inteiro N, representando o número de termos da sequência e calcule a soma da sequência de frações conforme a fórmula:

1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...

A soma deve ser calculada até o N-ésimo termo da sequência. 

Caso N seja 2, por exemplo, a soma seria:
1 - 1/2

Imprima o resultado da soma com 4 casas decimais.

EXEMPLO: 

Entrada:
2
Saída:
0.5000

Entrada:
4
Saída:
0.5833
*/