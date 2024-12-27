#include <stdio.h>
#include <stdlib.h>

int *alocaele(int qntd);
void leituradovetor(int qntd, int *vetor);
int *iguais(int qntdA, int qntdB, int *vA, int *vB, int *qntdI);
int *uniao (int qntdA, int qntdB, int qntdI, int *vA, int *vB, int *vI);
int *operacao (int qntdA, int qntdB, int qntdI, int *uniao, int *vI);

int *alocaele(int qntd){
    int *vetor;
    vetor= (int *) malloc (qntd*sizeof(int));
    leituradovetor(qntd, vetor);
    return (vetor);
}
void leituradovetor(int qntd, int *vetor) {
    for(int i=0; i<qntd; i++) 
    {
        scanf("%d", &vetor[i]);
    }
}
int *iguais(int qntdA, int qntdB, int *vA, int *vB, int *qntdI) {
    for(int a=0; a<qntdA; a++) { 
        for(int b=0; b<qntdB; b++) {
            if(vA[a]==vB[b])
                (*qntdI)++;
        }
    }
    int *viguais, posi=0;
    viguais= (int *) malloc ((*qntdI)*sizeof(int));
    for(int a=0; a<qntdA; a++) { 
        for(int b=0; b<qntdB; b++) {
            if(vA[a]==vB[b])
            {
                viguais[posi]=vA[a];
                posi++;
            }
        }
    }
    return (viguais);
}

int *uniao (int qntdA, int qntdB, int qntdI, int *vA, int *vB, int *vI) {
    int *aub;
    aub = malloc((qntdA+qntdB-qntdI)*sizeof(int));
    int posaub=0;
    for(int a=0; a<qntdA; a++)
    {
        int saoiguais=0;
        for (int i=0; i<qntdI; i++)
        {
            if(vA[a]==vI[i])
            {
                saoiguais=1;
                break;
            }
        }
        if (saoiguais==1)
        {
            continue;
        }
        else
        {
            aub[posaub]=vA[a];
            posaub++;
        }
    }
    for(int b=0; b<qntdB; b++)
    {
        aub[posaub]=vB[b];
        posaub++;
    }
    return (aub);
}
int *operacao (int qntdA, int qntdB, int qntdI, int *uniao, int *vI) {
    int *operacao;
    operacao = malloc((qntdA+qntdB-2*qntdI)*sizeof(int));
    int posop=0;
    for (int u=0; u<qntdA+qntdB-qntdI; u++) 
    {
        int saoiguais=0;
        for (int i=0; i<qntdI; i++)
        {
            if(vI[i]==uniao[u])
            {
                saoiguais=1;
                break;
            }
        }
        if(saoiguais==0)
        {
            operacao[posop]=uniao[u];
            posop++;
        }
    }
    return (operacao);
}
void ordenar (int n, int *vetor) {
    int temp;
    for (int a=0; a<n; a++)
    {
        for (int b=0; b<n; b++) 
        {
            if(vetor[a]<vetor[b])
            {
            temp=vetor[a];
            vetor[a]=vetor[b];
            vetor[b]=temp;
            }
        }
    }
}
void saida(int n, int *vet) {
    ordenar(n, vet);
    for (int z=0; z<n; z++)
    {
        printf("%d ", vet[z]);
    }
}

int main() {
    int qntdA, *vA, qntdB, *vB, qntdI=0, *vI, *a_uniao_b, *operacao_u_menos_i;
    scanf("%d", &qntdA);
    vA= alocaele(qntdA);
    scanf("%d", &qntdB);
    vB= alocaele(qntdB);
    vI= iguais(qntdA, qntdB, vA, vB, &qntdI);
    a_uniao_b = uniao (qntdA, qntdB, qntdI, vA, vB, vI);
    operacao_u_menos_i = operacao (qntdA, qntdB, qntdI, a_uniao_b, vI);
    if(qntdA!=0)
    {
        printf("conjunto A: ");
        saida(qntdA, vA);
    }
    else
    {
        printf("conjunto A: vazio");
    }
    if(qntdB!=0)
    {
        printf("\nconjunto B: ");
        saida(qntdB, vB);
    }
    else
    {
        printf("\nconjunto B: vazio");
    }
    if(qntdA+qntdB-qntdI!=0)
    {
        printf("\nA uniao B: ");
        saida(qntdA+qntdB-qntdI, a_uniao_b);
    }
    else
    {
        printf("\nA uniao B: vazio");
    }
    if(qntdA+qntdB-2*qntdI!=0)
    {
        printf("\n(A uniao B) - (A interseccao B): ");
        saida(qntdA+qntdB-2*qntdI, operacao_u_menos_i);
    }
    else
    {
        printf("\n(A uniao B) - (A interseccao B): vazio");
    }
    free(vA);
    free(vB);
    free(vI);
    free(a_uniao_b);
    free(operacao_u_menos_i);
    
    return EXIT_SUCCESS;
}

/* 
Leia dois vetores de inteiros (positivos e negativos), interpretando-os como conjuntos A e B. 
Crie uma funcao para retornar o conjunto A uniao B. 
Crie uma funcao para retornar o conjunto (A uniao B) - (A interseccao B). 
Os vetores retornados devem usar apenas o espaco necessario. 
Imprima os conjuntos A e B, assim como os resultados das operacoes, com elementos ordenados. 
Caso algum conjunto seja vazio, imprima "vazio". 

Exemplo de entrada e saida: 
Entrada: 
4 
1 2 3 4 
6 
3 4 5 6 7 8 

Saida: 
conjunto A : 1 2 3 4 
conjunto B : 3 4 5 6 7 8 
A uniao B : 1 2 3 4 5 6 7 8 
( A uniao B ) - ( A interseccao B ) : 1 2 5 6 7 8 
*/
