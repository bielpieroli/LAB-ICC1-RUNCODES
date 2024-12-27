#include <stdio.h>
#include <stdlib.h>
void leitura(int *m, int *n, char mat[20][20]);
void semcosplay(int m, int n, char mat[20][20], char matnv[20][20]);
void lugarvazio(int m, int n, char mat[20][20], char matnv[20][20]);
void matrizfinal(int m, int n, char mat[20][20], int tristedia);
void leitura(int *m, int *n, char mat[20][20]){
	scanf("%d %d", m, n);
	for (int i=0; i<*m; i++)
	{
		for (int j=0; j<*n; j++)
		{
			scanf(" %c", &mat[i][j]);
		}
	}
}
void lugarvazio(int m, int n, char mat[20][20], char matnv[20][20]){
     for (int i=0; i<m; i++)
     {
          for (int j=0; j<n; j++)
          {
               if(mat[i][j]=='v')
               {
                    matnv[i][j]='o';
               } else {
                    matnv[i][j]='x';
               }
          }
     }
}
void semcosplay(int m, int n, char mat[20][20], char matnv[20][20]){
     for (int i=0; i<m; i++)
     {
          for (int j=0; j<n; j++)
          {
               if(mat[i][j]=='c')
               {
                    for (int a=0; a<m; a++)
                    {
                         matnv[a][j]='x';
                    }
                    for (int b=0; b<n; b++)
                    {
                         matnv[i][b]='x';
                    }
               }
          }
     }
}
void matrizfinal(int m, int n, char matnv[20][20], int tristedia) {
     for (int a=0; a<m; a++)
     {
          for(int b=0; b<n; b++)
          {
               if(matnv[a][b]=='o')
               {
                    tristedia=0;
                    break;
               }
          }
     }
     if(tristedia){
          printf("Eh um dia triste para os mono Yasuo\n");
     } else {
          for (int i=0; i<m; i++)
          {
               for (int j=0; j<n; j++)
               {
                    printf("%c ", matnv[i][j]);
               }
               printf("\n");
          }
     }
}
int
main () {
	int m, n, tristedia=1;
	char mat[20][20], matnv[20][20];
	leitura(&m,&n,mat);
     lugarvazio(m,n,mat,matnv);
     semcosplay(m,n,mat,matnv);
     matrizfinal(m,n,matnv,tristedia);
     return EXIT_SUCCESS;
}

/*
O programa determina os lugares disponíveis para Ze sentar na matriz de assentos, obedecendo às seguintes regras:
- Ze só pode sentar em lugares vazios ('v').
- Ze não pode sentar em linhas ou colunas que contenham cosplayers ('c').
- Se nenhum lugar válido existir, exibir "Eh um dia triste para os mono Yasuo".

Entrada:
1. Um inteiro N e um inteiro M representando as dimensões da matriz.
2. Uma matriz N x M contendo:
   - 'c' para lugares ocupados por cosplayers.
   - 'f' para fãs sem cosplay.
   - 'v' para lugares vazios.

Saída:
1. Uma matriz N x M, onde:
   - 'o' representa lugares disponíveis para Ze.
   - 'x' representa lugares indisponíveis para Ze.
2. Se não houver lugares disponíveis, a saída é "Eh um dia triste para os mono Yasuo".

Exemplo de Entrada 1:
10 10
c c c c c c c c c c
v v v v v v v v v v
v v v v v v v v v v
v v v v v v v v v v
v v v v v v v v v v
v v v v v v v v v v
v v v v v v v v v v
v v v v v v v v v v
v v v v v v v v v v
v v v v v v v v v v

Exemplo de Saída 1:
Eh um dia triste para os mono Yasuo

Exemplo de Entrada 2:
5 10
c v v v v v f v v f
f f f v f f f f f v
v v f v v f v f v v
v f v v f c f f f f
v v f v v v v v v c

Exemplo de Saída 2:
x x x x x x x x x x
x x x o x x x x x x
x o x o o x o x o x
x x x x x x x x x x
x x x x x x x x x x
*/
