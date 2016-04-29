//----------------------------------------------//
//Universidade do Estado de Santa Catarina - UDESC
//Centro de Ciências Tecnológicas - CCT
//Disciplina: Teoria dos Grafos
//Professor: Omir Correa Alves Junior
//Acadêmicos: Edenilson Jonatas dos Passos
//            Gabriel Conejo
//-------------------------------------------//
/* entrada do tipo: vértice1 vértice2 vertice2 vertice 1, ou seja, vai e vem.

ex:
1 2   vértice 1 liga com vértice 2.
2 1   vértice 2 liga com vértice 1.
1 3   vértice 1 liga com vértice 3.
3 1
2 4
4 2
2 5
5 2
3 4
4 3
3 5
5 3
*/

#include <stdio.h>
#include <stdlib.h>
void funcoes();
int relacoes(int **p, int qtdVert);
int **geraMatriz(int qtdVert);
void dfs(int **p, int i, int qtdVert);
int visitado[50];

int main(){
	int opcao = 0;

	while(opcao!=2){
		printf("Quais das opcoes tu desejas?\n");
        printf("1 - Encontrar centro e mediana no grafo\n");
        printf("2 - Sair\n");
        scanf("%i", &opcao);

		switch(opcao){
            case 1:
                funcoes();
                break;
            case 2:
                return 0;
		}
	}
	return 0;
}

void funcoes(){
	int i = 0, j = 0, opcao = 0,qtdVert = 0, count = 0, aa = 0;
    int **p = NULL;

    printf("Digite o numero de vertices:\n");
	scanf("%i", &qtdVert);

	p = geraMatriz(qtdVert);
	relacoes(p, qtdVert);

	for(i = 0; i < qtdVert; i++){
        dfs(p, i, qtdVert);
		for(j=1;j<=qtdVert;j++){
        if(visitado[j])
            count++;
        }
        memset(visitado, 0, sizeof(visitado));
	}

    if((count/i)==qtdVert-1)
            printf("\nO Grafo eh conexo\n\n");
        else
            printf("\nO Grafo nao eh conexo\n\n");

	free(p);
}


int **geraMatriz(int qtdVert){
	int i, j;
	int **p;

	p = (int **) malloc(qtdVert * sizeof(int *));
    for (i = 0; i < qtdVert; i++){
    	p[i] = (int *) malloc(qtdVert * sizeof(int));
    	for(j = 0;j < qtdVert; j++){
    		p[i][j] = 0;
		}
    }

    return p;
}

int relacoes(int **p, int qtdVert){
    FILE *pFile;
    int i = 0, j = 0;
    pFile = fopen("grafo.txt","r+");

    while((fscanf(pFile," %i %i\n", &i, &j)) != EOF){
        p[i-1][j-1] += 1;
    }

    int k, l;
    printf("\n\n");
    for(k = 0; k < qtdVert; k++){
        for(l = 0; l < qtdVert; l++){
            printf("  %i ", p[k][l]);
        }
        printf("\n");
    }
    printf("\n\n");

	return 0;

}

void dfs(int **p, int i, int qtdVert){
    int x;
    visitado[i] = 1;

    for(x = 0; x < qtdVert; x++){
        if(!visitado[x] && p[i][x] != 0){
            dfs(p, x, qtdVert);
        }
    }
}
