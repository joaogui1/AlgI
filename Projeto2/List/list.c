#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list* createList(){
	list* newList = malloc(sizeof(list));
	
	if(newList == NULL)
		return NULL;

	newList->start = NULL;
	newList->end = NULL;
	
	return newList;
}

int insertList(list* l, elem x){
	nodeL* newNode = malloc(sizeof(nodeL));
	if(newNode == NULL)
		return 1;

	newNode->info = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(isEmptyList(l)) {
		l->start = newNode;
		l->end = newNode;
	} else {
		nodeL* position = l->start;
		
		//search position to insert
		while(position != NULL && position->info < x){
			position = position->next;
		}

		//insert in the end of the list
		if(position == NULL){
			l->end->next = newNode;
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

int removeList(list* l, elem x){
	if(isEmptyList(l))
		return 1;

	nodeL* target = l->start;
	
	while(target != NULL && target->info <= x){
		
		//found the element
		if(target->info == x){
			//removing from start
			if(target == l->start){
				l->start = target->next;
				if(l->start != NULL) l->start->prev = NULL;
			} else if(target == l->end){ //removing from end
				l->end = target->prev;
				if(l->end != NULL) l->end->next = NULL;
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

int searchList(list* l, elem x){
	nodeL* target = l->start;
	while(target != NULL && target->info <= x){
		if(target->info == x)
			return 1;
		target = target->next;
	}

	return 0;
}

int isEmptyList(list* l){
	return (l->start == NULL);
}

void printList(list* l){
	nodeL* curr = l->start;
	while(curr != NULL){
		printf("%d [%p] [%p] [%p]\n", curr->info, curr, curr->prev, curr->next);
		curr = curr->next;
	}
	printf("\n");
	return;
}

void destroyList(list* l){
	while(!isEmptyList(l)){
		int aux = l->start->info;
		removeList(l, aux);
	}

	if(l != NULL) free(l);
}