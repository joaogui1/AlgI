#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	float timeList = 0, timeArray = 0, timeListFreq = 0, timeListWS = 0;
	int size = 100;
	for(int i = 0; i < 4; i++){
		a[i] = createArrayBS(size);
		size *= 10;
	}


	//ordem crescente

	//valores de n
	size = 0;	
	for(int i = 100; i < 100001; i *= 10){
		size++;
		//cada teste é feito 10 vezes
		for(int j = 0; j < 10; j++){

			//inserção de cada numero
			for(int k = 0; k < i; k++) {

				timeList += clock();
				insertList(l, k);
				timeList += clock() - timeList;

				timeListFreq += clock();
				insertListFreq(lf, k);
				timeListFreq += clock() - timeListFreq;

				timeListWS += clock();
				insertListWS(ls, k);
				timeListWS += clock() - timeListWS;

				timeArray += clock();
				insertArrayBS(a[size], k);
				timeArray += clock() - timeArray;

			}
		}
	}

	//ordem decrescente

	//ordem aleatoria

/* • Tabela 1: Tempo de insercao crescente
*  • Tabela 2: Tempo de insercao decrescente
*  • Tabela 3: Tempo de insercao aleatoria
*  • Tabela 4: Tempo de remocao crescente (apos insercao crescente)
*  • Tabela 5: Tempo de remocao decrescente (apos insercao crescente)
*  • Tabela 6: Tempo de remocao aleatoria (apos insercao aleatoria)
*  • Tabela 7: Tempo de busca (apos insercao crescente)
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