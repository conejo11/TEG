#include <stdlib.h>
#include <stdio.h>
#include "bibFunçõesArvBin.h"

void insere(noh ** arv, int val){
    noh *temp = NULL;

    if(!(*arv)){
        temp = (noh *)malloc(sizeof(noh));
        temp->esq = temp->dir = NULL;
        temp->dados = val;
        *arv = temp;
        return;
    }
    if(val < (*arv)->dados){
        insere(&(*arv)->esq, val);
    }
    else if(val > (*arv)->dados){
        insere(&(*arv)->dir, val);
    }
}
void delArv(noh * arv){
    if (arv){
        delArv(arv->esq);
        delArv(arv->dir);
        free(arv);
    }
}