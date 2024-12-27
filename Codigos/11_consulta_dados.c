#include <stdio.h>
#include <stdlib.h>
int somafatores(int tamlinha);
void saida(char **mat, int *ip, int vezes);
void alocapont (char ***mat, int vezes) {
    (*mat)=(char **) malloc (vezes*sizeof(char *));
}
void alocalinhaeip (char **mat, int vezes, int *ip) {
    int tamlinha, id;
    for(int z=0; z<vezes; z++)
    {
        scanf("%d", &id);
        scanf("%d", &tamlinha);
        ip[id]=tamlinha;
        tamlinha= somafatores(tamlinha);
        mat[id] = (char *) malloc ((tamlinha +1) *sizeof(char));
        scanf("%s", mat[id]);
    } 
}

int somafatores(int tamlinha) {
    int primos[10000]={};
    primos[0]=1;
    primos[1]=1;
    for (int i =2; i<10000;  i++) 
    {
	    int multiplo= i;
		    while (multiplo+i<10000) 
		    {
		    	multiplo+=i;
			    primos[multiplo]=1;
		    }
    }
    int resultado=0;
    for(int a=0; a<10000; a++) {
        if(!primos[a]) {
            int entrou=0;
            while (tamlinha%a==0) {
                tamlinha=tamlinha/a;
                entrou=1;
            }
            if(entrou)
                resultado+=a;
        }
    }
    return (resultado);
}

void saida(char **mat, int *ip, int vezes){
    for(int i=vezes-1; i>=0; i--)
    {
        printf("%s %d\n", mat[i], ip[i]);
    }
}

int
main () {
    char **mat;
    int vezes = 0;
    scanf("%d", &vezes);
    if(vezes==0)
        printf("Sem produtos a serem cadastrados\n");
    else {
        alocapont(&mat, vezes);
        int *ip = (int *) malloc (vezes*sizeof(int));
        alocalinhaeip(mat, vezes, ip);
        saida(mat, ip, vezes);
        free(ip);
        for (int i=0; i<vezes; i++)
            free(mat[i]);
        free(mat);
    }
    return EXIT_SUCCESS;
}

/* 
Desenvolva um programa em C para registrar dados usando alocacao dinamica, garantindo seguranca contra engenharia reversa. 
O programa deve: 
- Receber como entrada um numero inteiro n, indicando a quantidade de dados. 
- Nas proximas n linhas, receber IP (prioridade do dado), codigo (usado para calcular tamanho da string), e conteudo (string sem espacos). 
- Calcular o tamanho da string baseado na soma dos divisores primos unicos do codigo. 
- Exibir os dados em ordem decrescente de IP, mostrando o conteudo e o codigo. 
- Utilizar apenas vetores dinamicos com calloc(), malloc() e free(). 
- Imprimir "Sem produtos a serem cadastrados" se n = 0. 
- Desalocar toda a memoria ao final do programa. 

Exemplo de entrada e saida: 
Entrada: 
3 
1 54 manga 
0 3624 tome_cuidado_com_palavras_grandes_hahahahhahahahhahaha 
2 67 importante_lembrar_de_casos_com_numeros_primos 

Saida: 
importante_lembrar_de_casos_com_numeros_primos 67 
manga 54 
tome_cuidado_com_palavras_grandes_hahahahhahahahhahaha 3624 

Entrada: 
0 

Saida: 
Sem produtos a serem cadastrados 
*/
