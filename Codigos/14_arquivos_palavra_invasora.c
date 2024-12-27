#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char word[50], nome[9], *p, *arquivo;
    int tam = 0;

    scanf("%s", word);
    scanf(" %s", nome);

    size_t len_prefix = strlen("arq_bin/14_arquivos_palavra_invasora/");
    size_t len_nome = strlen(nome);
    char *filename = calloc(len_prefix + len_nome + 1, sizeof(char)); 

    if (filename == NULL) {
        printf("Erro ao alocar memória para filename");
        return 1;
    }

    strcpy(filename, "arq_bin/14_arquivos_palavra_invasora/");
    strcat(filename, nome);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        free(filename);
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        tam++;
    }

    fseek(file, 0, SEEK_SET); 
    arquivo = (char *)calloc(tam + 1, sizeof(char)); 
    if (arquivo == NULL) {
        printf("Erro ao alocar memória para arquivo");
        fclose(file);
        free(filename);
        return 1;
    }

    for (int i = 0; i < tam; i++) {
        arquivo[i] = fgetc(file);
    }
    arquivo[tam] = '\0'; 

    fclose(file); 

    p = strstr(arquivo, word);
    if (p == NULL) {
        printf("Palavra não encontrada no arquivo.\n");
        free(arquivo);
        free(filename);
        return 0;
    }

    int i = 0;
    while (&arquivo[i] != p) {
        printf("%c", arquivo[i]);
        i++;
    }
    p += strlen(word);
    if (arquivo[i - 1] == ' ' && *p == ' ') {
        p += 1;
    }
    printf("%s", p);

    free(arquivo);
    free(filename);

    return 0;
}


/* 
Implemente um programa em C que leia um arquivo binário no formato 
"binn.bin" e remova uma palavra invasora do conteúdo do arquivo. O 
programa deve receber a palavra invasora e o nome do arquivo como 
entrada, e imprimir o texto sem a palavra invasora. Após a execução, 
deve liberar a memória e fechar o arquivo.

Exemplo:

Entrada:
pedro bin1.bin

Saída:
O jiu jitsu ganha tanto do muay 
thai quanto do boxe quanto do judo 
quanto do karate
*/
