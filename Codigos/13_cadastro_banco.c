#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    char *cpf;
    int idade;
    float saldo;
    float credito;
    float divida;
} pessoa;

void alocastruc(pessoa **pessoas, int num) {
    *pessoas = (pessoa *)malloc(num * sizeof(pessoa));
    if (*pessoas == NULL)
        exit(1);
    for (int i = 0; i < num; i++) {
        (*pessoas)[i].nome = (char *)malloc(31 * sizeof(char)); 
        if ((*pessoas)[i].nome == NULL)
            exit(1);
    }
    for (int i = 0; i < num; i++) {
        (*pessoas)[i].cpf = (char *)malloc(31 * sizeof(char)); 
        if ((*pessoas)[i].cpf == NULL)
            exit(1);
    }
}

int main() {
    int num, cont=0;
    pessoa *pessoas;
    scanf("%d", &num);
    alocastruc(&pessoas, num); 

    for (int i = 0; i < num; i++) {
        scanf(" %30[^,], %11[^,], %d, %f, %f", pessoas[i].nome, pessoas[i].cpf, &pessoas[i].idade, &pessoas[i].saldo, &pessoas[i].credito);
        pessoas[i].divida = pessoas[i].credito-pessoas[i].saldo;
        if(pessoas[i].divida>0)
            cont++;
    }

    // Imprimir os dados das pessoas
    for (int i = 0; i < num; i++) {
        printf("Dados da pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Saldo: %.2f\n", pessoas[i].saldo);
        printf("Credito: %.2f\n\n", pessoas[i].credito);
    }
    // Endividados
    printf("Pessoas endividadas:\n");
    int endiv=0;;
    if (cont) {
        for (int i = 0; i < num; i++) {
            int entrou=0;
            if(pessoas[i].divida>0) {
                printf("Nome: %s\n", pessoas[i].nome);
                printf("CPF: %s\n", pessoas[i].cpf);
                printf("Divida: %.2f\n", pessoas[i].divida);
                entrou=1;
                endiv++;
                if(endiv!=cont && entrou) {
                    printf("\n");
                }
            }
        }
    } else {
        printf("Nenhuma pessoa endividada encontrada.");
    }

    for (int i = 0; i < num; i++) {
        free(pessoas[i].nome);
        free(pessoas[i].cpf);
    }
    free(pessoas);

    return EXIT_SUCCESS;
}

/* 
Desenvolva um programa em C para organizar dados de clientes de um banco e identificar os clientes endividados. 
O programa deve: 
- Receber como entrada um inteiro n, representando a quantidade de registros fornecidos. 
- Nas próximas n linhas, receber os dados de cada cliente: nome (string), CPF (tratado como char*), idade (inteiro), saldo (float) e crédito (float), separados por vírgulas. 
- Utilizar uma STRUCT para representar as informações dos clientes. 
- Imprimir a lista de todos os registros de clientes. 
- Identificar e exibir os clientes endividados (aqueles cujo saldo é menor que o crédito). 
- Imprimir "Nenhuma pessoa endividada encontrada." caso não haja clientes endividados. 
- Utilizar a biblioteca stdlib.h para alocação dinâmica e string.h para manipulação de strings. 
- Liberar toda a memória alocada dinamicamente ao final do programa. 

Exemplo de entrada e saída: 
Entrada: 
2 
Ana,98765432100,22,200.00,150.00 
Beatriz,11122233344,30,0.00,100.00 

Saída: 
Dados da pessoa 1: 
Nome: Ana 
CPF: 98765432100 
Idade: 22 
Saldo: 200.00 
Crédito: 150.00 

Dados da pessoa 2: 
Nome: Beatriz 
CPF: 11122233344 
Idade: 30 
Saldo: 0.00 
Crédito: 100.00 

Pessoas endividadas: 
Nome: Beatriz 
CPF: 11122233344 
*/
