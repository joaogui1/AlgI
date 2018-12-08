#include <stdio.h>
#include <stdlib.h>
#include "arrayBinarySearch.h"

#define DEBUG 0

int main(int argc, const char *argv[]){

	arrayBS* a = createArrayBS(100);

	for(int i = 0; i < 10; i++)
		printf("%d\n\n", insertArrayBS(a, i));

	printArrayBS(a);
	destroyArrayBS(a);

	return 0;
}