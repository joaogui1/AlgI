#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ABB/ABB.h"
#include "AVL/AVL.h"
#include "List/list.h"
#include "ListFreq/listFreq.h"
#include "ListWithSentinel/listWithSentinel.h"
#include "ArrayBinarySearch/arrayBinarySearch.h"

#define DEBUG 0

int main(int argc, const char *argv[]){
	arrayBS* a[4];
	ABB *bst;
	list* l;
	AVL *bbst;
	listWS* ls;
	listFreq* lf;
	int random_order[100000], step = 1, element;
	double timeList = 0, timeArray = 0, timeListFreq = 0, timeListWS = 0, timeABB = 0, timeAVL = 0;
	double avgABBSearch[3][4] = {0}, avgAVLSearch[3][4] = {0};
	double avgListSearch[3][4] = {0}, avgArraySearch[3][4] = {0}, avgListFreqSearch[3][4] = {0}, avgListWSSearch[3][4] = {0};
	double avgABBRemoval[3][4] = {0}, avgAVLRemoval[3][4] = {0};
	double avgListRemoval[3][4] = {0}, avgArrayRemoval[3][4] = {0}, avgListFreqRemoval[3][4] = {0}, avgListWSRemoval[3][4] = {0};
	double avgABBInsertion[3][4] = {0}, avgAVLInsertion[3][4] = {0};
	double avgListInsertion[3][4] = {0}, avgArrayInsertion[3][4] = {0}, avgListFreqInsertion[3][4] = {0}, avgListWSInsertion[3][4] = {0};
	int n = 1001;
	int size = 0;


	// printf("crescente\n");
	//ordem crescente
	for(int i = 100; i < n; i *= 10){
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; ++j){
			ls = createListWS();

			//inserção de cada numero
			for(int k = 0; k < i; ++k) {
				timeListWS = clock();
				insertListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[0][size] += timeListWS;
			}

			// printf("buscas\n");
			for(int k = 0; k < i; ++k) {
				if(rand()&1)	element = k + i;
				timeListWS = clock();
				searchListWS(ls, element);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[0][size] += timeListWS;

			}

			// printf("Remocao\n");
			for(int k = 0; k < i; ++k) {
				if(rand()&1)	element = k + i;
				timeListWS = clock();
				removeListWS(ls, element);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[0][size] += timeListWS;

			}
			destroyListWS(ls);
		}

		avgListWSSearch[0][size] /= 10.0;
		avgListWSInsertion[0][size] /= 10.0;
		avgListWSRemoval[0][size] /= 10.0;

		++size;
	}

	//ordem decrescente
	size = 0;
	for(int i = 100; i < n; i *= 10){
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; ++j){
			ls = createListWS();
			//inserção de cada numero
			for(int k = i - 1; k > -1; --k) {
				timeListWS = clock();
				insertListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[1][size] += timeListWS;

			}

			for(int k = i - 1; k > -1; --k) {
				if(rand()&1)	element = k + i;
				timeListWS = clock();
				searchListWS(ls, element);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[1][size] += timeListWS;
			}

			for(int k = i - 1; k > -1; --k) {
				if(rand()&1)	element = k + i;
				timeListWS = clock();
				removeListWS(ls, element);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[1][size] += timeListWS;
			}

			destroyListWS(ls);
		}

		avgListWSSearch[1][size] /= 10.0;
		avgListWSInsertion[1][size] /= 10.0;
		avgListWSRemoval[1][size] /= 10.0;

		++size;
	}

	//ordem aleatoria


	size = 0;
	for(int i = 100; i < n; i *= 10){
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; ++j){
			ls = createListWS();

			step = 1;
			for(int k = 0; k < i; ++k)	random_order[k] = k;
			for(int k = 0; k < i; ++k)
				if(rand()&1){
					int tmp = random_order[(k + step)%i];
					random_order[(k + step)%i] = random_order[k];
					random_order[k] = tmp;
					++step;
				}

				printf("j = %d, %p\n", j, ls);
			//inserção de cada numero
			for(int k = 0; k < i; ++k){
				printf("%d %d\n", k, random_order[k]);
				timeListWS = clock();
				insertListWS(ls, random_order[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[2][size] += timeListWS;

			}
			printf("busca\n");
			step = 1;
			for(int k = 0; k < i; ++k)
				if(rand()&1){
					int tmp = random_order[(k + step)%i];
					random_order[(k + step)%i] = random_order[k];
					random_order[k] = tmp + i; //becomes an invalid search
					++step;
				}
			for(int k = 0; k < i; ++k) {
				timeListWS = clock();
				searchListWS(ls, random_order[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[2][size] += timeListWS;
			}

			step = 1;
			for(int k = 0; k < i; ++k)
				if(rand()&1){
					int tmp = random_order[(k + step)%i];
					random_order[(k + step)%i] = random_order[k];
					random_order[k] = tmp + i; //becomes an invalid removal
					++step;
				}
			for(int k = 0; k < i; ++k) {
				timeListWS = clock();
				removeListWS(ls, random_order[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[2][size] += timeListWS;

			}

			destroyListWS(ls);
		}
		avgListWSSearch[2][size] /= 10.0;
		avgListWSInsertion[2][size] /= 10.0;
		avgListWSRemoval[2][size] /= 10.0;

		++size;
	}


	return 0;
}
