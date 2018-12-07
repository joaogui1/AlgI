#ifndef TREE_H
#define TREE_H

typedef int elem;
typedef struct _abb ABB;

/*				Cria estrutura 			       */
/* Parâmetros: - 							   */
/* Retorno: ponteiro para a estrutura	   	   */
ABB *createABB();

/*    			Insere elemento			       */
/*Parâmetros: ABB* - ponteiro para a struct    */
/*			  elem - valor a ser inserido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int insertABB(ABB *t, elem x);

/*				Remove elemento 		         */
/*Parâmetros: ABB* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 1, se houver erro, 0 se não     */
int removeABB(ABB *t, elem x);

/*				Busca elemento 		   	   	     */
/*Parâmetros: ABB* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 0 se não for encontrado, 1 se for */
int searchABB(ABB *t, elem x);

/* 		   Printa arvore (para debug)            */
/*Parâmetros: ABB* - ponteiro para a struct      */
void printAbb(ABB* t);

/*	    		Libera memória alocada		     */
/*Parâmetros: ABB* - ponteiro para a struct      */
void destroyABB(ABB *t);

#endif
