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

int main(){

    int i = 0, j = 0, opcao = 0, qtdVert=0, qtdAres =0, grau = 0;
    int opcao1 = 0, vertDel = 0, opcao2 =0, direcionado = 0, dd = 0;
    int **p = NULL;

    printf("Quais das opcoes tu desejas?\n");
    printf("1 - Matriz de adjacencia\n");
    printf("2 - Matriz de incidencia\n");
    scanf("%i", &opcao);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------ADJACENCIA-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

    switch(opcao){
        case 1:
            while(opcao1 != 9){

                printf("Quais das opcoes tu desejas?\n");
                printf("1 - Gerar matriz de adjacencia\n");
                printf("2 - Adicionar relacoes\n");
                printf("3 - Imprimir matriz de adjacencia\n");
                printf("4 - Zerar matriz de adjacencia\n");
                printf("5 - Adicionar um vertice\n");
                printf("6 - Remover um vertice\n");
                printf("7 - Gerar grafo complementar\n");
                printf("8 - Grau dos vertices\n");
                printf("9 - Sair\n");
                scanf("%i", &opcao1);

                switch(opcao1){
                case 1:
                    printf("Quantos vertices?\n");
                    scanf("%i",&qtdVert);
                    p = geraMatriz(qtdVert);
                    break;
                case 2:
                    relacaoes(p);
                    break;
                case 3:
                    imprimeMatriz(qtdVert ,p);
                    break;
                case 4:
                    zeraMatriz(qtdVert ,p);
                    break;
                case 5:
                    qtdVert++;
                    p = adicionaVertice(qtdVert, p);
                    break;
                case 6:
                    printf("Qual vertice tu desejas excluir?\n");
                    scanf("%i", &vertDel);
                    vertDel--;
                    removeVertice(qtdVert, vertDel, p);
                    break;
                case 7:
                    grafoComplementar(qtdVert, p);
                    break;
                case 8:
                    printf("Qual vertice do queres saber o grau?\n");
                    scanf("%i", &grau);
                    printf("\n");
                    mostraGrau(grau, qtdVert, p);
                    break;
                case 9:
                    return 0;

                }
            }

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------INCIDENCIA-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 2:
        	while(opcao2 != 8){

        	 printf("Quais das opcoes tu desejas?\n");
                printf("1 - Gerar matriz de incidencia\n");
                printf("2 - Adicionar relacoes\n");
                printf("3 - Imprimir matriz de incidencia\n");
                printf("4 - Zerar matriz de incidencia\n");
                printf("5 - Adicionar um vertice\n");
                printf("6 - Remover um vertice\n");
                printf("7 - Grau do vertice\n");
                printf("8 - Sair\n");
                scanf("%i", &opcao2);

                switch(opcao2){
                case 1:

                   	printf("Quantos vertices?\n");
                    scanf("%i",&qtdVert);
                    printf("Quantas arestas?\n");
                    scanf("%i",&qtdAres);
                    p = geraMatrizIncidencia(qtdVert, qtdAres);
                    break;
                case 2:
                	printf("O grafo é direcionado? 1 para nao e 2 para sim\n");
                	scanf("%d", &direcionado);
                	switch(direcionado){
                	case 1:
                		relacaoIncidencia(p);
                		break;
                	case 2:
                		relacaoIncidenciaDirecionada(p);
                		break;
                	}

                case 3:
                	imprimeMatrizIncidencia (qtdAres,qtdVert,p);
                    break;
                case 4:
                	zeraMatrizIncidencia (qtdAres,qtdVert,p);
                    break;
                case 5:
                	qtdVert++;
                    p = adicionaVerticeIncidencia(qtdVert, p);
                    break;
                case 6:
                	printf("Qual vertice tu desejas excluir?\n");
                    scanf("%i", &vertDel);
                    vertDel--;
                    removeVerticeIncidencia(qtdAres, vertDel, p);
                    break;
                case 7:
                    printf("Qual vertice do queres saber o grau?\n");
                    scanf("%i", &grau);
                    printf("\n");
                    mostraGrauIncidencia(grau, qtdAres, p);
                    break;
                case 8:
                    return 0;
                }


			}


    }

    printf("\n");
    printf("\n");

    return 0;
}

