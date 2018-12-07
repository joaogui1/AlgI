#ifndef BST_H
#define BST_H

typedef int elem;
typedef struct _bst BST;

/*				Cria estrutura 			       */
/* Parâmetros: - 							   */
/* Retorno: ponteiro para a estrutura	   	   */
BST *createBST();

/*    			Insere elemento			       */
/*Parâmetros: BST* - ponteiro para a struct    */
/*			  elem - valor a ser inserido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int insertBST(BST *t, elem x);

/*				Remove elemento 		         */
/*Parâmetros: BST* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 1, se houver erro, 0 se não     */
int removeBST(BST *t, elem x);

/*				Busca elemento 		   	   	     */
/*Parâmetros: BST* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 0 se não for encontrado, 1 se for */
int searchBST(BST *t, elem x);

/* 		   Printa arvore (para debug)            */
/*Parâmetros: BST* - ponteiro para a struct      */
void printBST(BST* t);

/*	    		Libera memória alocada		     */
/*Parâmetros: BST* - ponteiro para a struct      */
void destroyBST(BST *t);

#endif
