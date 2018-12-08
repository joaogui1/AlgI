#include<stdio.h>
#include<stdlib.h>
#include "BST.h"
#include <time.h>

#define DEBUG 0

int main(int argc, const char *argv[]){

	BST* b = createBST();
	for(int i = 0; i < 1000; i++)
		insertBST(b, i);
	clock_t c = clock();
	for(int i = 0; i < 1000; i++)
		searchBST(b, i);
	c = clock() - c;

	printf("%lf\n", c/(float)CLOCKS_PER_SEC);
	return 0;
}