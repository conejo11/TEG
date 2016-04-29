//----------------------------------------------//
//Universidade do Estado de Santa Catarina - UDESC
//Centro de Ciências Tecnológicas - CCT
//Disciplina: Teoria dos Grafos
//Professor: Omir Correa Alves Junior
//Acadêmicos: Edenilson Jonatas dos Passos
//            Gabriel Conejo
//-------------------------------------------//

#include "LDDE_priv.h"

/*************** CRIA ***************/
int cria(ppLDDE pp, int tamInfo)
{   int ret = FRACASSO;
	if(((*pp)=(pLDDE)malloc(sizeof(LDDE)))==NULL)
		ret = FRACASSO;
	else
	{	(*pp)->lista=NULL;
        	(*pp)->tamInfo=tamInfo;
        	ret = SUCESSO;
	}
    	return ret;
}

/*************** INSERE NO INICIO ***************/
int insereNoInicio(pLDDE p, void *novo)
{	pNoLDDE temp;
   	int ret = FRACASSO;
	if((temp=(NoLDDE *)malloc(sizeof(NoLDDE)))!=NULL)
	{ if((temp->dados = (void *) malloc(p->tamInfo)) !=NULL )
		{	memcpy(temp->dados,novo,p->tamInfo);
 		 	temp->prox=p->lista;
         		temp->ant = NULL;
       	 		if(p->lista != NULL)
            			p->lista->ant=temp;
         		p->lista=temp;
         		ret = SUCESSO;
     		}
     		else
       			free(temp);
	}
   	return ret;
}

/*************** INSERE NO FINAL ***************/
int insereNoFim(pLDDE p, void *novo)
{ 	pNoLDDE temp, aux;
	int ret = FRACASSO;
	if((temp=(pNoLDDE)malloc(sizeof(NoLDDE)))!= NULL)
	{ if((temp->dados = (void *) malloc(p->tamInfo))!=NULL)
	     {   memcpy(temp->dados,novo,p->tamInfo);
        	 temp->prox = NULL;
		 if(p->lista==NULL)
		 {	p->lista=temp;
        		temp->ant=NULL;
		 }
		 else
		 {	aux=p->lista;
			while(aux->prox!=NULL)
				aux=aux->prox;
			aux->prox=temp;
			temp->ant=aux;
		 }
         	ret = SUCESSO;
     }
     else
      	free(temp);
   }
   return ret;
}

/*************** INSERE NA POSIÇÃO LÓGICA ***************/
int insereNaPosLog (pLDDE p, void *novo, unsigned int posLog)
{ pNoLDDE temp, pos;
  unsigned int cont=0, ret=FRACASSO;
  if( p->lista != NULL && posLog > 0)
  { cont = 1;
    if((temp = (pNoLDDE) malloc(sizeof(NoLDDE)))!=NULL){
      if((temp->dados = (void *) malloc(p->tamInfo))!=NULL)
      {	memcpy(temp->dados,novo,p->tamInfo);
      	if(posLog == cont)/*PosLog == 1: inserção de um novo primeiro elemento*/
      	 {  	temp->prox = p->lista;
            	p->lista->ant = temp;
            	temp->ant = NULL;
		p->lista = temp;
           	ret = SUCESSO;
         }
         else /* posLog >= 2, no minimo igual a dois */
         {  pos = p->lista->prox;/*pos:apontara p/ no de dados na posLog==cont*/
           	if (pos != NULL)
				{    cont = 2;
                 while(cont < posLog && pos->prox != NULL)/*1<posLog<=tam.dalista*/
                 {  pos = pos->prox;
                    cont++;
                 }
                 if (cont == posLog)
                	{   	temp->prox=pos;
                        	temp->ant = pos->ant;
                        	pos->ant->prox = temp;
				pos->ant= temp;
                   	    	ret = SUCESSO;
                 	}
             }
         }
      }
      }else{
         free(temp);
	}
  }
  return ret;/*posLog nao existe na lista: lista vazia ou PosLog>tamLista*/
}

/*************** REMOVE DO INICIO ***************/
int removeDoInicio(pLDDE p, void *reg)
{  	int ret = FRACASSO;
	if(p->lista != NULL)
	{	memcpy(reg,p->lista->dados,p->tamInfo);
     	   	free(p->lista->dados);
	   	if(p->lista->prox==NULL)
		{	free(p->lista);
			p->lista=NULL;
		}
		else
      		{	p->lista=p->lista->prox;
			free(p->lista->ant);
			p->lista->ant=NULL;
      		}
      		ret = SUCESSO;
	}
   	return ret;
}


/*************** REMOVE DO FINAL ***************/
int removeDoFim(pLDDE p, void *reg)
{	pNoLDDE aux;
	int ret = FRACASSO;
	if(p->lista != NULL)
	{	aux=p->lista;
		while(aux->prox != NULL)
			aux=aux->prox;
            memcpy(reg,aux->dados,p->tamInfo);
         	free(aux->dados);
         	if(aux->ant != NULL)
	        	aux->ant->prox=NULL; /*há mais de 1 item na lista e aux aponta p/ o último*/
         	else
             		p->lista = NULL; /*há apenas um elemento na lista*/
         	free (aux);
		ret = SUCESSO;
	}
   	return ret;

}

/*************** REMOVE DA POSIÇÃO LÓGICA ***************/
int removeDaPosLog(pLDDE p, void *reg, unsigned int posLog)
{	pNoLDDE pos;
	unsigned int cont=0, ret = FRACASSO;
   	if( p->lista != NULL && posLog > 0)
   	{ 	cont = 1;
     		if(posLog == cont)/*PosLog == 1: inserção de um novo primeiro elemento*/
     			ret = removeDoInicio(p, reg);
	     	else   /* posLog > 1, no minimo igual a dois */
		{	pos = p->lista->prox;/*pos:apontara p/ no de dados na posLog==cont*/
        		if (pos != NULL)
			{    	cont = 2;
              			while(cont < posLog && pos->prox != NULL)/*1<posLog<=tam.dalista*/
              			{  	pos = pos->prox;
                 			cont++;
              			}
              			if (cont == posLog) /* encontrou a posLog ? */
             			{	if(pos->prox != NULL)/*posLog eh aa do ultimo elemento ?*/
                       				pos->prox->ant = pos->ant;
                  			pos->ant->prox = pos->prox;
                            memcpy(reg,pos->dados,p->tamInfo);
                  			free(pos->dados);
                  			free(pos);
                  			ret = SUCESSO;
              			}
           		}
     		}
    	}
    	return ret;/*posLog nao existe na lista*/
}


/*************** BUSCA NO INICIO ***************/
int buscaNoInicio(pLDDE p, void *reg)
{  int ret = FRACASSO;
   if(p->lista != NULL)
	{ 	memcpy(reg,p->lista->dados,p->tamInfo);
      		ret = SUCESSO;
	}
   return ret;
}


/*************** BUSCA NO FINAL ***************/
int buscaNoFim(pLDDE p, void *reg)
{	pNoLDDE aux;
	int ret = FRACASSO;
	if(p->lista != NULL)
	{	aux=p->lista;
	  	while(aux->prox!=NULL)
      	   		aux=aux->prox;
	  	memcpy(reg,aux->dados,p->tamInfo);
      		ret = SUCESSO;
	}
   	return ret;
}

/*************** BUSCA NA POSIÇÃO LÓGICA ***************/
int buscaNaPosLog(pLDDE p, void *reg, unsigned int posLog)
{	int cont, ret = FRACASSO;
	pNoLDDE pos;
	if(p->lista != NULL && posLog > 0)
	{	cont = 1;
		pos = p->lista;
		while(cont < posLog && pos->prox != NULL )
		{  	pos = pos->prox;
        		cont++;
		}
		if(cont == posLog)
             	{	memcpy(reg,pos->dados,p->tamInfo);
              		ret = SUCESSO;
		}
	}
	return ret;
}

/*************** TAMANHO ***************/
int tamanho(pLDDE p)
{ int tam=0;
  pNoLDDE aux;
  aux=p->lista;
  if(aux==NULL)
    tam=0;
  else
  { while(aux!=NULL)
    { 	aux=aux->prox;
	tam++;
    }
  }
  return tam;
}

/*************** PURGA ***************/
void reinicia(pLDDE p)
{	if(p->lista != NULL)
	{	while(p->lista->prox != NULL)
		{	p->lista=p->lista->prox;
        		free(p->lista->ant->dados);
		 	free(p->lista->ant);
		}
	   	free(p->lista->dados);
     		free(p->lista);
      		p->lista = NULL;
	}
}

/*************** DESTROI ***************/
void destroi(ppLDDE pp)
{
	reinicia(*pp);
	free(*pp);
	(*pp)=NULL;
}

/*
int enderecosFisicos(pLDDE p)
{    pNoLDDE aux;

     if(p->lista != NULL)
	 {	printf("tamanho de cada no: %u bytes\n",p->tamInfo);
        	aux = p->lista;
        	while(aux != NULL)
		{	printf("endereco %X \n",(unsigned int)aux);
		        aux = aux->prox;
        	}
        	if(p->lista->prox)
        		  printf("distancia entre nos: %X \n",p->lista - p->lista->prox);
	        return SUCESSO;
     	}
    else
       return FRACASSO;
}
*/

