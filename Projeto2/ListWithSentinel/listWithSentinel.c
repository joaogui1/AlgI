#include <stdio.h>
#include <stdlib.h>
#include "listWithSentinel.h"

listWS* createListWS(){
	listWS* newList = malloc(sizeof(listWS));
	
	if(newList == NULL)
		return NULL;

	newList->start = NULL;
	newList->end = NULL;
	
	return newList;
}

int insertListWS(listWS* l, elem x){
	nodeWS* newNode = malloc(sizeof(nodeWS));
	if(newNode == NULL)
		return 1;

	newNode->info = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(isEmptyListWS(l)) {
		l->start = newNode;
		l->end = newNode;
		
		nodeWS* sentinelaux = malloc(sizeof(nodeWS));
		l->sentinel = sentinelaux;
		l->end->next = l->sentinel;
		l->sentinel->prev = l->end;
	} else {
		nodeWS* position = l->start;
		
		//search position to insert
		while(position != l->sentinel && position->info < x){
			position = position->next;
		}

		//insert in the end of the listWS
		if(position == l->sentinel){
			l->end->next = newNode;
			newNode->next = l->sentinel;
			newNode->prev = l->end;
			l->end = newNode;
		} else { //insert int the start or in the middle
			newNode->prev = position->prev;
			newNode->next = position;
			if(position == l->start) l->start = newNode;
			else position->prev->next = newNode;
			position->prev = newNode;
		}
	}
	
	return 0;
}

int removeListWS(listWS* l, elem x){
	if(isEmptyListWS(l))
		return 1;

	nodeWS* target = l->start;
	
	while(target != l->sentinel && target->info <= x){
		
		//found the element
		if(target->info == x){
			//removing from start
			if(target == l->start){
				l->start = target->next;
				if(l->start != NULL) l->start->prev = NULL;
			} else if(target == l->end){ //removing from end
				l->end = target->prev;
				if(l->end != NULL) l->end->next = l->sentinel;
			} else{ //removing from middle
				target->next->prev = target->prev;
				target->prev->next = target->next;
			}

			free(target);
			return 0;
		}
		
		target = target->next;
	}

	return 1;
}

int searchListWS(listWS* l, elem x){
	nodeWS* target = l->start;
	while(target != l->sentinel && target->info <= x){
		if(target->info == x)
			return 1;
		target = target->next;
	}

	return 0;
}

int isEmptyListWS(listWS* l){
	return (l->start == NULL || l->start == l->sentinel);
}

void printListWS(listWS* l){
	nodeWS* curr = l->start;
	while(curr != l->sentinel) {
		printf("%d [%p] [%p] [%p]\n", curr->info, curr, curr->prev, curr->next);
		curr = curr->next;
	}
	printf("\n");
	return;
}

void destroyListWS(listWS* l){
	
	while(!isEmptyListWS(l)){
		int aux = l->start->info;
		removeListWS(l, aux);
	}
	
	if(l != NULL) {
		free(l->sentinel);
		free(l);
	}
}