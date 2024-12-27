#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *alocavetor (int tam, int size_of) {
    void *vet;
    vet = malloc (tam*size_of);
    if (vet==NULL)
        exit (1);
    return vet;
}
    
int main (void) {
    char *str1, *str2, *parametro, *pont;
    str1= (char *) alocavetor(131,sizeof(char));
    str2= (char *) alocavetor(131,sizeof(char));
    parametro= (char *) alocavetor(21,sizeof(char));
    scanf(" %[^\n]s", str1);
    scanf(" %[^\n]s", str2);
    scanf(" %[^\n]s", parametro);
    pont=strstr(str1, parametro);
    if (pont!=NULL) {
        (*pont)='\0';
    } else {
        str1[strlen(str1)-1] = '\0';
        str1[strlen(str1)] = ' ';
    }
    printf("%s", str1);
    pont=strstr(str2, parametro);
    if(pont!=NULL) {
        pont+=(strlen(parametro)+1);
        printf("%s", pont);
    }
    free(str1);
    free(str2);
    free(parametro);
    return EXIT_SUCCESS;
}

/* 
1 Descrição
Implemente um programa em C que leia duas strings (A e B), com até 130 caracteres cada, e uma palavra (com até 20 caracteres) que será usada como parâmetro para a junção. O programa deve imprimir uma nova string formada pelos caracteres de A até o parâmetro, seguidos pelos caracteres de B a partir do parâmetro. Espaços adicionais não devem ser impressos. 

Caso o parâmetro não seja encontrado em A, imprima a string A inteira. Se o parâmetro não for encontrado em B, não deve ser impresso nada de B.

2 Instruções Complementares
• Utilize a biblioteca string.h

3 Exemplos de Entrada e Saída
Entrada
Alo meu Brasil !
meu
Companheiro !
Saída
Alo Companheiro !
*/
