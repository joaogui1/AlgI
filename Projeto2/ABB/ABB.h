#ifndef TREE_H
#define TREE_H

typedef int elem;
typedef struct _bst BST;

/*				Cria estrutura 			       */
/* Parâmetros: - 							   */
/* Retorno: ponteiro para a estrutura	   	   */
BST *createABB();

/*    			Insere elemento			       */
/*Parâmetros: BST* - ponteiro para a struct    */
/*			  elem - valor a ser inserido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int insertABB(BST *t, elem x);

/*				Remove elemento 		         */
/*Parâmetros: BST* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 1, se houver erro, 0 se não     */
int removeABB(BST *t, elem x);

/*				Busca elemento 		   	   	     */
/*Parâmetros: BST* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 0 se não for encontrado, 1 se for */
int searchABB(BST *t, elem x);

/* 		   Printa arvore (para debug)            */
/*Parâmetros: BST* - ponteiro para a struct      */
void printAbb(BST* t);

/*	    		Libera memória alocada		     */
/*Parâmetros: BST* - ponteiro para a struct      */
void destroyABB(BST *t);

#endif
