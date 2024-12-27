#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char word[11];
    char leitura[50];
    
    char nome[6];
    scanf("%s", nome);

    size_t len_prefix = strlen("arq_bin/14_arquivo_contar_palavra/");
    size_t len_nome = strlen(nome);
    char *filename = calloc(len_prefix + len_nome + 1, sizeof(char)); 

    if (filename == NULL) {
        printf("Erro ao alocar memória para filename\n");
        return 1;
    }

    strcpy(filename, "arq_bin/14_arquivo_contar_palavra/");
    strcat(filename, nome);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(filename);
        return 1;
    }

    scanf(" %s", word);
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    
    int count = 0;
    
    while (fscanf(file, "%s", leitura) == 1) {                   
        for (int i = 0; i < strlen(leitura); i++) {                                                                                                                       
            if(leitura[i]<65 || (leitura[i]>90 && leitura[i]<97) || leitura[i]>122) {                                                                                        
                leitura[i]='\0';                                                                                                                                          
            } else {                                                                                                                                                     
                leitura[i] = tolower(leitura[i]);
            }
        }
        
        if (strcmp(word, leitura) == 0) {                                                                                                                                 
            count++;                                                                                                                                                     
        }
    }
    
    printf("quantidade: %d\n", count);

    free(filename);
    fclose(file);

    return 0;
}


/* 
Implemente um programa em C que leia o nome de um arquivo de texto e 
uma palavra de até 10 caracteres. O programa deve contar quantas vezes 
a palavra aparece no arquivo, considerando a distinção entre maiúsculas 
e minúsculas, e ignorando situações em que a palavra aparece como parte 
de outra palavra (seguida por pontuação, por exemplo). 
O resultado deve ser impresso no formato especificado.

Exemplos de arquivo
1.txt
testando o teste, eh um teste Ana, ana banana ana

Exemplo:

Entrada:
1.txt
ana

Saída:
quantidade: 3

*/