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
void encontraCentro();
int relacoes(int **p);
int **geraMatriz(int qtdVert);
void dfs(int **p, int *visit, int *contAresta, int *maxContAresta, int *med, int i, int qtdVert);

int main(){
	int opcao = 0;

	while(opcao!=2){
		printf("Quais das opcoes tu desejas?\n");
        printf("1 - Encontrar centro e mediana no grafo\n");
        printf("2 - Sair\n");
        scanf("%i", &opcao);

		switch(opcao){
            case 1:
                encontraCentro();
                break;
            case 2:
                return 0;
		}
	}
	return 0;
}

void encontraCentro(){
	int i = 0, j = 0, opcao = 0, qtdAres =0,
		grau = 0, contAresta = 0, qtdVert = 0,
		maxContAresta, menorCaminM = 200, mediana, comparaMed = 1000;
    int **p = NULL;

    printf("Digite o numero de vertices:\n");
	scanf("%i", &qtdVert);

	int caminMax[qtdVert], visitado[qtdVert], med[qtdVert];

	for(i = 0; i < qtdVert; i++){
		visitado[i] = caminMax[i] = med[i] = 0;
	}

	p = geraMatriz(qtdVert);
	relacoes(p);

	for(i = 0; i < qtdVert; i++){
        dfs(p, visitado, &contAresta, &maxContAresta, med, i, qtdVert);
        caminMax[i] = maxContAresta;
        if(maxContAresta < menorCaminM){
            menorCaminM = maxContAresta;
		}
		contAresta =0;
		maxContAresta = 0;
        memset(visitado, 0, sizeof(visitado));
	}

	for(i = 0; i < qtdVert; i++){
        if(med[i] < comparaMed){
            comparaMed = med[i];
            mediana = i;
        }
    }

    printf("\nMediana: %i",mediana+1);
	printf("\nCentros: ");
	for(i = 0; i < qtdVert; i++){
		if(caminMax[i] == menorCaminM)
			printf("%i ", i+1);
	}
	free(p);
	printf("\n");
	printf("\n");
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

int relacoes(int **p){
    FILE *pFile;
    int i = 0, j = 0;
    pFile = fopen("grafo.txt","r+");

    while((fscanf(pFile," %i %i\n", &i, &j)) != EOF){
        p[i-1][j-1] += 1;
        }
	return 0;

}

void dfs(int **p, int *visit, int *contAresta, int *maxContAresta, int *med, int i, int qtdVert){
    int x;
    visit[i] = 1;

    for(x = 0; x < qtdVert; x++){
        if(!visit[x] && p[i][x] != 0){
            (*contAresta)++;
            dfs(p, visit, contAresta, maxContAresta, med, x, qtdVert);
        }
    }

    med[i] += *contAresta;

    if((*contAresta) > (*maxContAresta)){
        *maxContAresta = *contAresta;
    }

    (*contAresta)--;
}
