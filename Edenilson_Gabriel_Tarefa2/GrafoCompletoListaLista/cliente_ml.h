//----------------------------------------------//
//Universidade do Estado de Santa Catarina - UDESC
//Centro de Ci�ncias Tecnol�gicas - CCT
//Disciplina: Teoria dos Grafos
//Professor: Omir Correa Alves Junior
//Acad�micos: Edenilson Jonatas dos Passos
//            Gabriel Conejo
//-------------------------------------------//

#include"LDDE.h"

typedef struct{
    char palavra[50];
    int linha;
    int coluna;
} Palavra, *pPalavra;

int carregaArquivo(FILE *f, char **p);
pLDDE inicializaLista(char *p, int n_linhas);
pLDDE criaSubLista(char *p, int linha);
void mostraLista(pLDDE p, int linha);
void destroiListas(ppLDDE pp);

