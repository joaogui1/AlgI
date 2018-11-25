#include <stdio.h>
#include <stdlib.h>
#include "arrayBinarySearch.h"

arrayBS* createArrayBS(int size){
	arrayBS* newArray = malloc(sizeof(arrayBS));
	newArray->maxSize = size;
	newArray->currSize = 0;
	newArray->isSorted = 0;
	return newArray;
}	

int insertArrayBS(arrayBS* abs, elem x) {
	if(isFullArrayBS(abs)) 
		return 1;
	
	abs->vec[abs->currSize] = x;
	abs->currSize++;
	abs->isSorted = 0;

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

void mergeSort(int* vet, int start, int end){
	//base case
	if (start >= end) return;
	
	int mid = (start+end)/2;
	
	//recursion step
	mergeSort(vet, start, mid);
	mergeSort(vet, mid+1, end);
	
	//combination of the partial results
	int i = start;
	int j = mid+1;
	int k = 0;

	int* aux = malloc((end - start + 1) * sizeof(int));

	//merging sides
	while(i <= mid || j <= end){
		if(j > end || i <= mid && vet[i] < vet[j])
			aux[k++] = vet[i++];
		else
			aux[k++] = vet[j++];	
	}

	for(int i = start; i <= end; ++i){
		vet[i] = aux[i-start];
	}

	free(aux);
}


int searchArrayBS(arrayBS* abs, elem x){
	if(abs == NULL)
		return -1;

	if(!abs->isSorted){
		mergeSort(abs->vec, 0, abs->currSize-1);
		abs->isSorted = 1;
	}

	int left = 0, rigth = abs->currSize-1, mid;

	while(left <= rigth){
		mid = (left+rigth) / 2;
		
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