#include<stdio.h>
#include<stdlib.h>
#include "arrayBinarySearch.h"

#define DEBUG 0

int main(int argc, const char *argv[]){
	arrayBS* abs = createArrayBS(10);
	for(int i = 2; i < 7; i++){
		insertArrayBS(abs, i);
	}

	insertArrayBS(abs, 1);
	printArrayBS(abs);
	
	insertArrayBS(abs, 10);
	printArrayBS(abs);

	insertArrayBS(abs, 8);
	printArrayBS(abs);

	destroyArrayBS(abs);insertArrayBS(abs, 10);
	printArrayBS(abs);
	
	return 0;
}