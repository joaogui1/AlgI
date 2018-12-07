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

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(int argc, const char *argv[]){
	arrayBS* a[4];
	ABB *bst;
	list* l;
	AVL *bbst;
	listWS* ls;
	listFreq* lf;
	int random_search[100000], random_insertion[100000], random_removal[100000], idx1, idx2;
	double timeList = 0, timeArray = 0, timeListFreq = 0, timeListWS = 0, timeABB = 0, timeAVL = 0;
	double avgABBSearch[3][4] = {0}, avgAVLSearch[3][4] = {0};
	double avgListSearch[3][4] = {0}, avgArraySearch[3][4] = {0}, avgListFreqSearch[3][4] = {0}, avgListWSSearch[3][4] = {0};
	double avgABBRemoval[3][4] = {0}, avgAVLRemoval[3][4] = {0};
	double avgListRemoval[3][4] = {0}, avgArrayRemoval[3][4] = {0}, avgListFreqRemoval[3][4] = {0}, avgListWSRemoval[3][4] = {0};
	double avgABBInsertion[3][4] = {0}, avgAVLInsertion[3][4] = {0};
	double avgListInsertion[3][4] = {0}, avgArrayInsertion[3][4] = {0}, avgListFreqInsertion[3][4] = {0}, avgListWSInsertion[3][4] = {0};
	int n = 10001;
	int size = 0;


	// printf("crescente\n");
	//ordem crescente
	for(int i = 100; i < n; i *= 10){
		printf("%d\n", i);
		for(int j = 0; j < i; ++j)
			random_removal[j] = random_insertion[j] = (i/2 + j)%i;

		for(int j = 0; j < i; ++j){
			idx1 = rand()%i;
			idx2 = rand()%i;
			swap(&random_insertion[idx1], &random_insertion[idx2]);
		}

		for(int j = 0; j < i; ++j)
			random_search[j] = (rand()%(2*i));

		for(int j = 0; j < i; ++j){
			idx1 = rand()%i;
			idx2 = rand()%i;
			swap(&random_removal[idx1], &random_removal[idx2]);
			if(rand()&1)
				random_removal[j] += i;
		}

		//cada teste é feito 10 vezes
		for(int j = 0; j < 4; ++j){
			printf("\tcrescente %d\n", j);
			l = createList();
			bst = createABB();
			bbst = createAVL();
			ls = createListWS();
			lf = createListFreq();
			a[size] = createArrayBS(i);

			//inserção de cada numero
			printf("\t\tinsercao\n");
			for(int k = 0; k < i; ++k) {

				// printf("insercao lista %d\n", k);
				timeList = clock();
				insertList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListInsertion[0][size] += timeList;
				//
				// printf("insercao listafreq %d\n", k);
				timeListFreq = clock();
				insertListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqInsertion[0][size] += timeListFreq;
				//
				// printf("insercao listas sentinela %d %p\n", k, ls);
				timeListWS = clock();
				insertListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[0][size] += timeListWS;

				// printf("insercao busca binaria%d\n", k);
				timeArray = clock();
				insertArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayInsertion[0][size] += timeArray;

				// printf("insercao ABB %d\n", k);
				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBInsertion[0][size] += timeABB;

				// printf("insercao AVL %d %d\n", k, i);
				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLInsertion[0][size] += timeAVL;
			}

			// printf("buscas\n");
			printf("\t\tbusca\n");
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				searchList(l, random_search[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListSearch[0][size] += timeList;

				timeListFreq = clock();
				searchListFreq(lf, random_search[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqSearch[0][size] += timeListFreq;
				//
				//
				timeListWS = clock();
				searchListWS(ls, random_search[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[0][size] += timeListWS;
				//
				//
				timeArray = clock();
				searchArrayBS(a[size], random_search[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArraySearch[0][size] += timeArray;

				timeABB = clock();
				searchABB(bst, random_search[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBSearch[0][size] += timeABB;

				timeAVL = clock();
				searchAVL(bbst, random_search[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLSearch[0][size] += timeAVL;
			}

			// printf("Remocao\n");
			printf("\t\tremocao\n");
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				removeList(l, random_removal[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListRemoval[0][size] += timeList;
				//
				timeListFreq = clock();
				removeListFreq(lf, random_removal[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqRemoval[0][size] += timeListFreq;
				//
				//
				timeListWS = clock();
				removeListWS(ls, random_removal[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[0][size] += timeListWS;
				//
				//
				timeArray = clock();
				removeArrayBS(a[size], random_removal[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayRemoval[0][size] += timeArray;

				timeABB = clock();
				removeABB(bst, random_removal[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBRemoval[0][size] += timeABB;

				timeAVL = clock();
				removeAVL(bbst, random_removal[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLRemoval[0][size] += timeAVL;
			}
			destroyList(l);
			destroyABB(bst);
			destroyAVL(bbst);
			destroyListFreq(lf);
			destroyListWS(ls);
			destroyArrayBS(a[size]);
		}
		avgListSearch[0][size] /= 4.0;
		avgArraySearch[0][size] /= 4.0;
		avgListWSSearch[0][size] /= 4.0;
		avgListFreqSearch[0][size] /= 4.0;

		avgListInsertion[0][size] /= 4.0;
		avgArrayInsertion[0][size] /= 4.0;
		avgListWSInsertion[0][size] /= 4.0;
		avgListFreqInsertion[0][size] /= 4.0;

		avgListRemoval[0][size] /= 4.0;
		avgArrayRemoval[0][size] /= 4.0;
		avgListWSRemoval[0][size] /= 4.0;
		avgListFreqRemoval[0][size] /= 4.0;

	//ordem decrescente
	//cada teste é feito 10 vezes
		for(int j = 0; j < 4; ++j){
			printf("\tdecrescente %d\n", j);
			l = createList();
			bst = createABB();
			bbst = createAVL();
			ls = createListWS();
			lf = createListFreq();
			a[size] = createArrayBS(i);

			//inserção de cada numero
			printf("\t\tinsercao\n");
			for(int k = i - 1; k > -1; --k) {

				timeList = clock();
				insertList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListInsertion[1][size] += timeList;

				timeListFreq = clock();
				insertListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqInsertion[1][size] += timeListFreq;


				timeListWS = clock();
				insertListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[1][size] += timeListWS;


				timeArray = clock();
				insertArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayInsertion[1][size] += timeArray;

				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBInsertion[1][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLInsertion[1][size] += timeAVL;
			}

			printf("\t\tbusca\n");
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				searchList(l, random_search[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListSearch[1][size] += timeList;

				timeListFreq = clock();
				searchListFreq(lf, random_search[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqSearch[1][size] += timeListFreq;


				timeListWS = clock();
				searchListWS(ls, random_search[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[1][size] += timeListWS;


				timeArray = clock();
				searchArrayBS(a[size], random_search[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArraySearch[1][size] += timeArray;

				timeABB = clock();
				searchABB(bst, random_search[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBSearch[1][size] += timeABB;

				timeAVL = clock();
				searchAVL(bbst, random_search[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLSearch[1][size] += timeAVL;
			}



			destroyList(l);
			destroyABB(bst);
			destroyAVL(bbst);
			destroyListFreq(lf);
			destroyListWS(ls);
			destroyArrayBS(a[size]);

			l = createList();
			bst = createABB();
			bbst = createAVL();
			ls = createListWS();
			lf = createListFreq();
			a[size] = createArrayBS(i);

			for(int k = 0; k < i; ++k) {

				// printf("insercao lista %d\n", k);
				timeList = clock();
				insertList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListInsertion[0][size] += timeList;
				//
				// printf("insercao listafreq %d\n", k);
				timeListFreq = clock();
				insertListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqInsertion[0][size] += timeListFreq;
				//
				// printf("insercao listas sentinela %d %p\n", k, ls);
				timeListWS = clock();
				insertListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[0][size] += timeListWS;

				// printf("insercao busca binaria%d\n", k);
				timeArray = clock();
				insertArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayInsertion[0][size] += timeArray;

				// printf("insercao ABB %d\n", k);
				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBInsertion[0][size] += timeABB;

				// printf("insercao AVL %d %d\n", k, i);
				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLInsertion[0][size] += timeAVL;
			}

			printf("\t\tremocao\n");
			for(int k = i - 1; k > -1; --k) {

				timeList = clock();
				removeList(l, random_removal[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListRemoval[1][size] += timeList;

				timeListFreq = clock();
				removeListFreq(lf, random_removal[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqRemoval[1][size] += timeListFreq;


				timeListWS = clock();
				removeListWS(ls, random_removal[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[1][size] += timeListWS;


				timeArray = clock();
				removeArrayBS(a[size], random_removal[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayRemoval[1][size] += timeArray;

				timeABB = clock();
				removeABB(bst, random_removal[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBRemoval[1][size] += timeABB;

				timeAVL = clock();
				removeAVL(bbst, random_removal[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLRemoval[1][size] += timeAVL;
			}
			destroyList(l);
			destroyABB(bst);
			destroyAVL(bbst);
			destroyListFreq(lf);
			destroyListWS(ls);
			destroyArrayBS(a[size]);
		}

		avgListSearch[1][size] /= 4.0;
		avgArraySearch[1][size] /= 4.0;
		avgListWSSearch[1][size] /= 4.0;
		avgListFreqSearch[1][size] /= 4.0;

		avgListInsertion[1][size] /= 4.0;
		avgArrayInsertion[1][size] /= 4.0;
		avgListWSInsertion[1][size] /= 4.0;
		avgListFreqInsertion[1][size] /= 4.0;

		avgListRemoval[1][size] /= 4.0;
		avgArrayRemoval[1][size] /= 4.0;
		avgListWSRemoval[1][size] /= 4.0;
		avgListFreqRemoval[1][size] /= 4.0;

	//ordem aleatoria
	//cada teste é feito 10 vezes
		for(int j = 0; j < 4; ++j){
			printf("\taleatoria %d\n", j);

			l = createList();
			bst = createABB();
			bbst = createAVL();
			ls = createListWS();
			lf = createListFreq();
			a[size] = createArrayBS(i);

			//inserção de cada numero
			printf("\t\tinsercao\n");
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				insertList(l, random_insertion[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListInsertion[2][size] += timeList;

				timeListFreq = clock();
				insertListFreq(lf, random_insertion[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqInsertion[2][size] += timeListFreq;


				timeListWS = clock();
				insertListWS(ls, random_insertion[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[2][size] += timeListWS;


				timeArray = clock();
				insertArrayBS(a[size], random_insertion[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayInsertion[2][size] += timeArray;

				timeABB = clock();
				insertABB(bst, random_insertion[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBInsertion[2][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, random_insertion[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLInsertion[2][size] += timeAVL;
			}

			printf("\t\tbusca\n");
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				searchList(l, random_search[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListSearch[2][size] += timeList;

				timeListFreq = clock();
				searchListFreq(lf, random_search[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqSearch[2][size] += timeListFreq;


				timeListWS = clock();
				searchListWS(ls, random_search[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[2][size] += timeListWS;

				timeArray = clock();
				searchArrayBS(a[size], random_search[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArraySearch[2][size] += timeArray;

				timeABB = clock();
				searchABB(bst, random_search[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBSearch[2][size] += timeABB;

				timeAVL = clock();
				searchAVL(bbst, random_search[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLSearch[2][size] += timeAVL;
			}

			printf("\t\tremocao\n");
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				removeList(l, random_removal[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListRemoval[2][size] += timeList;

				// searchListFreq(lf, random_removal[k]);
				timeListFreq = clock();
				removeListFreq(lf, random_removal[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqRemoval[2][size] += timeListFreq;

				timeListWS = clock();
				removeListWS(ls, random_removal[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[2][size] += timeListWS;

				timeArray = clock();
				removeArrayBS(a[size], random_removal[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayRemoval[2][size] += timeArray;

				timeABB = clock();
				removeABB(bst, random_removal[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBRemoval[2][size] += timeABB;

				timeAVL = clock();
				removeAVL(bbst, random_removal[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLRemoval[2][size] += timeAVL;
			}

			destroyList(l);
			destroyABB(bst);
			destroyAVL(bbst);
			destroyListFreq(lf);
			destroyListWS(ls);
			destroyArrayBS(a[size]);
		}

		avgListSearch[2][size] /= 4.0;
		avgArraySearch[2][size] /= 4.0;
		avgListWSSearch[2][size] /= 4.0;
		avgListFreqSearch[2][size] /= 4.0;

		avgListInsertion[2][size] /= 4.0;
		avgArrayInsertion[2][size] /= 4.0;
		avgListWSInsertion[2][size] /= 4.0;
		avgListFreqInsertion[2][size] /= 4.0;

		avgListRemoval[2][size] /= 4.0;
		avgArrayRemoval[2][size] /= 4.0;
		avgListWSRemoval[2][size] /= 4.0;
		avgListFreqRemoval[2][size] /= 4.0;


		++size;
	}

	printf("Tabela 1: Tempo de insercao crescente\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArrayInsertion[0][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListInsertion[0][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSInsertion[0][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBInsertion[0][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLInsertion[0][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqInsertion[0][i]);
	}
	printf("\n-\n");

	printf("Tabela 2: Tempo de insercao decrescente\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArrayInsertion[1][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListInsertion[1][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSInsertion[1][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBInsertion[1][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLInsertion[1][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqInsertion[1][i]);
	}
	printf("\n-\n");

	printf("Tabela 3: Tempo de insercao aleatoria\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArrayInsertion[2][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListInsertion[2][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSInsertion[2][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBInsertion[2][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLInsertion[2][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqInsertion[2][i]);
	}
	printf("\n-\n");

	printf("Tabela 4: Tempo de remocao crescente (apos insercao crescente)\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArrayRemoval[0][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListRemoval[0][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSRemoval[0][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBRemoval[0][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLRemoval[0][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqRemoval[0][i]);
	}
	printf("\n-\n");

	printf("Tabela 5: Tempo de remocao decrescente (apos insercao crescente)\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArrayRemoval[1][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListRemoval[1][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSRemoval[1][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBRemoval[1][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLRemoval[1][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqRemoval[1][i]);
	}
	printf("\n-\n");

	printf("Tabela 6: Tempo de remocao aleatoria (apos insercao aleatoria)\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArrayRemoval[2][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListRemoval[2][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSRemoval[2][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBRemoval[2][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLRemoval[2][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqRemoval[2][i]);
	}
	printf("\n-\n");

	printf("Tabela 7: Tempo de busca (apos insercao crescente)\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArraySearch[0][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListSearch[0][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSSearch[0][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBSearch[0][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLSearch[0][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqSearch[0][i]);
	}
	printf("\n-\n");

	printf("Tabela 8: Tempo de busca (apos insercao decrescente)\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArraySearch[1][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListSearch[1][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSSearch[1][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBSearch[1][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLSearch[1][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqSearch[1][i]);
	}
	printf("\n-\n");

	printf("Tabela 9: Tempo de busca (apos insercao aleatoria)\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgArraySearch[2][i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListSearch[2][i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListWSSearch[2][i]);
	}
	printf("\n");

	printf("ABB");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgABBSearch[2][i]);
	}
	printf("\n");

	printf("AVL");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgAVLSearch[2][i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 4; ++i){
		printf("\t%lf", avgListFreqSearch[2][i]);
	}
	printf("\n-\n");


	return 0;
}
