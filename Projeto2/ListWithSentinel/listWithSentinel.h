#ifndef listWS
typedef int elem;

typedef struct _nodeWS {
	elem info;
	struct _nodeWS *next, *prev;
} nodeWS;

typedef struct _listWS {
	nodeWS* start;
	nodeWS* end;
	nodeWS* sentinel;
} listWS;

listWS* createListWS();
int insertListWS(listWS* l, elem x);
int removeListWS(listWS* l, elem x);
int searchListWS(listWS* l, elem x);
int isEmptyListWS(listWS* l);
void printListWS(listWS* l);
void destroyListWS(listWS* l);
#endif