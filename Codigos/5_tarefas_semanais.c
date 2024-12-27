#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bool;
    char dia;
    scanf("%c%d", &dia, &bool);
    if (bool==0)
    switch(dia) {
        case '1': printf ("Segunda: Aula de computacao\n");
        case '2': printf ("Terca: Treino de volei\n");
        case '3': printf ("Quarta: Aula de calculo\n");
        case '4': printf ("Quinta: Lista de GA\n");
        case '5': printf ("Sexta: Festa da Sacim\n");
        case '6': printf ("Sabado: Jantar em familia\n");
        case '7': printf ("Domingo: Depressao pos final de semana\n"); break;
        default: printf ("Dia nao registrado\n");
        }
    else
        switch(dia) {
        case '1': printf ("Segunda: Aula de computacao\n"); break;
        case '2': printf ("Terca: Treino de volei\n"); break;
        case '3': printf ("Quarta: Aula de calculo\n"); break;
        case '4': printf ("Quinta: Lista de GA\n"); break;
        case '5': printf ("Sexta: Festa da Sacim\n"); break;
        case '6': printf ("Sabado: Jantar em familia\n"); break;
        case '7': printf ("Domingo: Depressao pos final de semana\n"); break;
        default: printf ("Dia nao registrado\n");
        }
    return EXIT_SUCCESS;
}

/*
Implemente um programa em C que recebe dois valores: 
- Um inteiro representando o dia da semana (1 - Segunda, 2 - Terça ... 7 - Domingo).
- Um valor booleano (0 ou 1) que indica se as atividades devem ser mostradas a partir do dia informado ou apenas para o dia.

O programa deve realizar as seguintes ações:
- Se o dia informado não for válido (fora do intervalo de 1 a 7), imprima "Dia nao informado".
- Se o valor booleano for 0, imprima as atividades a partir do dia informado até o final da semana (domingo).
- Se o valor booleano for 1, imprima apenas a atividade do dia informado.

Exemplo de Entrada e Saída:
Entrada:
1
0
Saída:
Segunda: Aula de computacao
Terca: Treino de volei
Quarta: Aula de calculo
Quinta: Lista de GA
Sexta: Festa da Sacim
Sabado: Jantar em familia
Domingo: Depressao pos final de semana

Entrada:
3
1
Saída:
Quarta: Aula de calculo
*/