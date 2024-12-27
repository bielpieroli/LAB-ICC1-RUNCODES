#include <stdio.h>

int main(void) {
    int data_nao_formatada, dia, mes, ano;
    scanf("%d", &data_nao_formatada);
    
    dia = data_nao_formatada / 1000000;   
    mes = (data_nao_formatada % 1000000) / 10000;
    ano = data_nao_formatada % 10000;
    
    printf("%02d/%02d/%04d\n", dia, mes, ano);
    return 0;
}

/*
Implemente um programa em C que leia na entrada padrao de texto uma data desformatada composta de dia, mes e ano.  
Imprima na tela a data formatada da seguinte maneira:--/--/----, seguida por uma quebra de linha.  
(Essa data deve ser lida e tratada como int)

Exemplos de Entrada e Saida  
Entrada  
19082000  

Saida  
19/08/2000  

Entrada  
05121965  

Saida  
05/12/1965  
*/
