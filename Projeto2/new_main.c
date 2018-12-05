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
	ABB *bst = createABB();
	list* l = createList();
	AVL *bbst = createAVL();
	listFreq* lf = createListFreq();
	listWS* ls = createListWS();
	arrayBS* a[4];
	int random_order[100000], step = 1;
	double timeList = 0, timeArray = 0, timeListFreq = 0, timeListWS = 0, timeABB = 0, timeAVL = 0;
	double avgABBSearch[3][4] = {0}, avgAVLSearch[3][4] = {0};
	double avgListSearch[3][4] = {0}, avgArraySearch[3][4] = {0}, avgListFreqSearch[3][4] = {0}, avgListWSSearch[3][4] = {0};
	double avgABBRemoval[3][4] = {0}, avgAVLRemoval[3][4] = {0};
	double avgListRemoval[3][4] = {0}, avgArrayRemoval[3][4] = {0}, avgListFreqRemoval[3][4] = {0}, avgListWSRemoval[3][4] = {0};
	double avgABBInsertion[3][4] = {0}, avgAVLInsertion[3][4] = {0};
	double avgListInsertion[3][4] = {0}, avgArrayInsertion[3][4] = {0}, avgListFreqInsertion[3][4] = {0}, avgListWSInsertion[3][4] = {0};
	int n = 1001;
	int size = 100;

	for(int i = 0; i < 4; i++){
		a[i] = createArrayBS(size);
		size *= 10;
	}

	//ordem crescente
	size = 0;
	for(int i = 100; i < n; i *= 10){
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; ++j){

			//inserção de cada numero
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				insertList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListInsertion[0][size] += timeList;

				timeListFreq = clock();
				insertListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqInsertion[0][size] += timeListFreq;


				timeListWS = clock();
				insertListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[0][size] += timeListWS;


				timeArray = clock();
				insertArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayInsertion[0][size] += timeArray;

				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBInsertion[0][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLInsertion[0][size] += timeAVL;
			}

			for(int k = 0; k < i; ++k) {

				timeList = clock();
				searchList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListSearch[0][size] += timeList;

				timeListFreq = clock();
				searchListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqSearch[0][size] += timeListFreq;


				timeListWS = clock();
				searchListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[0][size] += timeListWS;


				timeArray = clock();
				searchArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArraySearch[0][size] += timeArray;

				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBSearch[0][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLSearch[0][size] += timeAVL;
			}

			for(int k = 0; k < i; ++k) {

				timeList = clock();
				removeList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListRemoval[0][size] += timeList;

				timeListFreq = clock();
				removeListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqRemoval[0][size] += timeListFreq;


				timeListWS = clock();
				removeListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[0][size] += timeListWS;


				timeArray = clock();
				removeArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayRemoval[0][size] += timeArray;

				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBRemoval[0][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLRemoval[0][size] += timeAVL;
			}
		}

		avgListSearch[0][size] /= 10.0;
		avgArraySearch[0][size] /= 10.0;
		avgListWSSearch[0][size] /= 10.0;
		avgListFreqSearch[0][size] /= 10.0;

		avgListInsertion[0][size] /= 10.0;
		avgArrayInsertion[0][size] /= 10.0;
		avgListWSInsertion[0][size] /= 10.0;
		avgListFreqInsertion[0][size] /= 10.0;

		avgListRemoval[0][size] /= 10.0;
		avgArrayRemoval[0][size] /= 10.0;
		avgListWSRemoval[0][size] /= 10.0;
		avgListFreqRemoval[0][size] /= 10.0;

		++size;
	}

	//ordem decrescente
	size = 0;
	for(int i = 100; i < n; i *= 10){
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; ++j){

			//inserção de cada numero
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

			for(int k = i - 1; k > -1; --k) {

				timeList = clock();
				searchList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListSearch[1][size] += timeList;

				timeListFreq = clock();
				searchListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqSearch[1][size] += timeListFreq;


				timeListWS = clock();
				searchListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[1][size] += timeListWS;


				timeArray = clock();
				searchArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArraySearch[1][size] += timeArray;

				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBSearch[1][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLSearch[1][size] += timeAVL;
			}

			for(int k = i - 1; k > -1; --k) {

				timeList = clock();
				removeList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListRemoval[1][size] += timeList;

				timeListFreq = clock();
				removeListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqRemoval[1][size] += timeListFreq;


				timeListWS = clock();
				removeListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[1][size] += timeListWS;


				timeArray = clock();
				removeArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayRemoval[1][size] += timeArray;

				timeABB = clock();
				insertABB(bst, k);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBRemoval[1][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, k);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLRemoval[1][size] += timeAVL;
			}
		}

		avgListSearch[1][size] /= 10.0;
		avgArraySearch[1][size] /= 10.0;
		avgListWSSearch[1][size] /= 10.0;
		avgListFreqSearch[1][size] /= 10.0;

		avgListInsertion[1][size] /= 10.0;
		avgArrayInsertion[1][size] /= 10.0;
		avgListWSInsertion[1][size] /= 10.0;
		avgListFreqInsertion[1][size] /= 10.0;

		avgListRemoval[1][size] /= 10.0;
		avgArrayRemoval[1][size] /= 10.0;
		avgListWSRemoval[1][size] /= 10.0;
		avgListFreqRemoval[1][size] /= 10.0;

		++size;
	}

	//ordem aleatoria

	size = 0;
	for(int i = 100; i < n; i *= 10){
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; ++j){

			step = 1;
			for(int k = 0; k < i; ++k)	random_order[k] = k;
			for(int k = 0; k < i; ++k)
				if(rand()&1){
					int tmp = random_order[(k + step)%i];
					random_order[(k + step)%i] = random_order[k];
					random_order[k] = tmp;
					++step;
				}

			//inserção de cada numero
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				insertList(l, random_order[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListInsertion[2][size] += timeList;

				timeListFreq = clock();
				insertListFreq(lf, random_order[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqInsertion[2][size] += timeListFreq;


				timeListWS = clock();
				insertListWS(ls, random_order[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[2][size] += timeListWS;


				timeArray = clock();
				insertArrayBS(a[size], random_order[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayInsertion[2][size] += timeArray;

				timeABB = clock();
				insertABB(bst, random_order[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBInsertion[2][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, random_order[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLInsertion[2][size] += timeAVL;
			}

			step = 1;
			for(int k = 0; k < i; ++k)
				if(rand()&1){
					int tmp = random_order[(k + step)%i];
					random_order[(k + step)%i] = random_order[k];
					random_order[k] = tmp;
					++step;
				}

			for(int k = 0; k < i; ++k) {

				timeList = clock();
				searchList(l, random_order[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListSearch[2][size] += timeList;

				timeListFreq = clock();
				searchListFreq(lf, random_order[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqSearch[2][size] += timeListFreq;


				timeListWS = clock();
				searchListWS(ls, random_order[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[2][size] += timeListWS;

				timeArray = clock();
				searchArrayBS(a[size], random_order[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArraySearch[2][size] += timeArray;

				timeABB = clock();
				insertABB(bst, random_order[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBSearch[2][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, random_order[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLSearch[2][size] += timeAVL;
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

				timeList = clock();
				removeList(l, random_order[k]);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListRemoval[2][size] += timeList;

				timeListFreq = clock();
				removeListFreq(lf, random_order[k]);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqRemoval[2][size] += timeListFreq;


				timeListWS = clock();
				removeListWS(ls, random_order[k]);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[2][size] += timeListWS;

				timeArray = clock();
				removeArrayBS(a[size], random_order[k]);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayRemoval[2][size] += timeArray;

				timeABB = clock();
				insertABB(bst, random_order[k]);
				timeABB = (clock() - timeABB)/CLOCKS_PER_SEC;
				avgABBRemoval[2][size] += timeABB;

				timeAVL = clock();
				insertAVL(bbst, random_order[k]);
				timeAVL = (clock() - timeAVL)/CLOCKS_PER_SEC;
				avgAVLRemoval[2][size] += timeAVL;
			}
		}

		avgListSearch[2][size] /= 10.0;
		avgArraySearch[2][size] /= 10.0;
		avgListWSSearch[2][size] /= 10.0;
		avgListFreqSearch[2][size] /= 10.0;

		avgListInsertion[2][size] /= 10.0;
		avgArrayInsertion[2][size] /= 10.0;
		avgListWSInsertion[2][size] /= 10.0;
		avgListFreqInsertion[2][size] /= 10.0;

		avgListRemoval[2][size] /= 10.0;
		avgArrayRemoval[2][size] /= 10.0;
		avgListWSRemoval[2][size] /= 10.0;
		avgListFreqRemoval[2][size] /= 10.0;

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
	printf("\n");

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
	printf("\n");

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
	printf("\n");

	printf("Tabela 4: Tempo de remocao crescente\n");
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
	printf("\n");

	printf("Tabela 5: Tempo de remocao decrescente\n");
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
	printf("\n");

	printf("Tabela 6: Tempo de remocao aleatoria\n");
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
	printf("\n");

	printf("Tabela 7: Tempo de busca crescente\n");
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
	printf("\n");

	printf("Tabela 8: Tempo de busca decrescente\n");
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
	printf("\n");

	printf("Tabela 9: Tempo de busca aleatoria\n");
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
	printf("\n");

	destroyList(l);
	destroyABB(bst);
	destroyAVL(bbst);
	// destroyListFreq(lf);
	destroyListWS(ls);
	for(int i = 0; i < 4; i++){
		destroyArrayBS(a[i]);
	}

	return 0;
}
