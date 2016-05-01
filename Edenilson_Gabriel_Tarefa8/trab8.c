#define infinito 999
#include <stdio.h>
#include <stdlib.h>

void dijkstra(int qtdVert, int v, int **vetorCustos, int vetorDistancias[]){
    int i, j, k, cont, marcador[1000], min;

    for(i = 0; i < qtdVert; i++){
        marcador[i] = 0;
        vetorDistancias[i] = vetorCustos[v-1][i];
    }
    cont = 2;
    while(cont <= qtdVert){
        min=999;
        for(k = 0; k < qtdVert; k++){
            if(vetorDistancias[k] < min && !marcador[k]){
                min = vetorDistancias[k];
                j = k;
            }
        }
        marcador[j] = 1;
        cont++;
        for(k = 1; k <= qtdVert; k++){
            if((vetorDistancias[j] + vetorCustos[j][k] < vetorDistancias[k]) && !marcador[k]){
                vetorDistancias[k] = vetorDistancias[j] + vetorCustos[j][k];
            }
        }
    }
}

int **geraMatriz(int qtdVert){
    int i, j;
    int **p;

    p = (int **) malloc(qtdVert * sizeof(int *));
    for (i = 0; i < qtdVert; i++){
        p[i] = (int *) malloc(qtdVert * sizeof(int));
        for(j = 0; j < qtdVert; j++){
            p[i][j] = 0;
        }
    }

    return p;
}

int relacoes(int **p){
    FILE *pFile;
    int i = 0, j = 0;
    pFile = fopen("grafo.txt","r+");

    while((fscanf(pFile," %i %i\n", &i, &j)) != EOF){
        p[i-1][j-1] += 1;
    }

    return 0;
}

int main(){
    int qtdVert, vertOrigem, i, j, vetorDistancias[10000], custo;
    int **vetorCustos;

    printf("Entre o numero de vertices:\n");
    scanf("%i", &qtdVert);
    vetorCustos = geraMatriz(qtdVert);
    relacoes(vetorCustos);

    for(i = 0; i < qtdVert; i++){
        for(j = 0;j < qtdVert; j++){
            printf(" %i  ", vetorCustos[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < qtdVert; i++){
        for(j = 0; j < qtdVert; j++){
            if(vetorCustos[i][j] == 1){
                printf("Digite o custo de %d -> %d:\n",i+1,j+1);
                scanf("%i", &custo);
                vetorCustos[i][j] = custo;
            } else if(vetorCustos[i][j] == 0){
                vetorCustos[i][j] = infinito;
            }
          }
        }

    printf("Digite o vertice de origem:\n");
    scanf("%i", &vertOrigem);
    dijkstra(qtdVert, vertOrigem, vetorCustos, vetorDistancias);
    printf("\nMenor Caminho:\n");
    for(i = 1; i <= qtdVert; i++){
        if(i != vertOrigem){
            printf("%i -> %i, custo = %i\n", vertOrigem, i, vetorDistancias[i-1]);
        }
    }

    return 0;
}
