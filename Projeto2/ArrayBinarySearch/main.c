#include<stdio.h>
#include<stdlib.h>
#include "arrayBinarySearch.h"

#define DEBUG 0

int main(int argc, const char *argv[]){
	arrayBS* abs = createArrayBS(10);
	for(int i = 2; i < 7; i++){
		insertArrayBS(abs, i);
	}

	printArrayBS(abs);
	insertArrayBS(abs, 1);
	printArrayBS(abs);
	printf("\n%d\n", searchArrayBS(abs, 1));
	printf("\n%d\n\n", searchArrayBS(abs, 4));

	removeArrayBS(abs, 3);
	printArrayBS(abs);
	removeArrayBS(abs, 1);
	printArrayBS(abs);
	removeArrayBS(abs, 6);
	printArrayBS(abs);
	removeArrayBS(abs, 6);
	printArrayBS(abs);
	destroyArrayBS(abs);
	
	return 0;
}