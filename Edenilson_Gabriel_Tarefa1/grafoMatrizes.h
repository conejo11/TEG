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
//---------------------------------ADJACENCIA----------------------------------------------------------------------

int** adicionaVertice(int qtdVert, int **p);
int** geraMatriz(int qtdVert);
void mostraGrau(int grau, int qtdVert, int **p);
void imprimeMatriz(int qtdVert, int **p);
void grafoComplementar(int qtdVert, int **p);
void zeraMatriz(int qtdVert, int **p);
int relacaoes(int **p);
void removeVertice(int qtdVert, int vertDel, int **p);

//---------------------------------INCIDENCIA----------------------------------------------------------------------

void mostraGrauIncidencia(int grau, int qtdAres, int **p);
int relacaoIncidencia(int **p);
int relacaoIncidenciaDirecionada(int **p);
int **geraMatrizIncidencia(int qtdVert,int qtdAres);
void zeraMatrizIncidencia (int qtdAres, int qtdVert, int **p);
void imprimeMatrizIncidencia (int qtdAres,int qtdVert, int **p);
void removeVerticeIncidencia(int qtdAres, int vertDel, int **p);
int** adicionaVerticeIncidencia(int qtdVert, int **p);
