#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void aloca (int ***m, int num) {
    *m = (int **) malloc(num*sizeof(int *));
    if(m==NULL)
        exit (1);
}
void matriz(int **m, int num) {
    for(int i=0; i<num; i++)
    {
        m[i]=(int *) malloc(num*sizeof(int));
        if(m[i]==NULL)
            exit (2);
    }
}
void leitura(int **m, int num) {
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}
void imprimir(int **m, int num) {
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
int main () {
    int num, **m;
    scanf("%d ", &num);
    num=sqrt(num);

    aloca(&m, num);
    matriz(m, num);
    leitura(m, num);
    imprimir(m, num);

    /*
    m = (int **) malloc(num*sizeof(int *));
    for(int i = 0; i<num; i++){
        m[i] = (int*)malloc(num*sizeof(int));
    }
    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            scanf("%d", &m[i][j]);
        }
    }
    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    */
    for(int z=0; z<num; z++) 
    {
        free(m[z]);
    }
    free(m);
    return EXIT_SUCCESS;

}

/* 
Implemente um programa em C para alocar e manipular uma matriz dinamicamente. 
O programa deve: 
- Receber um inteiro N representando a quantidade de elementos da matriz. 
- Alocar dinamicamente memoria para armazenar os N elementos. 
- Conter funcoes para preencher a matriz e imprimi-la na tela. 
- Garantir a desalocacao de memoria ao final do programa. 
- Utilizar as funcoes malloc, calloc e free da biblioteca stdlib.h. 
- Imprimir a matriz com os elementos formatados corretamente e com quebra de linha ao final de cada linha. 

Exemplo de entrada e saida: 
Entrada: 
16 
5243 8149 2923 1877 6892 1468 
3554 8029 673 4281 1142 7086 
2629 5484 7501 2930 

Saida: 
5243 8149 2923 1877 
6892 1468 3554 8029 
673 4281 1142 7086 
2629 5484 7501 2930 

Entrada: 
25 
7826 4631 5225 3417 2042 8935 
1910 5807 315 770 6903 8507 
4932 6172 7419 8922 2891 
4814 162 6687 751 5621 7343 
156 8610 

Saida: 
7826 4631 5225 3417 2042 
8935 1910 5807 315 770 
6903 8507 4932 6172 7419 
8922 2891 4814 162 6687 
751 5621 7343 156 8610 
*/
