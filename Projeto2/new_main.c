#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "List/list.h"
#include "ListFreq/listFreq.h"
#include "ListWithSentinel/listWithSentinel.h"
#include "ArrayBinarySearch/arrayBinarySearch.h"

#define DEBUG 0

int main(int argc, const char *argv[]){
	list* l = createList();
	listFreq* lf = createListFreq();
	listWS* ls = createListWS();
	arrayBS* a[4];
	double timeList = 0, timeArray = 0, timeListFreq = 0, timeListWS = 0;
	double avgListSearch[4] = {0}, avgArraySearch[4] = {0}, avgListFreqSearch[4] = {0}, avgListWSSearch[4] = {0};
	double avgListRemoval[4] = {0}, avgArrayRemoval[4] = {0}, avgListFreqRemoval[4] = {0}, avgListWSRemoval[4] = {0};
	double avgListInsertion[4] = {0}, avgArrayInsertion[4] = {0}, avgListFreqInsertion[4] = {0}, avgListWSInsertion[4] = {0};

	int size = 100;
	for(int i = 0; i < 4; i++){
		a[i] = createArrayBS(size);
		size *= 10;
	}

	//ordem crescente

	//valores de n
	size = 0;
	for(int i = 100; i < 10001; i *= 10){
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; ++j){

			//inserção de cada numero
			for(int k = 0; k < i; ++k) {

				timeList = clock();
				insertList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListInsertion[size] += timeList;

				timeListFreq = clock();
				insertListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqInsertion[size] += timeListFreq;


				timeListWS = clock();
				insertListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSInsertion[size] += timeListWS;


				timeArray = clock();
				insertArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayInsertion[size] += timeArray;

			}

			for(int k = 0; k < i; ++k) {

				timeList = clock();
				searchList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListSearch[size] += timeList;

				timeListFreq = clock();
				searchListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqSearch[size] += timeListFreq;


				timeListWS = clock();
				searchListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSSearch[size] += timeListWS;


				timeArray = clock();
				searchArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArraySearch[size] += timeArray;

			}

			for(int k = 0; k < i; ++k) {

				timeList = clock();
				removeList(l, k);
				timeList = (clock() - timeList)/CLOCKS_PER_SEC;
				avgListRemoval[size] += timeList;

				timeListFreq = clock();
				removeListFreq(lf, k);
				timeListFreq = (clock() - timeListFreq)/CLOCKS_PER_SEC;
				avgListFreqRemoval[size] += timeListFreq;


				timeListWS = clock();
				removeListWS(ls, k);
				timeListWS = (clock() - timeListWS)/CLOCKS_PER_SEC;
				avgListWSRemoval[size] += timeListWS;


				timeArray = clock();
				removeArrayBS(a[size], k);
				timeArray = (clock() - timeArray)/CLOCKS_PER_SEC;
				avgArrayRemoval[size] += timeArray;

			}
		}

		avgListSearch[size] /= 10.0;
		avgArraySearch[size] /= 10.0;
		avgListWSSearch[size] /= 10.0;
		avgListFreqSearch[size] /= 10.0;

		avgListInsertion[size] /= 10.0;
		avgArrayInsertion[size] /= 10.0;
		avgListWSInsertion[size] /= 10.0;
		avgListFreqInsertion[size] /= 10.0;

		avgListRemoval[size] /= 10.0;
		avgArrayRemoval[size] /= 10.0;
		avgListWSRemoval[size] /= 10.0;
		avgListFreqRemoval[size] /= 10.0;

		++size;
	}

	printf("Tabela 1: Tempo de insercao crescente\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgArrayInsertion[i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListInsertion[i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListWSInsertion[i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListFreqInsertion[i]);
	}
	printf("\n");

	printf("Tabela 4: Tempo de remocao crescente\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgArrayRemoval[i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListRemoval[i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListWSRemoval[i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListFreqRemoval[i]);
	}
	printf("\n");

	printf("Tabela 7: Tempo de busca crescente\n");
	printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
	printf("BB");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgArraySearch[i]);
	}
	printf("\n");

	printf("LO");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListSearch[i]);
	}
	printf("\n");

	printf("LOS");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListWSSearch[i]);
	}
	printf("\n");

	printf("LFREQ");
	for(int i = 0; i < 3; ++i){
		printf("\t%lf", avgListFreqSearch[i]);
	}
	printf("\n");

	//ordem decrescente

	//ordem aleatoria

/* • Tabela 1: Tempo de insercao crescente oks
*  • Tabela 2: Tempo de insercao decrescente
*  • Tabela 3: Tempo de insercao aleatoria
*  • Tabela 4: Tempo de remocao crescente (apos insercao crescente) oks
*  • Tabela 5: Tempo de remocao decrescente (apos insercao crescente)
*  • Tabela 6: Tempo de remocao aleatoria (apos insercao aleatoria)
*  • Tabela 7: Tempo de busca (apos insercao crescente) oks
*  • Tabela 8: Tempo de busca (apos insercao decrescente)
*  • Tabela 9: Tempo de busca (apos insercao aleatoria)
*/

	destroyList(l);
	destroyListFreq(lf);
	destroyListWS(ls);
	for(int i = 0; i < 4; i++){
		destroyArrayBS(a[i]);
	}

	return 0;
}
