#include <stdio.h>
int main (void)
{
	int valor, n200, n100, n50, n20, n10, n5, n2, r200, r100, r50, r20, r10, r5, r2;
	scanf("%d", &valor);
	n200 = valor/200;
	r200 = valor%200;
	n100 = r200/100;
	r100 = r200%100;
	n50 = r100/50;
	r50 = r100%50;
	n20 = r50/20;
	r20 = r50%20;
	n10 = r20/10;
	r10 = r20%10;
	n5 = r10/5;
	r5 = r10%5;
	n2 = r5/2;
	r2 = r5%2;
	
	printf("%d nota(s) de R$ 200\n", n200);
	printf("%d nota(s) de R$ 100\n", n100);
	printf("%d nota(s) de R$ 50\n", n50);
	printf("%d nota(s) de R$ 20\n", n20);
	printf("%d nota(s) de R$ 10\n", n10);
	printf("%d nota(s) de R$ 5\n", n5);
	printf("%d nota(s) de R$ 2\n", n2);
	printf("%d moeda(s) de R$ 1\n", r2);
	return (0);
}
/*
Implemente um programa em C que leia um valor inteiro em reais e calcule a quantidade minima de notas e moedas
necessarias para representar esse valor. O programa deve considerar as notas de R$ 200, R$ 100, R$ 50, R$ 20, R$ 10, 
R$ 5, R$ 2 e as moedas de R$ 1, R$ 0.50, R$ 0.25, R$ 0.10, R$ 0.05 e R$ 0.01. A saí­da deve mostrar a quantidade 
de cada tipo de nota ou moeda e indicar "nota(s)" ou "moeda(s)".  

Exemplos de Entrada e Saída:
Entrada  
143  

Saída  
0 nota(s) de R$ 200  
1 nota(s) de R$ 100  
0 nota(s) de R$ 50  
2 nota(s) de R$ 20  
0 nota(s) de R$ 10  
0 nota(s) de R$ 5  
1 nota(s) de R$ 2  
1 moeda(s) de R$ 1  
*/