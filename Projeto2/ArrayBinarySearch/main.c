#include<stdio.h>
#include<stdlib.h>
#include "arrayBinarySearch.h"

#define DEBUG 0

int main(int argc, const char *argv[]){
	arrayBS* abs = createArrayBS(10);
	for(int i = 100001; i > 1; i--){
		insertArrayBS(abs, i);
	}
	for(int i = 100001; i > 1; i--){
		searchArrayBS(abs, i);
	}
	printf("ok\n");
	
	return 0;
}