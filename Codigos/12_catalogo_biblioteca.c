#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void alocamat(char ***m, int num) {
    (*m) = (char **)malloc(num * sizeof(char *));
    if ((*m) == NULL)
        exit(1);
}

void matriz(char **m, int i, int tam) {
    m[i] = (char *)malloc(tam * sizeof(char));
    if (m[i] == NULL)
        exit(2);
}

void alocavetor(int **qntd, int tam) {
    (*qntd) = (int *)malloc(tam);
    if ((*qntd) == NULL)
        exit(2);
}


int main() {
    int num, i = 0;
    char **titulo, **autor, **data;
    int *qntd;

    scanf("%d", &num);

    alocamat(&titulo, num);
    alocamat(&autor, num);
    alocamat(&data, num);
    alocavetor(&qntd, num*sizeof(int));

    for (int c = 0; c < num; c++) {
        qntd[c] = 0;
    }

    for (int a = 0; a < num; a++) {
        int jaexiste = 0;
        char *str;
        alocavetor((int **) &str, 160*sizeof(char));
        scanf(" %159[^\n]", str);

        char *token = strtok(str, ",");
        
        for (int z = 0; z < i; z++) {
            if (strcmp(token, titulo[z]) == 0) {
                jaexiste = 1;
                qntd[z]++;
                break;
            }
        }

        if (!jaexiste) {
            matriz(titulo, i, strlen(token) + 1);
            strcpy(titulo[i], token);

            token = strtok(NULL, ",");
            matriz(autor, i, strlen(token) + 1);
            strcpy(autor[i], token);

            token = strtok(NULL, "\n");
            matriz(data, i, strlen(token) + 1);
            strcpy(data[i], token);

            qntd[i]++;
            i++;
        }
        free(str);
    }

    printf("Catalogo de Livros:\n");
    for (int b = 0; b < i; b++) {
        printf("Livro %d:\n", b + 1);
        printf("Titulo: %s\n", titulo[b]);
        printf("Autor:%s\n", autor[b]);
        printf("Ano:%s\n", data[b]);
        printf("Quantidade: %d\n", qntd[b]);
        if(b<i-1)
            printf("\n");
        
    }

    for (int j = 0; j < i; j++) {
        free(titulo[j]);
        free(autor[j]);
        free(data[j]);
    }
    free(titulo);
    free(autor);
    free(data);
    free(qntd);

    return 0;
}

/* 
Desenvolva um programa em C para gerenciar dinamicamente um catálogo de livros de uma biblioteca comunitária. 
O programa deve: 
- Receber um inteiro N indicando a quantidade de livros a serem cadastrados. 
- Ler N linhas contendo o título, o autor e o ano de publicação de cada livro (separados por vírgulas). 
- Armazenar as informações em vetores alocados dinamicamente. 
- Contabilizar a quantidade de exemplares de cada livro, considerando títulos, autores e anos iguais como sendo o mesmo livro. 
- Exibir o catálogo organizado, mostrando o título, o autor, o ano de publicação e a quantidade de exemplares. 
- Utilizar as funções malloc(), calloc(), realloc() e free() da biblioteca stdlib.h. 
- Não utilizar vetores estáticos e liberar toda a memória alocada ao final do programa. 

Exemplo de entrada e saída: 
Entrada: 
8 
As Brumas de Avalon, Marion Zimmer Bradley, 1982 
O Talentoso Ripley, Patricia Highsmith, 1955 
O Pintassilgo, Donna Tartt, 2013 
Sapiens: Uma Breve Historia da Humanidade, Yuval Noah Harari, 2011 
Sapiens: Uma Breve Historia da Humanidade, Yuval Noah Harari, 2011 
O Pintassilgo, Donna Tartt, 2013 
Os Pilares da Terra, Ken Follett, 1989 
Os Pilares da Terra, Ken Follett, 1989 

Saída: 
Catalogo de Livros: 
Livro 1: 
Titulo: As Brumas de Avalon 
Autor: Marion Zimmer Bradley 
Ano: 1982 
Quantidade: 1 

Livro 2: 
Titulo: O Talentoso Ripley 
Autor: Patricia Highsmith 
Ano: 1955 
Quantidade: 1 

Livro 3: 
Titulo: O Pintassilgo 
Autor: Donna Tartt 
Ano: 2013 
Quantidade: 2 

Livro 4: 
Titulo: Sapiens: Uma Breve Historia da Humanidade 
Autor: Yuval Noah Harari 
Ano: 2011 
Quantidade: 2 

Livro 5: 
Titulo: Os Pilares da Terra 
Autor: Ken Follett 
Ano: 1989 
Quantidade: 2 
*/
