#include <stdlib.h>
#include <stdio.h>
#include "bibFun��esArvBin.h"

int main(){
    FILE *texto;
    int i = 0;
    noh *raiz;
    noh *tmp;

    raiz = NULL;

    /* Insere os nos na arvore */
    texto = fopen("grafo.txt","r+");

    if(texto == NULL){
        printf("Erro ao ler arquivo\n");
        EXIT_FAILURE;
    }

    while((fscanf(texto," %i\n", &i)) != EOF){
        insere(&raiz, i);
    }

    
    /* Deleta todos os n�s da �rvore */
    delArv(raiz);

    return 0;
}

void dfs(int i){

}
