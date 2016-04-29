#include<stdlib.h>
#include<stdio.h>
#include "bibFunçõesArvBin.h"

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

    /* Imprime os nós da árvore */
    printf("Pre Ordem:\n");
    print_preOrdem(raiz);

    printf("Em ordem\n");
    print_emOrdem(raiz);

    printf("Pos Ordem\n");
    print_posOrdem(raiz);

    /* Deleta todos os nós da árvore */
    delArv(raiz);

    return 0;
}
