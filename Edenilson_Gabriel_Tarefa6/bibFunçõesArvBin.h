#include <stdlib.h>
#include <stdio.h>

struct arvBin {
    int dados;
    struct arvBin * dir, * esq;
};

typedef struct arvBin noh;

void insere(noh ** arv, int val);
void delArv(noh * arv);
