#include <stdio.h>
#include <stdlib.h>

int main () {
    int num = 0;
    int pos;
    scanf("%d", &num);
    if (num == 0)
    {
        printf("Sem atividades registradas hoje\n");
        return 0;
    }
    int qntdcompra, qntdvenda;
    float precocompra, precovenda, lucro=0, maior;
    float produto[num];
    for (int i=0; i<num; i++)
    {
        scanf("%f %f %d %d", &precocompra, &precovenda, &qntdcompra, &qntdvenda);
        produto[i]= qntdvenda*precovenda - qntdcompra*precocompra;
        lucro+=produto[i];
    }
    if(lucro>=0)
    {
        printf("lucro: %.2f\n", lucro);
    } else {
        printf("prejuizo: %.2f\n", (-1)*lucro);
    }
    maior=produto[num-1];
    pos=num;
    for (int u=num-1; u>0; u--){
        if (produto[u-1]>maior)
        {
            maior=produto[u-1];
            pos=u;
        }
    }
    printf("produto: %d ", pos);
    printf("lucro relativo: %.2f", maior);
    return 0;
}
/* 
   O programa recebe a quantidade de produtos negociados no dia e calcula o lucro/prejuízo total, 
   além de determinar o índice do produto com a maior receita.

   Entrada:
   - Um número inteiro n (quantidade de produtos).
   - Para cada um dos n produtos, são fornecidos 4 valores:
     preço de compra, preço de venda, quantidade adquirida e quantidade vendida.

   Exemplo de Entrada:
   3
   10.0 15.0 5 7
   8.0 12.0 10 8
   6.0 9.0 4 6

   Saída:
   "lucro : 101.00"
   "produto : 1 lucro relativo : 55.00"
*/


