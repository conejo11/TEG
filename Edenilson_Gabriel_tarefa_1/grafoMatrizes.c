//----------------------------------------------//
//Universidade do Estado de Santa Catarina - UDESC
//Centro de Ciências Tecnológicas - CCT
//Disciplina: Teoria dos Grafos
//Professor: Omir Correa Alves Junior
//Acadêmicos: Edenilson Jonatas dos Passos
//            Gabriel Conejo
//-------------------------------------------//


#include <stdio.h>
#include <stdlib.h>
#include "grafoMatrizes.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------ADJACENCIA-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

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

int relacaoes(int **p){
    int i = 0, j = 0;

    printf("Quais as relacoes entre arestas? Digite -1 e -1 para terminar\n");

    while((i != -1)&&(j != -1)){
        scanf("%i %i", &i, &j);
        if((i == -1)&&(j == -1)){
            return 0;
        }
        p[i-1][j-1] += 1;
    }
	 return 0;

}

int** adicionaVertice(int qtdVert, int **p){

    int l, i, z;

    p = (int **) realloc(p, qtdVert * sizeof(int *));
    p[qtdVert-1] = (int *) malloc(qtdVert * sizeof(int));

    for(z = 0; z < qtdVert-1; z++){
        p[z] = (int *) realloc(p[z], qtdVert * sizeof(int));
    }

    for(l = 0; l < qtdVert; l++){
        p[qtdVert-1][l] = 0;
    }

    for(i = 0; i < qtdVert; i++){
        p[i][qtdVert-1] = 0;
    }

    return p;
}

void removeVertice(int qtdVert, int vertDel, int **p){
    int i, j;

    for(i = 0; i < qtdVert; i++){
        p[vertDel][i]=0;
    }
    for(j = 0; j < qtdVert; j++){
        p[j][vertDel]=0;
    }

}

void mostraGrau(int grau, int qtdVert, int **p){
    int i = 0, cont = 0;

    for(i = 0; i < qtdVert; i++){
        cont = cont + p[grau-1][i];
    }

    printf("O vertice %i tem grau %i\n", grau, cont);
    printf("\n\n");
}

void zeraMatriz(int qtdVert, int **p){
    int i, j;

	for (i = 0; i < qtdVert; i++){
   	for(j = 0;j < qtdVert; j++){
            p[i][j] = 0;
		}
   }
}

void imprimeMatriz(int qtdVert, int **p){
    int k, l;
    printf("\n\n");
    for(k = 0; k < qtdVert; k++){
        for(l = 0; l < qtdVert; l++){
            printf("  %i ", p[k][l]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void grafoComplementar(int qtdVert, int **p){
   int i, j;
	int **q;

    q = (int **) malloc(qtdVert * sizeof(int *));
    for (i = 0; i < qtdVert; i++){
        q[i] = (int *) malloc(qtdVert * sizeof(int));
    }

    q = p;

	int k, l, x, y;
    for(k = 0; k < qtdVert; k++){
        for(l = 0; l < qtdVert; l++){
            if(q[k][l]==0){
                q[k][l]=1;
            }
            else if(q[k][l]==1){
                q[k][l]=0;
            }
        }
    }

    for(k = 0; k < qtdVert; k++){
        for(l = 0; l < qtdVert; l++){
            printf("  %i ", p[k][l]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------INCIDENCIA-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int **geraMatrizIncidencia(int qtdVert,int qtdAres){
	int i, j;
	int **p;

    p = (int **) malloc(qtdAres * sizeof(int *));
    for (i = 0; i < qtdAres; i++){
    	p[i] = (int *) malloc(qtdVert * sizeof(int));
    	for(j = 0;j < qtdVert; j++){
    		p[i][j] = 0;
		}
    }
    return p;
}

void zeraMatrizIncidencia (int qtdAres, int qtdVert, int **p){
    int i, j;

	for (i = 0; i < qtdAres; i++){
   	for(j = 0;j < qtdVert; j++){
            p[i][j] = 0;
		}
   }
}

void mostraGrauIncidencia(int grau, int qtdAres, int **p){
    int i = 0, cont = 0;

    for(i = 0; i < qtdAres; i++){
        cont = cont + abs(p[i][grau-1]);
    }

    printf("O vertice %i tem grau %i\n", grau, cont);
    printf("\n\n");
}

void imprimeMatrizIncidencia (int qtdAres,int qtdVert, int **p){
    int k, l;
    printf("\n\n");
    for(k = 0; k < qtdAres; k++){
        for(l = 0; l < qtdVert; l++){
            printf("  %i ", p[k][l]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int relacaoIncidencia(int **p){
    int i = 0, j = 0;

    printf("Quais as relacoes entre aresta e vertice? Digite -1 e -1 para terminar\n");

    while((i != -1)&&(j != -1)){
        scanf("%i %i", &i, &j);
        if((i == -1)&&(j == -1)){
            return 0;
        }
        p[i-1][j-1] += 1;
    }
	 return 0;
}

int relacaoIncidenciaDirecionada(int **p){
    int i = 0, j = 0,x = 0 ;

    printf("Quais as relacoes entre aresta e vertice ? Digite -1 e -1 para terminar\n");

    while((i != -1)&&(j != -1)){
    	printf("relação aresta x vértice:\n");
        scanf("%i %i", &i, &j);
        if((i == -1)&&(j == -1)){
            return 0;
        }
        printf("digite 1 para aresta entrar no vértice ou 2 para sair\n");
        scanf("%d",&x);
        if(x == 1){
        	p[i-1][j-1] -= 1;
        }
        else{
        	 p[i-1][j-1] += 1;
        }
    }
	 return 0;
}

void removeVerticeIncidencia(int qtdAres, int vertDel, int **p){
    int i, j;

    for(j = 0; j < qtdAres; j++){
        p[j][vertDel]=0;
    }

}

int** adicionaVerticeIncidencia(int qtdVert, int **p){

    int l, i, z;

    p = (int **) realloc(p, qtdVert * sizeof(int *));
    p[qtdVert-1] = (int *) malloc(qtdVert * sizeof(int));

    for(z = 0; z < qtdVert-1; z++){
        p[z] = (int *) realloc(p[z], qtdVert * sizeof(int));
    }

    for(i = 0; i < qtdVert; i++){
        p[i][qtdVert-1] = 0;
    }

    return p;
}
