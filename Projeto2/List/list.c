#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _node {
	elem info;
	struct _node *next, *prev;
} node;

struct _list {
	node* start;
	node* end;
};

list* createList(){
	list* newList = malloc(sizeof(list));
	
	if(newList == NULL)
		return NULL;

	newList->start = NULL;
	newList->end = NULL;
	
	return newList;
}

node* createNode(elem x){
	node* newNode = malloc(sizeof(node));
	if(newNode == NULL) 
		return NULL;
	newNode->info = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

node* internalSearch(list* l, elem x){
	node* target = l->start;
	
	while(target != NULL && target->info <= x){
		if(target->info == x)
			return target;
		target = target->next;
	}

	return target;
}

int searchList(list* l, elem x){
	node* n = internalSearch(l, x);
	return (n != NULL && n->info == x);
}

int insertList(list* l, elem x){
	node* newNode = createNode(x);
	
	if(newNode == NULL)
		return 1;

	if(isEmptyList(l)) {
		l->start = newNode;
		l->end = newNode;
	} else {
		node* position = internalSearch(l, x);

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

	node* target = internalSearch(l, x);
	
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

	return 1;
}

int isEmptyList(list* l){
	return (l->start == NULL);
}

void printList(list* l){
	node* curr = l->start;
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