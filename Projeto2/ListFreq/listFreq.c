#include <stdio.h>
#include <stdlib.h>
#include "listFreq.h"

typedef struct _node {
	elem info;
	struct _node *next, *prev;
} node;

struct _listFreq{
	node* start;
	node* end;
	int size;
};

listFreq* createListFreq(){
	listFreq* newListFreq = malloc(sizeof(listFreq));

	if(newListFreq == NULL)	return NULL;

	newListFreq->start = NULL;
	newListFreq->end = NULL;
	newListFreq->size = 0;

	return newListFreq;
}

int insertListFreq(listFreq* lf, elem x){
	node* newNode = malloc(sizeof(node));
	if(newNode == NULL)
		return 1;

	newNode->info = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(isEmptyListFreq(lf)) { //insere primeiro elemento
		lf->start = newNode;
		lf->end = newNode;
		lf->end->next = lf->start;
		lf->start->prev = lf->end;
	} else { //insere no final
		lf->end->next = newNode;
		newNode->prev = lf->end;
		lf->end = newNode;
		lf->end->next = lf->start;
		lf->start->prev = lf->end;
	}
	lf->size++;

	return 0;
}

node* internalSearch(listFreq* lf, elem x){
	node* target = lf->start;

	//busca sequencial, mudando valores quando encontrados
	for (int i = 0; i < lf->size; ++i){
		if(target->info == x){
			//swap dos valores, caso não seja o primeiro
			if(target != lf->start){
				target->info ^= target->prev->info;
				target->prev->info ^= target->info;
				target->info ^= target->prev->info;
			}
			return target;
		}

		target = target->next;
	}

	return NULL;
}

int removeListFreq(listFreq* lf, elem x){
	if(isEmptyListFreq(lf))	return 1;

	//busca elemento para remover
	node* target = internalSearch(lf, x);
	if(target == NULL) return 1;

	if(target == lf->start){ //removendo do inicio
		lf->start = target->next;
		lf->end->next = lf->start;
		lf->start->prev = lf->end;
	} else if(target == lf->end){ //removendo do final
		lf->end = target->prev;
		lf->end->prev = target->prev->prev;
		lf->end->next = lf->start;
	} else{ //removendo do meio
		target->next->prev = target->prev;
		target->prev->next = target->next;
	}
	
	lf->size--;
	free(target);
	return 0;
}

int searchListFreq(listFreq* lf, elem x){
	return (internalSearch(lf, x) != NULL); 
}

int isEmptyListFreq(listFreq* lf){
	return (lf->size == 0);
}

void printListFreq(listFreq* lf){
	node* curr = lf->start;

	for(int i = 0; i < lf->size; i++){
		printf("%d\n", curr->info);
		curr = curr->next;
	}

	printf("\n");
}

void destroyListFreq(listFreq* lf){
	//remove todos os elementos
	while(!isEmptyListFreq(lf)){
		int aux = lf->start->info;
		removeListFreq(lf, aux);
	}

	if(lf != NULL) free(lf);
}
