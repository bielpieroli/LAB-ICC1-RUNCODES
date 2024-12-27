#include <stdio.h>
#include <stdlib.h>

int main()
{
	float media, nlistas, p1, p2, l1, l2, l3, l4;
	scanf("%f%f%f%f%f%f", &p1, &p2, &l1, &l2, &l3, &l4);
	nlistas = l1+l2+l3+l4;
	media = (p1 + p2 + (nlistas)/4)/3;
	if (nlistas==0)
		printf("Reprovado\n");
	else {
		if (media>=5)
			printf("Aprovado\n");
		else if (media<3)
			printf("Reprovado\n");
		else
			printf("Recuperacao\n");
	}	
    return (0);
}

/*
Implemente um programa em C que recebe as notas de P1, P2 e das 4 listas de exercício. A nota final será
calculada como nfinal = (P1 + P2 + nlistas) / 3, onde nlistas é a média das notas das listas. Dependendo da 
nota final, o aluno estará aprovado, em recuperação ou reprovado, com as seguintes condições:

- Se nfinal >= 5, o aluno foi aprovado.
- Se 3 <= nfinal < 5, o aluno está em recuperação.
- Se nfinal < 3, o aluno foi reprovado.
- Se a nota das listas for zero, o aluno é automaticamente reprovado.

Exemplo de Entrada e Saída:
Entrada
7.3 2.7 10 0 2 8

Saída
Aprovado

Entrada
2.2 3.7 4 2 0 1.25

Saída
Reprovado

Entrada
2 4 2.2 1.8 1 7

Saída
Recuperacao
*/
