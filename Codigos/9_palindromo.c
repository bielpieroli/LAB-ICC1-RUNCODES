#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehpalindromo (int esquerda, int direita, char *p, char *q) {
    for( ; esquerda<direita; esquerda++, direita--, p++, q--) {
            if((*p)!=(*q)) 
            {
                return 0;
            }
        }
    return 1;
}
int
main () {
    int num, direita, esquerda=1;
    char *p, *q;
    scanf("%d", &num);
    for(int i=0;i<num;i++)
    {  
        char str[1000]={};
        scanf("%s", str);
        p=str;
        q=str;
        esquerda=1;
        direita=strlen(str);
        q=q+direita-1;
        if(ehpalindromo(esquerda, direita, p, q))
            printf("%s eh um palindromo\n", str);
        else
            printf("%s nao eh um palindromo\n", str);
    }
    
}
/* 
   O programa recebe um número inteiro n, seguido de n palavras, e verifica se cada palavra é um palíndromo.
   - Para isso, será implementada uma função que checa se a palavra é igual ao seu inverso.
   - Para cada palavra, imprime se ela é ou não um palíndromo.

   Entrada:
   - Um número inteiro n (quantidade de palavras).
   - Seguido de n palavras.

   Exemplo de Entrada:
   4
   ana
   roberto
   carlos
   ovo

   Saída:
   "ana eh um palindromo"
   "roberto nao eh um palindromo"
   "carlos nao eh um palindromo"
   "ovo eh um palindromo"
*/
