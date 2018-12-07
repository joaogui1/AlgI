#include <stdio.h>
#include <stdlib.h>
#include "listWithSentinel.h"

typedef struct _node {
	elem info;
	struct _node *next, *prev;
} node;

struct _listWS {
	node* start;
	node* end;
	node* sentinel;
};

listWS* createListWS(){
	listWS* newList = malloc(sizeof(listWS));
	if(newList == NULL) return NULL;

	newList->start = NULL;
	newList->end = NULL;
	newList->sentinel = NULL;

	return newList;
}

//percorre toda lista, buscando o valor
node* internal_search(listWS* ls, elem x){
	node* target = ls->start;
	//valor do sentinela é o que está sendo buscado
	ls->sentinel->info = x;

	while(target->info < x){
		target = target->next;
	}

	return target;
}

int searchListWS(listWS* ls, elem x){
	if(ls == NULL) return 0;
	//se o valor estiver no sentinela, não foi encontrado
	return (internal_search(ls, x) != ls->sentinel);
}

// muda ponteiros para a inserção
int insertListWS(listWS* ls, elem x){
	node* newNode = malloc(sizeof(node));
	if(newNode == NULL)	return 1;

	newNode->info = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	//cria ponteiros na primeira inserção
	if(isEmptyListWS(ls)){
		ls->start = newNode;
		ls->end = newNode;

		node* sentinelaux = malloc(sizeof(node));
		ls->sentinel = sentinelaux;
		ls->end->next = ls->sentinel;
		ls->sentinel->prev = ls->end;
	} else {
		//busca posição e insere
		node* position = internal_search(ls, x);
		newNode->prev = position->prev;
		newNode->next = position;
		
		if(position == ls->start) 
			ls->start = newNode;
		else 
			position->prev->next = newNode;
		
		if(position == ls->sentinel){
			newNode->next = ls->sentinel;
			ls->end = newNode;
		}
		position->prev = newNode;
	}

	return 0;
}

int removeListWS(listWS* ls, elem x){
	if(isEmptyListWS(ls)) return 1;

	node* target = internal_search(ls, x);
	//se valor estiver no sentila, não foi encontrado
	if(target == ls->sentinel) return 1;

	if(target == ls->start){ //removendo do inicio
		ls->start = target->next;
		ls->start->prev = NULL;
	} else if(target == ls->end){ //removendo do final
		ls->end = target->prev;
		ls->end->next = ls->sentinel;
	} else{ //removendo do meio
		target->next->prev = target->prev;
		target->prev->next = target->next;
	}
	free(target);
	return 0;
}


int isEmptyListWS(listWS* ls){
	return (ls->start == ls->sentinel);
}

void printListWS(listWS* ls){
	node* curr = ls->start;
	while(curr != ls->sentinel) {
		printf("%d\n", curr->info);
		curr = curr->next;
	}
	printf("\n");
	return;
}

void destroyListWS(listWS* ls){
	//remove todos os elementos
	while(!isEmptyListWS(ls)){
		int aux = ls->start->info;
		removeListWS(ls, aux);
	}

	//libera memoria restante
	if(ls != NULL) {
		free(ls->sentinel);
		free(ls);
	}
	return;
}