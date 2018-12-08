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
int lowerBound(arrayBS* abs, elem x){
	if(abs == NULL)	return -1;

	//busca binaria no vetor
	int left = 0, right = abs->currSize-1, mid = 0;
	while(left < right){
		mid = (left + right + 1)/ 2;

		if(abs->vec[mid] < x)
		left = mid;
		else if(abs->vec[mid] > x)
		right = mid - 1;
	}

	return mid;
}

int insertArrayBS(arrayBS* abs, elem x) {
	if(isFullArrayBS(abs))
		return 1;

	//procura posição para inserir
	int pos = lowerBound(abs, x) + 1;
	// printf("pos %d\n", pos);
	// while(pos < abs->currSize && abs->vec[pos] < x)
		// pos++;

	//shift do vetor para inserir na posição correta
	for(int i = abs->currSize; i > pos; i--){
		abs->vec[i] = abs->vec[i-1];
	}

	abs->vec[pos] = x;
	abs->currSize++;

	return 0;
}

int removeArrayBS(arrayBS* abs, elem x){
	if (abs == NULL) return 1;

	//busca elemento para remover
	int pos = searchArrayBS(abs, x);
	if(pos == 0) return 1;
	pos--;

	//remove elemento e faz shift do resto do vetor
	abs->currSize--;
	for(int j = pos; j < abs->currSize; j++){
		abs->vec[j] = abs->vec[j+1];
	}

	return 0;
}


int searchArrayBS(arrayBS* abs, elem x){
	if(abs == NULL)	return -1;

	//busca binaria no vetor
	int left = 0, right = abs->currSize-1, mid;

	while(left <= right){
		mid = (left+right+1) / 2;

		if(abs->vec[mid] < x)
			left = mid + 1;
		else if(abs->vec[mid] > x)
			right = mid - 1;
		else
			return mid + 1;
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
	if(abs != NULL) free(abs);
}
