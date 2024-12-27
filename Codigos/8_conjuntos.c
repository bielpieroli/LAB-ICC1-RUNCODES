#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vouf=0, unico=0, acum=0;
    /* LER VETOR A */
    int qntdA;
    scanf("%d", &qntdA);
    int conjA[qntdA];
    for (int n=0; n<qntdA; n++)
    {
        scanf("%d", &conjA[n]);
    }
    /* LER VETOR B */
    int qntdB;
    scanf("%d", &qntdB);
    int conjB[qntdB];
    for (int u=0; u<qntdB; u++)
    {
        scanf("%d", &conjB[u]);
    }
    printf("intersecao: ");
    /* INTERSECAO */
    for (int i=0; i<qntdA; i++)
    {
        for(int j=0; j<qntdB; j++)
        {
            if (conjA[i]==conjB[j])
            {
                vouf=1;
                printf("%d ", conjA[i]);
            }
        }
    }
    if (vouf==0)
    {
        printf("vazio");
    }
    printf("\na - b: ");
    /* DIFERENCA */
    for (int i=0; i<qntdA; i++)
    {
        unico=1;
        for(int j=0; j<qntdB; j++)
        {
            if (conjA[i]==conjB[j])
            {
                unico=0;
            }
        }
        if (unico==1)
        {
            printf("%d ", conjA[i]);
            acum=1;
        }
    }
    if (acum==0)
    {
        printf("vazio");
    }
    return EXIT_SUCCESS;
}

/* 
   Implemente um programa que leia 2 vetores (com tamanho maximo 10) e imprima:
   a interseccao a e b e a diferenca a - b.
   

   - Elementos impressos devem estar na ordem de a
   - Se o conjunto for vazio, imprima "vazio"
   
   3 Exemplos de Entrada e Saida
   Entrada:
   4
   1 2 3 4
   6
   3 4 5 6 7 8
   Saida:
   Interseccao: 3 4
   Diferenca: 1 2
*/
