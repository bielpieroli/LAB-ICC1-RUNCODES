#include <stdio.h>

void hanoi(int n, char origem, char destino, char aux) {
    if (n == 1) {
        printf("Move disco 1 da pilha %c para a pilha %c\n", origem, aux);
        return;
    }
    hanoi(n - 1, origem, aux, destino);
    printf("Move disco %d da pilha %c para a pilha %c\n", n, origem, aux);
    hanoi(n - 1, destino, origem, aux);
}

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}



/*
Torre de Hanoi !!! O 'jogo' torre de Hanoi consiste de 3 varetas (A, B e C),
sendo que existem N discos perfurados em ordem de tamanho (o maior sempre 
sobre o menor) na vareta A. Seu objetivo é transferir todos os discos de A
para B, usando a vareta C como destinoiliar... O disco do topo é o disco 1, o
segundo disco, 2.. e assim sucessivamente... Escreva um programa recursivo
que faz isso.. Observe a saída do programa formatar a sua saída !!!
Exemplo:
 - ENTRADA:
3
 - SAIDA
Move disco 1 da pilha A para a pilha B
Move disco 2 da pilha A para a pilha C
Move disco 1 da pilha B para a pilha C
Move disco 3 da pilha A para a pilha B
Move disco 1 da pilha C para a pilha A
Move disco 2 da pilha C para a pilha B
Move disco 1 da pilha A para a pilha B
*/