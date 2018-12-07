#ifndef LIST_H
#define LIST_H

typedef int elem;
typedef struct _list list;

/*				Cria estrutura 			       */
/* Parâmetros: - 							   */
/* Retorno: ponteiro para a estrutura	   	   */
list* createList();

/*    			Insere elemento			       */
/*Parâmetros: list* - ponteiro para a struct   */
/*			  elem - valor a ser inserido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int insertList(list* l, elem x);

/*				Remove elemento 		       */
/*Parâmetros: list* - ponteiro para a struct   */
/*			  elem - valor a ser removido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int removeList(list* l, elem x);

/*				Busca elemento 		   	   	   */
/*Parâmetros: list* - ponteiro para a struct   */
/*			  elem - valor a ser removido      */
/*Retorno: int - 0 se não for encontrado, 1 se for */
int searchList(list* l, elem x);

/*			   Lista está vazio				   */
/*Parâmetros: list* - ponteiro para a struct   */
/*Retorno: int - 1, se estiver vazio, 0 se não */
int isEmptyList(list* l);

/*			   Printa lista (para debug)       */
/*Parâmetros: list* - ponteiro para a struct   */
void printList(list* l);

/*	    		Libera memória alocada		   */
/*Parâmetros: list* - ponteiro para a struct   */
void destroyList(list* l);

#endif