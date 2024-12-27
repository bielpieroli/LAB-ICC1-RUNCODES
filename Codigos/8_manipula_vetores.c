#include <stdio.h>
#include <stdlib.h>
#define UM 1;
int
main () {
    int velho[2000]={};
    int pos = -1;
    int num, temp, gerafib[18] = {};
    char comando = 100;
    do{
        if (pos>=0) 
        {
            velho[pos]=num;
        }
        scanf("%d\n", &num);
        pos++;
    } while(num!=1);
    int vetor[pos+1];
    for (int u=0; u<pos; u++)
    {
        vetor[u]=velho[u];
    }
    scanf("%c", &comando);
    if (comando==97)
    {
        for (int i = 0; i < pos; i++) {
            for (int j = 0; j < pos; j++) {
                if (vetor[j] > vetor[i]) 
                {
                    temp = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = temp;
                }
            }
        }
        printf("vetor ordenado:");
        for (int a=0; a<pos; a++)
        {
            printf("%d ", vetor[a]);
        }
    } else if (comando==98)
    {
        gerafib[0]=0;
        gerafib[1]=1;
        printf("Numeros de Fibonacci:");
        for (int c=2; c<18 && gerafib[c]<2000; c++)
        {
            gerafib[c]=gerafib[c-1]+gerafib[c-2];
        }
        for (int d=0; d<pos; d++)
        {
            for (int e=0; e<18; e++)
            if (vetor[d]==gerafib[e])
            {
                printf("%d ", vetor[d]);
            }
        }
    } else if (comando==99)
    {
        printf("Vetor maiusculo:");
        for (int b=0; b<pos; b++)
        {
            vetor[b]-=32;
            printf("%c ", (char)vetor[b]);
        }
    } else
        printf("Comando inexistente");
}

/* 
   Implemente um programa que recebe um vetor de inteiros e o número "1". O programa deve então receber um comando:
   - 'a': ordenar e imprimir o vetor
   - 'b': imprimir números de Fibonacci no vetor (até 2000)
   - 'c': imprimir os números do vetor como caracteres e como maiúsculos
   - Qualquer outro comando deve imprimir "comando inexistente".

   Exemplos:
   Entrada: 34 76 888 120 333 100 23 12 78 90 92 87 90 1
   Comando: a
   Saída: vetor ordenado: 12 23 34 76 78 87 90 90 92 100 120 333 888

   Entrada: 40 348 988 2 5 98 67 8 29 499 1597 34 144 377 233 96 1000
   Comando: b
   Saída: Numeros de Fibonacci: 2 5 8 1597 34 144 377 233 377

   Entrada: 34 76 88 120 122 444 680 72 12 10 1
   Comando: d
   Saída: Comando inexistente

   Entrada: 98 97 116 105 115 116 97 1
   Comando: c
   Saída: Vetor maiusculo: B A T I S T A
*/
