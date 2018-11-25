#include <stdio.h>
#include <stdlib.h>
#include "listFreq.h"

listFreq* createListFreq(){
	listFreq* newListFreq = malloc(sizeof(listFreq));
	
	if(newListFreq == NULL)
		return NULL;

	newListFreq->start = NULL;
	newListFreq->end = NULL;
	newListFreq->size = 0;

	return newListFreq;
}

int insertListFreq(listFreq* lf, elem x){
	nodeLF* newNode = malloc(sizeof(nodeLF));
	if(newNode == NULL)
		return 1;

	newNode->info = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(isEmptyListFreq(lf)) {
		lf->start = newNode;
		lf->end = newNode;
		lf->end->next = lf->start;
		lf->start->prev = lf->end;
	} else {
		lf->end->next = newNode;
		newNode->prev = lf->end;
		lf->end = newNode;
		lf->end->next = lf->start;
		lf->start->prev = lf->end;
	}
	lf->size++;
	
	return 0;
}

int removeListFreq(listFreq* lf, elem x){
	if(isEmptyListFreq(lf))
		return 1;

	nodeLF* target = lf->start;

	for(int i = 0; i < lf->size; i++){
		if(target->info == x){
			//removing from start
			if(target == lf->start){
				lf->start = target->next;
				lf->end->next = lf->start;
				lf->start->prev = lf->end;
			} else if(target == lf->end){ //removing from end
				lf->end = target->prev;
				lf->end->prev = lf->start;
				lf->end->next = lf->start;
			} else{ //removing from middle
				target->next->prev = target->prev;
				target->prev->next = target->next;
			}
			lf->size--;
			free(target);
			return 0;
		}
		target = target->next;
	}

	return 1;
}

int searchListFreq(listFreq* lf, elem x){
	nodeLF* target = lf->start;
	
	for (int i = 0; i < lf->size; ++i){
		if(target->info == x){
			//swap values
			if(target != lf->start){
				target->info ^= target->prev->info;
				target->prev->info ^= target->info;
				target->info ^= target->prev->info;
			}
			return 1;
		}
		
		target = target->next;
	}

	return 0;
}

int isEmptyListFreq(listFreq* lf){
	return (lf->size == 0);
}

void printListFreq(listFreq* lf){
	nodeLF* curr = lf->start;
	
	for(int i = 0; i < lf->size; i++){
		printf("%d [%p] [%p] [%p]\n", curr->info, curr, curr->prev, curr->next);
		curr = curr->next;
	}

	printf("\n");
}

void destroyListFreq(listFreq* lf){
	while(!isEmptyListFreq(lf)){
		int aux = lf->start->info;
		removeListFreq(lf, aux);
	}

	if(lf != NULL) free(lf);
}