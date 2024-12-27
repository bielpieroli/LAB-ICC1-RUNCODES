#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void entrada(int num, int numeros[]) {
    for (int i = 0; i < num - 1; i++) {
        scanf("%d", &numeros[i]);
    }
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left) quick_sort(a, left, j);
    if (i < right) quick_sort(a, i, right);
}

void verificacao(int num, int *numeros) {
    quick_sort(numeros, 0, num - 2);

    for (int verificador = 0; verificador < num - 1; verificador++) {
        if (numeros[verificador] != verificador + 1) {
            printf("Numero desaparecido: %d\n", verificador + 1);
            return;
        }
    }
    printf("Numero desaparecido: %d\n", num);
}

void calcula_com_PA (int num, int numeros[num-1]) {
	int soma = 0;
	for (int i=0; i<num-1; i++)
	{
		scanf("%d", &numeros[i]);
		soma += numeros[i];
	}		
	int resposta = ((1 + (num))*num)/2;
	printf("Numero desaparecido: %d\n", resposta-soma);
}

int main () {
	// OBS.: Ha uma maneira MUITO, MUITO mais eficiente utilizando a SOMA FINITA da Progressao Aritmetica (PA), veja abaixo:
	int num;
	scanf("%d", &num);
	int numeros[num-1];
	entrada (num, numeros);
	// verificacao (num, numeros);
	calcula_com_PA(num, numeros);
	return EXIT_SUCCESS;
}


/* 
   O programa identifica o número ausente em uma sequência de 1 a N.
   - Recebe um número N e, em seguida, N-1 números distintos.
   - Implementa funções para calcular o número faltante.

   Entrada:
   - Um número inteiro N.
   - Uma sequência de N-1 números entre 1 e N.

   Exemplo de Entrada 1:
   10
   7 4 10 3 2 6 8 1 5
   Saída 1:
   Numero desaparecido : 9

   Exemplo de Entrada 2:
   10
   10 9 8 7 6 5 3 2 1
   Saída 2:
   Numero desaparecido : 4

   Exemplo de Entrada 3:
   10
   1 2 3 4 5 6 7 9 10
   Saída 3:
   Numero desaparecido : 8
*/
