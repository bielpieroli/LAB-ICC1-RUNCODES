#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char receita[20];
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int chocolate;
} caderno;

typedef struct {
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int chocolate;
} comprados;

int main () {
    char comando;
    caderno *receitas;
    comprados compras;
    int indice, qntdrec = 0;
    
    compras.farinha=0;
    compras.ovos=0;
    compras.oleo=0;
    compras.acucar=0;
    compras.chocolate=0;
    
    receitas=(caderno *)malloc(sizeof(caderno));
    
    scanf("%c", &comando);
    
    while (comando!='S') {
        switch(comando) {
            case 'R': {
                receitas=(caderno *)realloc(receitas,(qntdrec+2)*sizeof(caderno));
                scanf(" %[^ ]s", receitas[qntdrec].receita);
                scanf("%d", &receitas[qntdrec].farinha);
                scanf("%d", &receitas[qntdrec].ovos);
                scanf("%d", &receitas[qntdrec].oleo);
                scanf("%d", &receitas[qntdrec].acucar);
                scanf("%d", &receitas[qntdrec].chocolate);
                qntdrec++;
                break;
            }
            case 'C': {
                int temp;
                scanf("%d", &temp);
                compras.farinha+=temp;
                scanf("%d", &temp);
                compras.ovos+=temp;
                scanf("%d", &temp);
                compras.oleo+=temp;
                scanf("%d", &temp);
                compras.acucar+=temp;
                scanf("%d", &temp);
                compras.chocolate+=temp;
                break;
            }
            case 'F': {
                scanf("%d", &indice);
                if (indice>=qntdrec) {
                    printf("Receita nao encontrada!\n");
                    break;
                } else {
                    if(compras.farinha-receitas[indice].farinha<0) {
                        printf("Farinha insuficiente\n");
                        break;
                    } else if(compras.ovos-receitas[indice].ovos<0) {
                        printf("Ovos insuficientes\n");
                        break;
                    } else if(compras.oleo-receitas[indice].oleo<0) {
                        printf("Oleo insuficiente\n");
                        break;
                    } else if(compras.acucar-receitas[indice].acucar<0) {
                        printf("Acucar insuficiente\n");
                        break;
                    } else if(compras.chocolate-receitas[indice].chocolate<0) {
                        printf("Chocolate insuficiente\n");
                        break;
                    } else {
                        compras.farinha-=receitas[indice].farinha;
                        compras.ovos-=receitas[indice].ovos;
                        compras.oleo-=receitas[indice].oleo;
                        compras.acucar-=receitas[indice].acucar;
                        compras.chocolate-=receitas[indice].chocolate;
                        printf("%s feita com sucesso!\n", receitas[indice].receita);
                        break;
                    }
                        
                }
            }
            default: printf("Codigo invalido\n");
        }
        scanf(" %c", &comando);
    }
    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", compras.acucar);
    printf("Chocolate: %d\n", compras.chocolate);
    printf("Farinha: %d\n", compras.farinha);
    printf("Oleo: %d\n", compras.oleo);
    printf("Ovos: %d\n", compras.ovos);
    printf("Receitas cadastradas: %d", qntdrec);
    free(receitas);
    return EXIT_SUCCESS;
}

/* 
1 Descrição
Você está ajudando sua avó Lurdes a gerenciar suas receitas de forma mais prática. Ela tem dificuldades em anotar tudo manualmente, então você decidiu criar um programa em C para ajudá-la a registrar e gerenciar suas receitas e o estoque de ingredientes. O programa precisa permitir 4 funcionalidades principais:

- **R** para registrar uma nova receita, onde a receita possui 6 campos:
  - Uma string que representa o nome da receita (não maior que 20 caracteres).
  - 5 inteiros que representam as quantidades de farinha, ovos, óleo, açúcar e chocolate para a receita.
  
- **C** seguido de 5 inteiros para cadastrar a compra de ingredientes para o estoque, seguindo a mesma ordem dos ingredientes na receita (farinha, ovos, óleo, açúcar, chocolate).
  
- **F** seguido de um número inteiro que representa o número da receita a ser feita. O programa deve verificar se a quantidade de ingredientes no estoque é suficiente para realizar a receita. Caso contrário, imprime a mensagem "Ingrediente insuficiente". Se a receita for possível, os ingredientes devem ser subtraídos do estoque e a receita será realizada com sucesso.
  
- **S** para sair do programa. Ao finalizar, o programa deve exibir a quantidade restante de cada ingrediente no estoque e o número total de receitas registradas.

- **Se um comando inválido for inserido, o programa deve exibir a mensagem "Código inválido"**.
- **Se uma receita solicitada para ser feita não for encontrada, deve ser exibida a mensagem "Receita não encontrada!"**.

2 Instruções Complementares
• Utilize a biblioteca stdlib.h para alocar dinamicamente a memória.
• Utilize structs para representar as receitas e o estoque.
• As funções principais de alocação são malloc(), calloc(), realloc() e free().
• Caso o programa receba um comando inválido, deve imprimir "Código inválido".
• Caso a quantidade de ingredientes seja insuficiente, deve exibir o nome do ingrediente que está em falta, como "Farinha insuficiente" ou "Ovo insuficiente".
• Ao final do programa, exiba a quantidade de ingredientes restantes e o número de receitas registradas.

3 Exemplos de Entrada e Saída
Entrada
R Pamonha 100 2 50 0 35
C 100 200 150 150 200
R Bananada 50 4 200 100 50
F 1
R BoloDeChocolate 200 3 100 150 200
F 3
C 50 100 75 200 150
R PaoCaseiro 500 2 50 30 0
C 200 30 400 50 100
J
F 2
K
F 3
R PanquecaAmericana 150 2 25 10 0
F 0
S

Saída
Oleo insuficiente
Receita nao encontrada !
Codigo invalido
BoloDeChocolate feita com sucesso !
Codigo invalido
Farinha insuficiente
Pamonha feita com sucesso !
Quantidade no estoque :
Acucar : 250
Chocolate : 215
Farinha : 50
Oleo : 475
Ovos : 325
Receitas cadastradas : 5

Entrada
R TortaDeMaca 300 4 75 100 0
F 0
R CookiesDeChocolate 250 3 125 200 100
C 950 5 200 350 150
F 1
R BoloDeCenoura 350 4 100 150 50
F 2
R Brigadeiro 0 0 0 300 350
F 3
C 100 150 200 50 75
R TortaDeLimao 200 3 50 75 0
C 300 250 200 100 150
F 4
R MousseDeChocolate 0 2 30 10 350
F 5
S

Saída
Farinha insuficiente
CookiesDeChocolate feita com sucesso !
Ovos insuficientes
Acucar insuficiente
TortaDeLimao feita com sucesso !
Chocolate insuficiente
Quantidade no estoque :
Acucar : 225
Chocolate : 275
Farinha : 900
Oleo : 425
Ovos : 399
Receitas cadastradas : 6
*/
