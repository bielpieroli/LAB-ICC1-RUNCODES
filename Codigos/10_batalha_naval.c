#include <stdio.h>
#include <stdlib.h>
void lermatriz(int n, char m[n][n]);
void posicoes(int n, char m[n][n]);
void acerto (int n, int linha, int coluna, char m[n][n]);
void imprimematriz(int n, char m[n][n]);
void lermatriz(int n, char m[n][n]) {
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf(" %c", &m[i][j]);
        }
    }
}
void posicoes(int n, char m[n][n]) {
    int qntd, coluna;
    char linha;
    scanf(" %d",&qntd);
    for (int a=0; a<qntd; a++)
    {
        scanf(" %c%d", &linha, &coluna);
        linha=(int)linha-65;
        acerto(n, linha, coluna, m);
    }
}
void acerto (int n, int linha, int coluna, char m[n][n]) {
    if (m[linha][coluna-1]=='N')
    {
        m[linha][coluna-1]='X';
        printf("acerto!\n");
    } else {
        printf("erro!\n");
    }
    return;
} 
void imprimematriz(int n, char m[n][n]) {
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}
int
main () {
    int n;
    scanf("%d", &n);
    char m[n][n];
    lermatriz(n,m);
    posicoes(n,m);
    imprimematriz(n,m);
    return EXIT_SUCCESS;
}

/*
Problema: Batalha Naval

Descrição:
O programa deve simular ataques em um tabuleiro de batalha naval representado por uma matriz quadrada de tamanho N x N. A matriz contém os seguintes símbolos:
- 'O': Representa espaços vazios no tabuleiro.
- 'N': Representa navios no tabuleiro.

Entrada:
1. Um número inteiro N, representando o tamanho do tabuleiro.
2. Uma matriz N x N contendo os caracteres 'O' e 'N'.
3. Um número inteiro I, indicando o número de ataques a serem realizados.
4. I coordenadas de ataque, cada uma composta por:
   - Uma letra maiúscula (A, B, ..., Z) representando a linha.
   - Um número inteiro (1, 2, ..., N) representando a coluna.

Processamento:
1. Para cada coordenada de ataque:
   - Verificar se o ataque atinge um navio ('N') ou um espaço vazio ('O').
   - Se atingir um navio:
     - Substituir 'N' por 'X' na matriz.
     - Imprimir "acerto!".
   - Se atingir um espaço vazio:
     - Imprimir "erro!".
2. Após processar todos os ataques, exibir o estado final da matriz.

Saída:
1. O resultado de cada ataque ("acerto!" ou "erro!").
2. A matriz final, refletindo as alterações feitas pelos ataques bem-sucedidos.

Exemplo de Entrada:
4
O O O N
O O O N
O O N N
O O O O
3
A2
B4
C4

Exemplo de Saída:
erro!
acerto!
acerto!
O O O N
O O O X
O O N X
O O O O
*/
