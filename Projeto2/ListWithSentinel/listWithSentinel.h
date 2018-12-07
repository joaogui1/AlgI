#ifndef LISTWS_H
#define LISTWS_H

typedef int elem;
typedef struct _listWS listWS;

/*				Cria estrutura 			       */
/* Parâmetros: - 							   */
/* Retorno: ponteiro para a estrutura	   	   */
listWS* createListWS();

/*    			Insere elemento			       */
/*Parâmetros: listWS* - ponteiro para a struct */
/*			  elem - valor a ser inserido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int insertListWS(listWS* ls, elem x);

/*				Remove elemento 		       */
/*Parâmetros: listWS* - ponteiro para a struct */
/*			  elem - valor a ser removido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int removeListWS(listWS* ls, elem x);

/*				Busca elemento 		   	   	   */
/*Parâmetros: listWS* - ponteiro para a struct */
/*			  elem - valor a ser removido      */
/*Retorno: int - 0 se não for encontrado, 1 se for */
int searchListWS(listWS* ls, elem x);

/*			   Lista está vazio				   */
/*Parâmetros: listWS* - ponteiro para a struct */
/*Retorno: int - 1, se estiver vazio, 0 se não */
int isEmptyListWS(listWS* ls);

/*			   Printa lista (para debug)       */
/*Parâmetros: listWS* - ponteiro para a struct */
void printListWS(listWS* ls);

/*	    		Libera memória alocada		   */
/*Parâmetros: listWS* - ponteiro para a struct */
void destroyListWS(listWS* ls);

#endif