#include <stdio.h>
#include <stdlib.h>
int main () {
	int tempo, n=0;
	double velA, velB; 
	scanf("%d", &n);
	while (n>0) {
		scanf("%lf %lf %d", &velA, &velB, &tempo);
		if(tempo==0) {
			printf("A corrida ainda nao comecou\n");
		} else if (velA==0 && velB==0) {
			printf("Os dois pilotos nao querem competir\n");
		} else if (velA==0) {
			printf("O piloto A desistiu inesperadamente\n");
		} else if (velB==0) {
			printf("O piloto B desistiu inesperadamente\n");
		} else if (tempo<0) {
			printf("De alguma forma os pilotos voltaram no tempo\n");
		} else if (velA==velB) {
			printf("Os karts empataram, percorrendo cada %.2fkm\n", velA*tempo);
		} else if (velA>velB) {
			printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", ((velA-velB)*tempo));
		} else if (velA<velB) {
			printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", ((velB-velA)*tempo));
		}
	n--;
    }
	return EXIT_SUCCESS;
}


/*
Implemente um programa que receba como entrada o numero de corridas N, as velocidades dos karts A e B, e o tempo T de cada corrida. 
Para cada corrida, calcule a distancia percorrida por cada kart, comparando os resultados e imprimindo o vencedor e a distancia a
mais que o perdedor percorreu.

- Se ambos os karts tiverem velocidade zero, a corrida ainda nao comecou.
- Se ambos os pilotos nao quiserem competir (velocidade negativa), o programa deve tratar como "Os dois pilotos nao querem competir".
- Se um piloto tiver velocidade negativa, isso significa que ele desistiu.
- Se os dois pilotos percorrerem a mesma distancia, houve empate.

Exemplo de Entrada e Saída:
Entrada:
11
0 0 0
0 0 1
0 1 0
1 0 0
1 0 1
1 1 0
1 1 1
1 1 -1
0 0 -1
1 0 -1
0 1 -1

Saída:
A corrida ainda nao comecou
Os dois pilotos nao querem competir
A corrida ainda nao comecou
A corrida ainda nao comecou
O piloto B desistiu inesperadamente
A corrida ainda nao comecou
Os karts empataram, percorrendo cada 1.00 km
De alguma forma os pilotos voltaram no tempo
Os dois pilotos nao querem competir
O piloto B desistiu inesperadamente
O piloto A desistiu inesperadamente
*/
