#include <stdio.h>
int main (void)
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	if  (((n1 > n2) && (((n1 - n2)%3) == 0)) || ((n2 > n1) && ((n1 + n2) > 400)) || ((n1 == n2) && (n1%2 == 1)))
		printf ("%d\n", n1 + n2);
	else
		printf ("Nenhuma condicao foi satisfeita\n");
	return (0);
}

	
/*  
Implemente um programa em C que leia dois numeros inteiros e realize os seguintes testes:  
1) Se n1 e maior que n2 E n1 menos n2 e divisivel por 3.  
2) Se n2 e maior que n1 E n1 + n2 e maior que 400.  
3) Se n1 e igual a n2 E n1 e impar.  
Se qualquer um desses testes for verdadeiro, imprima n1 + n2, caso contrario, imprima "Nenhuma condicao foi satisfeita".  

Exemplos de Entrada e Saida  
Entrada  
39 39  

Saida  
78  

Entrada  
120 130  

Saida  
Nenhuma condicao foi satisfeita  
*/
	