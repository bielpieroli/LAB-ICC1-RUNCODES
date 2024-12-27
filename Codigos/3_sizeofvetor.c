#include <stdio.h>

int main (void) {
    long long int n = -1;
    scanf("%lld", &n);
    if(n == -1){
        n = 0;
    }
    printf("char: %lld\n", n*sizeof(char));
    printf("int: %lld\n", n*sizeof(int));
    printf("double: %lld\n", n*sizeof(double));
    return 0;
}

/*  
Implemente um programa em C que leia na entrada padrao de texto um numero inteiro n. Suponha  
que existam 3 vetores de tamanho n, um formado por chars, outro por ints e outro por doubles.  
O programa deve imprimir na tela o espaco ocupado (em bytes) por cada um dos vetores, seguidos  
por uma quebra de linha.  

Instrucoes Complementares  
- Utilize a funcao sizeof neste exercicio.  
- ATENCAO! Os tamanhos dos vetores podem ser muito grandes. Por muito grande, entenda-se  
um valor na ordem de -2^63 ate 2^63 - 1  

Exemplos de Entrada e Saida  
Entrada  
0  

Saida  
char : 0  
int : 0  
double : 0  
*/
