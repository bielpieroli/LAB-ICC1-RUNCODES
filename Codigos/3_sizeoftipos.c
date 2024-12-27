#include <stdio.h>

int main(void) {
    printf("Tam char: %lu\n", sizeof(char));
    printf("Tam int: %lu\n", sizeof(int));
    printf("Tam float: %lu\n", sizeof(float));
    printf("Tam double: %lu\n", sizeof(double));
    printf("Tam unsigned char: %lu\n", sizeof(unsigned char));
    printf("Tam signed char: %lu\n", sizeof(signed char));
    printf("Tam unsigned int: %lu\n", sizeof(unsigned int));
    printf("Tam signed int: %lu\n", sizeof(signed int));
    printf("Tam short int: %lu\n", sizeof(short int));
    printf("Tam long int: %lu\n", sizeof(long int));
    printf("Tam long long int: %lu\n", sizeof(long long int));

    return 0;
}

/*
Desenvolva um programa que imprima o tamanho ocupado, em bytes, por cada um dos tipos de dados abaixo:  
1. Char  
2. Int  
3. Float  
4. Double  
5. Unsigned Char  
6. Signed Char  
7. Unsigned Int  
8. Signed Int  
9. Short Int  
10. Long Int  
11. Long long Int  

Exemplos de Entrada e Saida  
Entrada  
Nenhuma entrada, apenas exibicao de tamanhos.  

Saida  
Tam char : n  
Tam int : n  
Tam float : n  
Tam double : n  
Tam unsigned char : n  
Tam signed char : n  
Tam unsigned int : n  
Tam signed int : n  
Tam short int : n  
Tam long int : n  
Tam long long int : n  

Instrucoes Complementares  
- n e o tamanho em bytes do tipo fundamental em C (compilador 64 bits). Se o compilador for de 32 bits, o resultado pode ser diferente!
*/