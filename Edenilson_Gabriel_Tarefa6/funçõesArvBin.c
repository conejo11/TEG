#include<stdlib.h>
#include<stdio.h>
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

void print_preOrdem(noh * arv){
    if (arv){
        printf("%d\n",arv->dados);
        print_preOrdem(arv->esq);
        print_preOrdem(arv->dir);
    }
}

void print_emOrdem(noh * arv){
    if (arv){
        print_emOrdem(arv->esq);
        printf("%d\n",arv->dados);
        print_emOrdem(arv->dir);
    }
}
void print_posOrdem(noh * arv){
    if (arv){
        print_posOrdem(arv->esq);
        print_posOrdem(arv->dir);
        printf("%d\n",arv->dados);
    }
}

void delArv(noh * arv){
    if (arv){
        delArv(arv->esq);
        delArv(arv->dir);
        free(arv);
    }
}