#include <stdio.h>
#include <stdlib.h>
#include "listFreq.h"

#define DEBUG 0

int main(int argc, const char *argv[]){

	listFreq* lf = createListFreq();
	for(int i = 2; i < 7; i++){
		insertListFreq(lf, i);
	}

	insertListFreq(lf, 9);
	printListFreq(lf);
	insertListFreq(lf, 8);
	printListFreq(lf);
	insertListFreq(lf, 1);
	printListFreq(lf);

	removeListFreq(lf, 1);
	printListFreq(lf);
	removeListFreq(lf, 9);
	printListFreq(lf);
	removeListFreq(lf, 5);
	printListFreq(lf);

	printf("%d\n\n", searchListFreq(lf, 1));
	printListFreq(lf);
	printf("%d\n\n", searchListFreq(lf, 2));
	printListFreq(lf);
	printf("%d\n\n", searchListFreq(lf, 6));
	printListFreq(lf);
	printf("%d\n\n", searchListFreq(lf, 6));
	printListFreq(lf);

	destroyListFreq(lf);

	return 0;
}