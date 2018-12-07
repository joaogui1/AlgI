#ifndef AVL_H
#define AVL_H

typedef int elem;
typedef struct _avl AVL;

/*				Cria estrutura 			       */
/* Parâmetros: - 							   */
/* Retorno: ponteiro para a estrutura	   	   */
AVL *createAVL();

/*    			Insere elemento			       */
/*Parâmetros: AVL* - ponteiro para a struct    */
/*			  elem - valor a ser inserido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int insertAVL(AVL *t, elem x);

/*				Remove elemento 		         */
/*Parâmetros: AVL* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 1, se houver erro, 0 se não     */
int removeAVL(AVL *t, elem x);

/*				Busca elemento 		   	   	     */
/*Parâmetros: AVL* - ponteiro para a struct      */
/*			  elem - valor a ser removido        */
/*Retorno: int - 0 se não for encontrado, 1 se for */
int searchAVL(AVL *t, elem x);

/* 		   Printa arvore (para debug)            */
/*Parâmetros: AVL* - ponteiro para a struct      */
void printAVL(AVL* t);

/*	    		Libera memória alocada		     */
/*Parâmetros: AVL* - ponteiro para a struct      */
void destroyAVL(AVL *t);

#endif
