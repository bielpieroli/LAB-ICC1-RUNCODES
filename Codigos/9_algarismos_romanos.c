#include <stdio.h>
#include <stdlib.h>
void inteiroParaRomano (int n) {
	int cont;
	cont=n/1000;
	n=n%1000;
	for(int i=0; i<cont; i++) {
		printf("M");
	}
	if (n==0)
	    return;
	cont=n/900;
	n=n%900;
	for(int j=0; j<cont; j++) {
		printf("CM");
	}
	if (n==0)
	    return;
	cont=n/500;
	n=n%500;
	for(int k=0; k<cont; k++) {
		printf("D");
	}
	if (n==0)
	    return;
	cont=n/400;
	n=n%400;
	for(int l=0; l<cont; l++) {
		printf("CD");
	}
	if (n==0)
	    return;
	cont=n/100;
	n=n%100;
	for(int m=0; m<cont; m++) {
		printf("C");
	}
	if (n==0)
	    return;
	cont=n/90;
	n=n%90;
	for(int n=0; n<cont; n++) {
		printf("XC");
	}
	if (n==0)
	    return;
	cont=n/50;
	n=n%50;
	for(int o=0; o<cont; o++) {
		printf("L");
	}
	if (n==0)
	    return;
	cont=n/40;
	n=n%40;
	for(int p=0; p<cont; p++) {
		printf("XL");
	}
	if (n==0)
	    return;
	cont=n/10;
	n=n%10;
	for(int q=0; q<cont; q++) {
		printf("X");
	}
	if (n==0)
	    return;
	cont=n/9;
	n=n%9;
	for(int r=0; r<cont; r++) {
		printf("IX");
	}
	if (n==0)
	    return;
	cont=n/5;
	n=n%5;
	for(int s=0; s<cont; s++) {
		printf("V");
	}
	if (n==0)
	    return;
	cont=n/4;
	n=n%4;
	for(int t=0; t<cont; t++) {
		printf("IV");
	}
	if (n==0)
	    return;
	for (int u=1; n/u; u++) {
	    printf("I");
	}
	if (n==0)
	    return;
}
int main () {
	int qntdvezes, num;
	scanf("%d", &qntdvezes);
	for(int i=0; i<qntdvezes; i++) 
	{
		scanf("%d", &num);
		inteiroParaRomano(num);
		printf("\n");
	}
}

/* 
   O programa converte números indo-arabicos para algarismos romanos.
   - Recebe a quantidade de números inteiros e os valores em indo-arabicos.
   - Implementa uma função `inteiroParaRomano` para realizar a conversão.
   - Os números fornecidos devem ser entre 1 e 3999.

   Entrada:
   - Um número inteiro n (tamanho do vetor).
   - n valores inteiros para serem convertidos.

   Exemplo de Entrada:
   2
   21
   8

   Saída:
   "XXI"
   "VIII"
*/
