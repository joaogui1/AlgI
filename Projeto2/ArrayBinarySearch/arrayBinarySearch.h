#ifndef ARRAYBS_H
#define ARRAYBS_H	

#define totalSize 101005

typedef int elem;
typedef struct _arrayBS arrayBS;

/*				Cria estrutura 			       */
/* Parâmetros: int - tamanho do vetor	   	   */
/* Retorno: ponteiro para a estrutura	   	   */
arrayBS* createArrayBS(int size);

/*    			Insere elemento			       */
/*Parâmetros: arrayBS* - ponteiro para a struct*/
/*			  elem - valor a ser inserido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int insertArrayBS(arrayBS* abs, elem x);

/*				Remove elemento 		       */
/*Parâmetros: arrayBS* - ponteiro para a struct*/
/*			  elem - valor a ser removido      */
/*Retorno: int - 1, se houver erro, 0 se não   */
int removeArrayBS(arrayBS* abs, elem x);


/*				Busca elemento 		   	   	   */
/*Parâmetros: arrayBS* - ponteiro para a struct*/
/*			  elem - valor a ser removido      */
/*Retorno: int - 0 se não for encontrado, (pos + 1), caso contrario  */
int searchArrayBS(arrayBS* abs, elem x);

/*			   Vetor está vazio				   */
/*Parâmetros: arrayBS* - ponteiro para a struct*/
/*Retorno: int - 1, se estiver vazio, 0 se não */
int isEmptyArrayBS(arrayBS* abs);

/*			   Vetor está cheio				   */
/*Parâmetros: arrayBS* - ponteiro para a struct*/
/*Retorno: int - 1, se estiver cheio, 0 se não */
int isFullArrayBS(arrayBS* abs);

/*			   Printa vetor (para debug)       */
/*Parâmetros: arrayBS* - ponteiro para a struct*/
void printArrayBS(arrayBS* abs);

/*	    		Libera memória alocada		*/
/*Parâmetros: arrayBS* - ponteiro para a struct*/
void destroyArrayBS(arrayBS* abs);

#endif