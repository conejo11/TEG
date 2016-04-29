//----------------------------------------------//
//Universidade do Estado de Santa Catarina - UDESC
//Centro de Ciências Tecnológicas - CCT
//Disciplina: Teoria dos Grafos
//Professor: Omir Correa Alves Junior
//Acadêmicos: Edenilson Jonatas dos Passos
//            Gabriel Conejo
//-------------------------------------------//

#include"cliente_ml.h"
#define SUCESSO 1
#define FRACASSO 0

int main(){
    FILE *texto = fopen("arquivo.txt","r");
    int n_vertices = 0;
    char *ligacoes;
    pLDDE lista = NULL;
    int opcao = -1;

    if(texto == NULL){
        printf("ERRRooo!");
        return -1;
    }

    n_vertices = carregaArquivo(texto, &ligacoes);

    lista = inicializaLista(ligacoes, n_vertices);

    //Menu para o usuario
    while(opcao!=0){
        printf("Informe a opcao desejada:\n");
        printf("1: Mostrar Grafo\n");
        printf("0: Sair\n");
        scanf("%i", &opcao);
        switch (opcao){
        case 1:
            mostraLista(lista, n_vertices);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");

        }
        printf("\n");
    }

    //finaliza o programa: atualiza o arquivo, destroi as listas e fecha o arquivo
    fclose(texto);
    destroiListas(&lista);

    return 0;
}

int carregaArquivo(FILE *f, char **p){
    char c;
    int cont = 0, i=0, n=1;

    //Conta o numero de caracteres e de linhas do arquivo
    while((c = fgetc(f)) != EOF){
        cont++;
        if(c == '\n'){
            n++;
        }
    }

    rewind(f);

    *p = (char*)malloc(1+cont*sizeof(char));

    //cria um vetor com o conteudo do arquivo
    while((c = fgetc(f)) != EOF){
        (*p)[i]=c;
        i++;
    }
    (*p)[i]='\0';

    return n;
}

pLDDE inicializaLista(char *p, int n_vertices){
    pLDDE l = NULL;
    int i;

    //Cria a lista principal, onde tamInfo é o tamanho de um ppLDDE
    if(cria(&l, sizeof(ppLDDE))!=SUCESSO){
        printf("Erro ao criar lista principal\n");
        exit(EXIT_FAILURE);
    }
    //Cria as listas internas, adicionando-as ao fim da lista principal
    for(i=0; i<n_vertices;i++){
        pLDDE sub = criaSubLista(p, i);
        insereNoFim(l, &sub);
    }

    return l;

}

pLDDE criaSubLista(char *p, int linha){
    pLDDE temp = NULL;
    pPalavra pl = NULL;
    char t[50];
    int i, k, l=0, col_inicial, coluna;
    int esp=0, pos=0;

    if(cria(&temp, sizeof(Palavra))!=SUCESSO){ //Inicializa a sublista
        printf("Erro ao criar sublista\n");
        exit(EXIT_FAILURE);
    }
    pl = (pPalavra)malloc(sizeof(Palavra));
    if(!pl){
        printf("Erro ao criar palavra\n");
        exit(EXIT_FAILURE);
    }
    pl->linha = linha;


    for(k=0;l<linha;k++){ //encontra no vetor a linha que vai ser inserida na lista
        if(p[k]=='\n'){
            l++;
        }
    }

    //p é um vetor que contem todo o conteúdo do arquivo em uma única linha
    //esse trecho do código varre uma linha do arquivo (até encontrar '\n' no vetor), procura os vértices e adiciona à uma lista de vértices temporária

    //esp igual a 1 inidica que o caracter atual é diferente de espaço, e é inicializado em 0
    col_inicial=k;
    while(p[k]!='\n'&&p[k]!='\0'){
        if(p[k]!=' '&&esp==0){                          //encontrou o início de um vértice
            coluna=k-col_inicial;                       //calcula a coluna inicial do vértice (col_inicial é a coluna inicial da linha)
            pl -> coluna = coluna;
            esp=1;                                      //indica que está em um vértice
            pos=0;                                      //pos é a posição no vetor temporário para o qual o vértice vai ser copiado
        }
        if(esp==1){
            if(p[k]==' '||p[k+1]=='\n'||p[k+1]=='\0'){  //o vértice acabou
                esp=0; //zera o esp
                if(p[k+1]=='\n'||p[k+1]=='\0'){         //exceção pra caso estar no final da linha ou do vetor
                    t[pos]=p[k];
                    t[pos+1]='\0';
                }
                else{
                    t[pos]='\0';
                }
                //printf("%s\n", t);
                strcpy(pl->palavra, t);                 //copia o vetor temporário para a struct

                //printf("%i %i %s\n", pl->linha, pl->coluna, pl->palavra);


                if(insereNoFim(temp, pl)!=SUCESSO){     //insere a struct na ista
                    printf("Erro ao inserir elemento na sublista\n");
                    exit(EXIT_FAILURE);
                }

                //buscaNoFim(temp, teste);
                //printf("%i %i %s\n", teste->linha, teste->coluna, teste->palavra);

                for(i=0;i<pos;i++){                     //reseta o vetor temporário
                    t[i]='\0';
                }
                pos=0;
            }
            else{                                       //continua lendo os vértices
                t[pos]=p[k];
                pos++;
            }
        }
        k++;
    }

    return temp;                                        //retorna a lista temporária pra ser inserida na lista mãe
}

void mostraLista(pLDDE p, int linha){
    int i, j;
    pPalavra pl=NULL;

    pl=(pPalavra)malloc(sizeof(Palavra));

    //varre as listas, mostrando os vértices
    for(i=0;i<linha;i++){
        pLDDE l=NULL;
        buscaNaPosLog(p, &l, i+1);
        for(j=0;(buscaNaPosLog(l, pl, j+1)==SUCESSO);j++){
            printf(" %s ", pl->palavra);
        }
        printf("\n");
    }

    free(pl);

}


void destroiListas(ppLDDE pp){
    int tam, i;

    tam=tamanho(*pp);

    //remove todas as listas internas
    for(i=0;i<tam;i++){
        pLDDE l;
        removeDoFim((*pp), &l);
    }

    //detroi a lista principal
    destroi(pp);
}



