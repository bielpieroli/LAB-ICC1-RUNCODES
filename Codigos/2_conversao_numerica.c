#include <stdio.h>

int main(void) {
    char caracter;
    int num;
    
    scanf(" %c", &caracter);
    scanf(" %d", &num);

    printf("numero correspondente: %d\n", (int)caracter);
    printf("caracter correspondente: %c\n", (char)num);
    printf("octal: %o\n", num);
    printf("hexadecimal: %x\n", num);

    return 0;
}
/*  
Implemente um programa em C que leia na entrada padrao de texto um caractere e um numero inteiro.  
Imprima na tela: o codigo ASCII do caractere, o caractere correspondente ao inteiro, o inteiro  
em base octal e o inteiro em base hexadecimal, todos seguidos por uma quebra de linha.  


Entrada  
a 102  

Saida  
numero correspondente : 97  
caracter correspondente : f  
octal : 146  
hexadecimal : 66  
*/  
