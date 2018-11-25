#include<stdio.h>
#include<stdlib.h>
#include "listWithSentinel.h"

#define DEBUG 0

int main(int argc, const char *argv[]){

	listWS* ls = createListWS();

	for(int i = 3; i < 6; i++){
		insertListWS(ls, i);
	}

	printListWS(ls);
	removeListWS(ls, 4);
	printListWS(ls);

	insertListWS(ls, 1);
	insertListWS(ls, 9);
	insertListWS(ls, 4);
	printListWS(ls);

	printf("%d\n", searchListWS(ls, 1));
	printf("%d\n", searchListWS(ls, 5));
	printf("%d\n", searchListWS(ls, 9));
	printf("%d\n", searchListWS(ls, 10));
	printf("%d\n", searchListWS(ls, 2));

	removeListWS(ls, 1);
	removeListWS(ls, 9);
	printListWS(ls);

	destroyListWS(ls);

	return 0;
}