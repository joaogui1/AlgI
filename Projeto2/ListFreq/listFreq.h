#ifndef listFreq
typedef int elem;

typedef struct _nodeLF {
	elem info;
	struct _nodeLF *next, *prev;
} nodeLF;

typedef struct _listFreq{
	nodeLF* start;
	nodeLF* end;
	int size;
} listFreq;

listFreq* createListFreq();
int insertListFreq(listFreq* l, elem x);
int removeListFreq(listFreq* l, elem x);
int searchListFreq(listFreq* l, elem x);
int isEmptyListFreq(listFreq* l);
void printListFreq(listFreq* l);
void destroyListFreq(listFreq* l);
#endif