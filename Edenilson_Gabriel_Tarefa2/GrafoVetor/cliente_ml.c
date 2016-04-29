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
    char *vetor = NULL;
    
    int opcao = -1;

    if(texto == NULL){
        printf("ERRRooo!");
        return -1;
    }
	
	n_vertices = contaCaracteres(texto);
	vetor = inicializaVetor(n_vertices, texto);

    //Menu para o usuario
    while(opcao != 0){
        printf("Informe a opcao desejada:\n");
        printf("1: Mostrar Grafo\n");
        printf("0: Sair\n");
        scanf("%i", &opcao);
        switch (opcao){
        case 1:
            system("cls");
            imprimeVetor(n_vertices, vetor);
            system("PAUSE");
            break;
        
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");

        }
        printf("\n");
        system("cls");
    }
    
    fclose(texto);

    return 0;
}


int contaCaracteres(FILE *f){
    char c = NULL;
    int cont = 0, i = 0, n = 1;

    //Conta o numero de caracteres e de linhas do arquivo
    while((c = fgetc(f)) != EOF){
        cont++;
        if(c == '\n'){
            n++;
        }
    }

    rewind(f);
 

    return cont;
}

char *inicializaVetor(int cont, FILE *f){
	char c = NULL;
	char *p = NULL;
	int i = 0;
	p = (char*)malloc(1+cont*sizeof(char));

    //cria um vetor com o conteudo do arquivo
    while((c = fgetc(f)) != EOF){
        p[i]=c;
        i++;
    }
    p[i]='\0';  
    
    return p;
}

void imprimeVetor(int n, char *p){
    int l = 0;
    
    for(l = 0; l < n; l++){
    	printf("%c", p[l]);
	}
	
	printf("\n");
}


