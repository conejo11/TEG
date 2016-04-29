//----------------------------------------------//
//Universidade do Estado de Santa Catarina - UDESC
//Centro de Ciências Tecnológicas - CCT
//Disciplina: Teoria dos Grafos
//Professor: Omir Correa Alves Junior
//Acadêmicos: Edenilson Jonatas dos Passos
//            Gabriel Conejo
//-------------------------------------------//
/* entrada do tipo: vértice1 vértice2 vertice2 vertice 1, ou seja, vai e vem.

ex:
1 2   vértice 1 liga com vértice 2.
2 1   vértice 2 liga com vértice 1.
1 3   vértice 1 liga com vértice 3.
3 1
2 4
4 2
2 5
5 2
3 4
4 3
3 5
5 3
*/

#include <stdio.h>
#include <stdlib.h>

//Funcões utilizadas:
int raiz();
void circuitEuler(int raiz);
void tiraAresta(int raiz,int conectVert);
int verificaFimAlgoritmo();
int ehPonte(int vert);
int proxVertice(int vert);
int ultimoVertice(int vert);
int encontraGrau(int vert);
int pegaVertice(int vert);
void printCaminho();
int relacoes(int **adj);
int **geraMatriz(int qtdVert);

//Declarações globais... do contrário não iria funcionar
int qtdVert, cont = 0, caminFim = 0;
int finalCaminho[100], vetNos[100];
int **adj;


int main(){
    int i,j,k;

    printf("Informe a quantidade de vertices:\n");
    scanf("%d",&qtdVert);

    for( i=0; i<qtdVert; i++){
     vetNos[i] = i;//passa os vértices para o vetor de vértices
    }

  	adj = geraMatriz(qtdVert);
  	relacoes(adj);

    int r,pos;
    if(r=raiz()){ //raiz retorna 0 se caminho ou circuito euleriano não forem possíveis
        if(cont){
            printf("Existe Circuito Euleriano\n");
        }
        else{
            printf("Existe Circuito Semi-Euleriano\n");
        }
        finalCaminho[caminFim++]=r;
        circuitEuler(r);
        printCaminho();
    }else{
        printf("Nao existe Circuito Euleriano\n");
    }
	return 0;
}

int **geraMatriz(int qtdVert){
	int i, j;
	int **adj;
	adj = (int **) malloc(qtdVert * sizeof(int *));
    for (i = 0; i < qtdVert; i++){
    	adj[i] = (int *) malloc(qtdVert * sizeof(int));
    	for(j = 0;j < qtdVert; j++){
    		adj[i][j] = 0;
		}
    }
    return adj;
}

int relacoes(int **adj){
    FILE *pFile;
    int i = 0, j = 0;
    pFile = fopen("grafo.txt","r+");

    while((fscanf(pFile," %i %i\n", &i, &j)) != EOF){
        adj[i-1][j-1] += 1;
    }

    int k, l;
    printf("\n\n");

    for(k = 0; k < qtdVert; k++){
        for(l = 0; l < qtdVert; l++){
            printf("  %i ", adj[k][l]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;

}


//printa o caminho/circuito Euleriano
void printCaminho(){
    int i;
    for(i=0;i<caminFim;i++){
        printf("%d ->",finalCaminho[i]+1);
    }
}

//pega o vértice atual no vetor de vértices
int pegaVertice(int vert){
    int i=0;

    while(vert!=vetNos[i]){
        i++;
	}
    return i;
}


//encontra o número do grau do vértice
int encontraGrau(int vert){
    int i,grau=0;
    int vertice=pegaVertice(vert);

    for(i=0;i<qtdVert;i++) {
        if(adj[vertice][i] == 1) grau++;
    }
    return grau;
}

//Encontra o ultimo vertice do grafo
int ultimoVertice(int vert){
    int i=0;
    int somaGrau=0;
    for(i=0;i<qtdVert;i++){
        somaGrau=somaGrau+encontraGrau(vetNos[i]);
    }
    if(somaGrau==2){ //Se a soma de todos os graus for 2 quer dizer que só temos um vertice na matriz, portanto é o ultimo vertice
        return 1;
    }else{
        return 0;
    }
}
//pega o proximo vertice do grafo
int proxVertice(int vert){
    int i=0;
    int pos=pegaVertice(vert);

    for(i=0;i<qtdVert;i++){
        if(adj[pos][i] == 1){ //têm aresta
            if(!ehPonte(vetNos[i])){//se não é ponte retorna o vertice
                return vetNos[i];
            }else{
                if(ultimoVertice(vetNos[i])){//se é o ultimo vertice retorna o vertice
                    return vetNos[i];
                }
            }
        }
    }
    return -1; //retorna -1 caso não seja possível obter o prox vertice
}

//verifica se o vértice é uma ponte
int ehPonte(int vert){
    if(encontraGrau(vert)==1){ //se o grau do vertice for 1 pode ser uma ponte
        return 1;
    }else{
        return 0;
    }
}

//verifica se todos os graus são 0, ou seja, foi possível remover todas as arestas
int verificaFimAlgoritmo(){
    int i=0;
    for(i=0;i<qtdVert;i++){
        if(encontraGrau(vetNos[i])>0){
             return 0;
        }
    }
    return 1;
}


//desconecta o vertice raiz do proximo vertice a ser pesquisado
void tiraAresta(int raiz,int conectVert){
     int p1=0,p2=0;

     p1=pegaVertice(raiz);
     p2=pegaVertice(conectVert);
     adj[p1][p2]=0;
     adj[p2][p1]=0;
}


//encontra o circuito euleriano no grafo
void circuitEuler(int raiz){
     int conectVert;

     while(!verificaFimAlgoritmo()){
        conectVert=proxVertice(raiz);   //pega o vertice seguinte que está conectado a raiz
        finalCaminho[caminFim++]=conectVert;     //adiciona o vertice raiz no caminho final
        tiraAresta(raiz,conectVert);   //retira a aresta conectada a raiz e ao proximo vertice
        raiz=conectVert; //o proximo vertice torna-se a nova raiz
     }
}



int raiz(){
    int i,rAtual=1,x;//Assume a raiz como sendo vertice 1, se todos os vertices tiverem grau par qualquer um poderá ser raiz, logo continuará sendo 1

    for(i=0;i<qtdVert;i++){
        if(encontraGrau(vetNos[i])%2!=0){//se o grau não for par soma o contador e coloca-o como raiz atual
            cont++;
            rAtual=i;
        }
    }
    //se o contador for 1 ou maior que dois quer dizer que não é possível ter um caminho euleriao
    if(cont!=0 && cont!=2){
        return 0;
    }
    else{// se 2 vertices exatamente tiverem grau impar teremos um caminho euleriano
        return vetNos[rAtual];
    }
}
