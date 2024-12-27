#include <stdio.h>
#include <stdlib.h>
int main () {
	char str[26], *p;
	p=str;
	scanf("%[^\n]s", str);
	while (*p!='\0') {
		printf("%c\n", *p);
		p++;
	}
	return EXIT_SUCCESS;
}
/*
Implemente um programa que leia uma string com no máximo 26 caracteres e imprima cada caractere
da string em uma nova linha. O programa deve utilizar ponteiros e NÃO deve usar indexação de vetores.

Instruções:
- Use ponteiros para percorrer a string, evitando o uso de indexação de vetores (ex: string[i]).
- Para cada caractere da string, imprima-o seguido de uma quebra de linha.

Exemplo de Entrada:
ponteiro.

Exemplo de Saída:
p
o
n
t
e
i
r
o
.
*/
