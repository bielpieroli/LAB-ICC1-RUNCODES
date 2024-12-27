#include <stdio.h>
#include <stdlib.h>
void ordenar (int qntdvzs, int pntsordenados[qntdvzs]) {
    int temp;
    for (int a=0; a<qntdvzs; a++)
    {
        for (int b=0; b<qntdvzs; b++) 
        {
            if(pntsordenados[a]>pntsordenados[b])
            {
            temp=pntsordenados[a];
            pntsordenados[a]=pntsordenados[b];
            pntsordenados[b]=temp;
            }
        }
    }
}
int
main () {
    int qntdvzs, cont, n=0;
    scanf("%d", &qntdvzs);
    int pontos[qntdvzs];
    int pntsordenados[qntdvzs];
    for (int i=0; i<qntdvzs; i++)
    {
        scanf("%d", &pontos[i]);
        pntsordenados[i]=pontos[i];
    }
    ordenar(qntdvzs, pntsordenados);
    
    for (int j=0; j<qntdvzs; j++)
    {
        cont=qntdvzs;
        n=0;
        for(int a=0, c=0; c<qntdvzs; c++, a++)
        {
            if (a<qntdvzs-1 && pntsordenados[a]==pntsordenados[a+1])
            {
                n++;
                continue;
            }
            if(pontos[j]>=pntsordenados[c])
            {
            cont--;
            }
        }
        cont-=n-1;
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", j+1, pontos[j], cont);
    }
    return EXIT_SUCCESS;
}

/* 
   O programa organiza e exibe a colocacao dos atletas em um esporte.
   - Recebe o numero de atletas e suas respectivas pontuacoes.
   - Ordena os atletas por pontuacao e calcula suas colocacoes, considerando empates.

   Entrada:
   - Um inteiro n indicando o numero de atletas (1 <= n <= 100).
   - n linhas com a pontuacao de cada atleta.

   Exemplo de Entrada 1:
   4
   10
   20
   15
   25
   Saida 1:
   1º Atleta, 10 Pontos, 4º Colocado
   2º Atleta, 20 Pontos, 2º Colocado
   3º Atleta, 15 Pontos, 3º Colocado
   4º Atleta, 25 Pontos, 1º Colocado

   Exemplo de Entrada 2:
   5
   10
   20
   15
   25
   10
   Saida 2:
   1º Atleta, 10 Pontos, 4º Colocado
   2º Atleta, 20 Pontos, 2º Colocado
   3º Atleta, 15 Pontos, 3º Colocado
   4º Atleta, 25 Pontos, 1º Colocado
   5º Atleta, 10 Pontos, 4º Colocado
*/
