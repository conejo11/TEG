#include<stdlib.h>
#include<stdio.h>

struct arvBin {
    int dados;
    struct arvBin * dir, * esq;
};

typedef struct arvBin noh;

void insere(noh ** arv, int val);
void print_preOrdem(noh * arv);
void print_emOrdem(noh * arv);
void print_posOrdem(noh * arv);
void delArv(noh * arv);
