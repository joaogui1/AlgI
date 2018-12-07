#ifndef LISTFREQ_H
#define LISTFREQ_H

typedef int elem;
typedef struct _listFreq listFreq;

/*				Cria estrutura 			         */
/* Parâmetros: - 							     */
/* Retorno: ponteiro para a estrutura	   	     */
listFreq* createListFreq();

/*    			Insere elemento			         */
/*Parâmetros: listFreq* - ponteiro para a struct */
/*			  elem - valor a ser inserido        */
/*Retorno: int - 1, se houver erro, 0 se não     */
int insertListFreq(listFreq* l, elem x);

/*				Remove elemento 		         */
/*Parâmetros: listFreq* - ponteiro para a struct */
/*			  elem - valor a ser removido        */
/*Retorno: int - 1, se houver erro, 0 se não     */
int removeListFreq(listFreq* l, elem x);

/*				Busca elemento 		   	   	     */
/*Parâmetros: listFreq* - ponteiro para a struct */
/*			  elem - valor a ser removido        */
/*Retorno: int - 0 se não for encontrado, 1 se for */
int searchListFreq(listFreq* l, elem x);

/*			   Lista está vazio				     */
/*Parâmetros: listFreq* - ponteiro para a struct */
/*Retorno: int - 1, se estiver vazio, 0 se não   */
int isEmptyListFreq(listFreq* l);

/*			   Printa lista (para debug)         */
/*Parâmetros: listFreq* - ponteiro para a struct */
void printListFreq(listFreq* l);

/*	    		Libera memória alocada		     */
/*Parâmetros: listFreq* - ponteiro para a struct */
void destroyListFreq(listFreq* l);

#endif