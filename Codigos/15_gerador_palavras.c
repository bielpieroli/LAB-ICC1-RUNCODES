#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gerador_palavras(char *palavra, int pos, int M) {
    if (pos == M) {
        palavra[pos] = '\0';  
        printf("%s\n", palavra);
        return;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        palavra[pos] = c;  
        gerador_palavras(palavra, pos + 1, M);  
    }
}

int main() {
    int M;

    scanf("%d", &M);

    char *palavra = (char *)malloc((M + 1) * sizeof(char));
    if (!palavra) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    gerador_palavras(palavra, 0, M);

    free(palavra);

    return 0;
}
/*
Faça um programa que gere TODAS as palavras (de 'a' --- 'z' - minúsculas) de M caracteres.
A entrada é o valor de M. A saída, todas as palavras.. 1 por linha !!!!
EXEMPLO:
 - ENTRADA:
3
 - SAIDA (imagine sendo minuscula)
AAA
AAB
AAC
...
ADA
ADB
ADC
...
FAA
FAB
FAC
...
GBZ
GCA
GCB
...
HZY
HZZ
IAA
...
ZZV
ZZW
ZZX
ZZY
ZZZ
*/