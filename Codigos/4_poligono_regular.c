#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    double l, ap, area;
    double npi =  3.14159265358979323846;
    scanf("%d %lf", &n, &l);
    ap = (l)/(2*(tan(npi/n)));
    area = (l*n*ap)/2;
    printf("%lf\n", area);
    return EXIT_SUCCESS;
}

/*
Implemente um programa em C que leia um inteiro n e um double l. O programa deve calcular a área de um
polígono regular com n lados de tamanho l, utilizando a fórmula para a área do polígono regular. A fórmula é:

Área = (n * l^2) / (4 * tan(π / n))

O valor de π deve ser definido como 3.14159265358979323846.

Exemplo de Entrada e Saída:
Entrada
4 0.5

Saída
0.250000
*/