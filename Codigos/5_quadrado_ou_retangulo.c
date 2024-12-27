#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (a!=0 && b!=0 && c!=0 && d!=0) {
		if (a!=c || b!=d)
			printf ("nenhum!\n");
		else	
			if (a == c && b == d && a!= b)
				printf ("retangulo!\n");
			else
				printf ("quadrado!\n");
}
	else 
		printf ("nenhum!");
	return (0);
}

/*
Implemente um programa em C que recebe quatro inteiros a, b, c, d representando os lados consecutivos de um quadrilátero. 
Assuma que todos os ângulos são retos. O programa deve determinar se o quadrilátero é um quadrado ou um retângulo:

- Se todos os lados forem iguais, imprime "quadrado!".
- Se dois lados opostos forem iguais, imprime "retangulo!".
- Caso contrário, imprime "nenhum !".

Exemplo de Entrada e Saída:
Entrada:
1 1 1 1
Saída:
quadrado!

Entrada:
2 4 2 4
Saída:
retangulo!

Entrada:
0 0 0 0
Saída:
nenhum!
*/
