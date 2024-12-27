#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int count = 0;
    char nome[13];
    scanf("%s", nome);

    size_t len_prefix = strlen("arq_bin/14_arquivo_copiar/");
    size_t len_nome = strlen(nome);
    char *filename = calloc(len_prefix + len_nome + 1, sizeof(char)); 

    if (filename == NULL) {
        printf("Erro ao alocar memória para filename\n");
        return 1;
    }

    strcpy(filename, "arq_bin/14_arquivo_copiar/");
    strcat(filename, nome);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(filename);
        return 1;
    }

    while (fgetc(file) != EOF) {
        count++;
    }
    
    fseek(file, 0, SEEK_SET);

    char *arquivo = (char *) calloc(count + 1, sizeof(char)); 
    if (arquivo == NULL) {
        printf("Erro ao alocar memória para o conteúdo do arquivo\n");
        free(filename);
        fclose(file);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        arquivo[i] = fgetc(file);
    }

    printf("%s\n", arquivo);

    free(arquivo);
    free(filename);
    fclose(file);

    return 0;
}

/* 
Implemente um programa em C que leia o nome de um arquivo binário 
(no formato "binario(n).bin", onde 1 ≤ n ≤ 5) e clone seu conteúdo,
imprimindo-o na tela como texto. O programa deve alocar dinamicamente
a memória necessária para armazenar o conteúdo do arquivo e imprimir o
texto. Após a leitura e impressão, o programa deve liberar a memória e
fechar o arquivo.

Exemplo:
Entrada:
binario1.bin
Saída:
Eu nao sou mais o Vitor, Vitor era meu nome de nerd, pai. Agora eu
sou o Veeeeeectoooooooooor!!!
*/
