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

	destroyListWS(ls);

	return 0;
}