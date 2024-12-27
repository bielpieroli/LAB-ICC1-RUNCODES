#include <stdio.h>
#include <stdlib.h>
void ordenar (int tam, float vetor[tam]) {
    float temp;
    int troca=1;
    while (troca){
        troca=0;
        for(int z=0; z<tam-1; z++)
        {
            
            if (vetor[z]<vetor[z+1])
            {
                temp=vetor[z+1];
                vetor[z+1]=vetor[z];
                vetor[z]=temp;
                troca=1;
            }
        }
    }
    
}
int
main () {
    int i, j;
    scanf("%d %d", &i, &j);
    float notas[i][j], mediavertical, mediahorizontal;
    float exordenado[j];
    // LEITURA
    for (int a=0; a<i; a++)
    {
        for(int b=0; b<j; b++)
        {
            scanf("%f", &notas[a][b]);
        }
    }
    // Média Aluno
    for (int a=0; a<i; a++)
    {
        mediahorizontal=0;
        for(int b=0; b<j; b++)
        {
            mediahorizontal+=notas[a][b];
        }
        mediahorizontal=mediahorizontal/j;
        if (mediahorizontal>=5)
            printf("Media do aluno %d = %.2f : Aprovado\n", a+1, mediahorizontal);
        else 
            printf("Media do aluno %d = %.2f : Reprovado\n", a+1, mediahorizontal);
    }
    // Média Exercício
    for (int a=0; a<j; a++)
    {
        mediavertical=0;
        for(int b=0; b<i; b++)
        {
            mediavertical+=notas[b][a];
        }
        mediavertical=mediavertical/i;
        exordenado[a]=mediavertical;
    }
    ordenar (j,exordenado);
    printf("\n");
    for (int k=0; k<j ;k++)
        printf("%.2f ", exordenado[k]);
    return EXIT_SUCCESS;
}

/*

O programa deve processar uma matriz que representa as notas dos alunos em diversos exercícios. A matriz contém N linhas (alunos) e M colunas (exercícios). O objetivo é calcular:
1. A média simples das notas de cada aluno e seu status ("Aprovado" ou "Reprovado").
2. A média das notas de cada exercício, ordenadas em ordem decrescente.

Entrada:
1. Dois números inteiros N e M:
   - N: Quantidade de alunos (1 ≤ N ≤ 100).
   - M: Quantidade de exercícios (1 ≤ M ≤ 25).
2. Uma matriz de N linhas e M colunas contendo as notas dos alunos em cada exercício.

Processamento:
1. Para cada aluno:
   - Calcular a média simples de suas notas.
   - Determinar o status:
     - "Aprovado" se a média for maior ou igual a 5.0.
     - "Reprovado" caso contrário.
2. Para cada exercício:
   - Calcular a média das notas obtidas pelos alunos.
3. Ordenar as médias dos exercícios em ordem decrescente.

Saída:
1. Para cada aluno, exibir sua média com precisão de duas casas decimais, seguida do status ("Aprovado" ou "Reprovado").
2. Após uma linha em branco, exibir as médias dos exercícios em ordem decrescente, cada uma com precisão de duas casas decimais, separadas por um espaço, seguida de uma quebra de linha.

Exemplo de Entrada:
5 7
10.0 8.5 7.0 9.0 10.0 6.5 10.0
10.0 10.0 10.0 10.0 10.0 10.0 10.0
10.0 8.5 7.0 9.0 10.0 6.5 6.0
10.0 8.5 7.0 9.0 10.0 8.5 10.0
10.0 1.0 1.0 3.0 2.3 4.5 1.0

Exemplo de Saída:
Media do aluno 1 = 8.71 : Aprovado
Media do aluno 2 = 10.00 : Aprovado
Media do aluno 3 = 8.14 : Aprovado
Media do aluno 4 = 9.00 : Aprovado
Media do aluno 5 = 3.26 : Reprovado

10.00 8.46 8.00 7.40 7.30 7.20 6.40
*/