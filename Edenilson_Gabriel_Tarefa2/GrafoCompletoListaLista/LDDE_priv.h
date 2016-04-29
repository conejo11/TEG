//----------------------------------------------//
//Universidade do Estado de Santa Catarina - UDESC
//Centro de Ciências Tecnológicas - CCT
//Disciplina: Teoria dos Grafos
//Professor: Omir Correa Alves Junior
//Acadêmicos: Edenilson Jonatas dos Passos
//            Gabriel Conejo
//-------------------------------------------//

#include "LDDE.h"


typedef struct noLDDE{
    void *dados;
    struct noLDDE *prox;
    struct noLDDE *ant;
}NoLDDE,*pNoLDDE;

typedef struct LDDE{
    int tamInfo;
    pNoLDDE lista;
}LDDE;

