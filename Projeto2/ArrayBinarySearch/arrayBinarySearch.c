#include <stdio.h>
#include <stdlib.h>
#include "arrayBinarySearch.h"

struct _arrayBS {
	int maxSize;
	int currSize;
	int vec[totalSize];
};

arrayBS* createArrayBS(int size){
	arrayBS* newArray = malloc(sizeof(arrayBS));
	newArray->maxSize = size;
	newArray->currSize = 0;
	return newArray;
}	

int insertArrayBS(arrayBS* abs, elem x) {
	if(isFullArrayBS(abs)) 
		return 1;
	
	int pos = 0;
	while(pos < abs->currSize && abs->vec[pos] < x)	pos++;
	
	for(int i = abs->currSize; i > pos; i--){
		abs->vec[i] = abs->vec[i-1]; 
	}

	abs->vec[pos] = x;
	abs->currSize++;

	return 0;
}

int removeArrayBS(arrayBS* abs, elem x){
	if (abs == NULL)
		return 1;
	
	int pos = searchArrayBS(abs, x);
	if(!pos) 
		return 1;
	
	pos--;

	abs->currSize--;
	for(int j = pos; j < abs->currSize; j++){
		abs->vec[j] = abs->vec[j+1];
	}

	return 0;
}

int searchArrayBS(arrayBS* abs, elem x){
	if(abs == NULL)	return -1;

	int left = 0, rigth = abs->currSize-1, mid;

	while(left <= rigth){
		mid = (left+rigth+1) / 2;
		
		if(abs->vec[mid] < x)
			left = mid + 1;
		else if(abs->vec[mid] > x)
			rigth = mid - 1;
		else 
			return mid +1;
	}

	return 0;
}

int isEmptyArrayBS(arrayBS* abs){
	return (abs->currSize == 0);
}

int isFullArrayBS(arrayBS* abs){
	return (abs->currSize == abs->maxSize);
}

void printArrayBS(arrayBS* abs){
	for(int i = 0; i < abs->currSize; i++){
		printf("%d\n", abs->vec[i]);
	}
	printf("\n");
}

void destroyArrayBS(arrayBS* abs){
	if(abs != NULL)
		free(abs);
}