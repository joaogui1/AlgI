#include<stdio.h>
#include<stdlib.h>
#include "list.h"

#define DEBUG 0

int main(int argc, const char *argv[]){

	list* l = createList();
	
	for(int i = 2; i < 7; i++){
		insertList(l, i);
	}
	
	printList(l);
	printf("\n");
	
	insertList(l, 1);
	insertList(l, 9);
	printList(l);
	printf("\n");
	

	insertList(l, 7);
	printList(l);
	printf("\n");

	removeList(l, 1);
	printList(l);
	printf("\n");

	removeList(l, 9);
	printList(l);
	printf("\n");

	removeList(l, 5);
	printList(l);
	printf("\n");

	printf("%d\n", searchList(l, 5));
	printf("%d\n", searchList(l, 2));

	destroyList(l);

	return 0;
}