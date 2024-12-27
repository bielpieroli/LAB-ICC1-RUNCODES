#include <stdio.h>
#include <stdlib.h>
void imprimir (int i, int m, int matriz1[i][i], int matriz2[m][m]) {
        printf("Matrizes:\n");
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<i; b++)
        {
            printf("%d ", matriz1[a][b]);
        }
        printf("\n");
    }
    for (int c=0; c<m; c++)
    {
        for (int d=0; d<m; d++)
        {
            printf("%d ", matriz2[c][d]);
        }
        printf("\n");
    }
}
int diagonal (int i, int matriz1[i][i]) {
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<i; b++)
        {
            if(a!=b && matriz1[a][b]!=0)
                return 1;
        }
    }
    return 0;
}
void multiplicacao (int i, int matriz1[i][i], int matriz2[i][i]) {
    int multiplicada[i][i];
    for (int y=0; y<i; y++)
    {
        for (int z=0; z<i; z++)
        {
            multiplicada[y][z]=0;
        }
    }
   
        for (int b=0; b<i; b++)
        {
            for (int c=0; c<i; c++)
            {
                for (int d=0; d<i; d++) 
                {
                multiplicada[b][c]+= matriz1[b][d]*matriz2[d][c];
                }
            }
        }
    
    printf("Matriz multiplicada:\n");
    for (int y=0; y<i; y++)
    {
        for (int z=0; z<i; z++)
        {
            printf("%d ", multiplicada[y][z]);
        }
        printf("\n");
    }
}
int
main () {
    int i, m, verdade;
    scanf("%d %d", &i, &m);
    int matriz1[i][i];
    int matriz2[m][m];
    //LEITURA
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<i; b++)
        {
            scanf("%d", &matriz1[a][b]);
        }
    }
    for (int c=0; c<m; c++)
    {
        for (int d=0; d<m; d++)
        {
            scanf("%d", &matriz2[c][d]);
        }
    }
    // IMPRIMIR MATRIZES
    imprimir(i,m,matriz1,matriz2);
    // DIAGONAL
    verdade=diagonal(i,matriz1);
    if (verdade==1)
        printf("A matriz 1 nao eh diagonal\n");
    else
        printf("A matriz 1 eh diagonal\n");
    verdade=diagonal(m,matriz2);
    if (verdade==1)
        printf("A matriz 2 nao eh diagonal\n");
    else
        printf("A matriz 2 eh diagonal\n");
    if (i==m)
        multiplicacao(i,matriz1,matriz2);
    else
        printf("Matrizes de tamanho incompativel");
}

/*
O programa realiza as seguintes tarefas:
1. Lê dois inteiros, N e M, representando as dimensões das duas matrizes quadradas.
2. Lê os elementos das duas matrizes.
3. Imprime as matrizes lidas.
4. Verifica se cada matriz é diagonal:
   - Uma matriz é diagonal se todos os elementos fora da diagonal principal forem zero.
5. Se possível, realiza a multiplicação das matrizes e imprime o resultado:
   - A multiplicação só é possível se ambas as matrizes forem quadradas e de mesmo tamanho (N = M).

Entrada:
1. Dois inteiros, N e M, representando o tamanho das matrizes.
2. Elementos da primeira matriz, organizados em N linhas e N colunas.
3. Elementos da segunda matriz, organizados em M linhas e M colunas.

Saída:
1. As duas matrizes na forma original.
2. Declaração se cada matriz é ou não diagonal.
3. Se as matrizes forem compatíveis, imprime a matriz resultante da multiplicação.
4. Caso contrário, imprime "Matrizes de tamanho incompativel".

Exemplo de Entrada 1:
4 6
42 77 15 89 30 63 8 57 21 48 90
2 69 35 82 11
46 12 78 33 91 7 55 24 62 3 88
19 40 70 14 68 96 25 52 80 9
60 38 83 1 74 28 49 64 5 95
17 72 36 86 8

Exemplo de Saída 1:
Matrizes :
42 77 15 89
30 63 8 57
21 48 90 2
69 35 82 11
46 12 78 33 91 7
55 24 62 3 88 19
40 70 14 68 96 25
52 80 9 60 38 83
1 74 28 49 64 5
95 17 72 36 86 8
A matriz 1 nao eh diagonal
A matriz 2 nao eh diagonal
Matrizes de tamanho
incompativel

Exemplo de Entrada 2:
3 3
9 8 7
6 5 4
3 2 1
1 0 0
0 2 0
0 0 3

Exemplo de Saída 2:
Matrizes :
9 8 7
6 5 4
3 2 1
1 0 0
0 2 0
0 0 3
A matriz 1 nao eh diagonal
A matriz 2 eh diagonal
Matriz multiplicada :
9 16 21
6 10 12
3 4 3
*/
