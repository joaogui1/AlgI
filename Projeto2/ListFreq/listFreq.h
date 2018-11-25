typedef int elem;

typedef struct _node{
	elem info;
	struct _node *next, *prev;
} node;

typedef struct _listFreq{
	node* start;
	node* end;
	int size;
} listFreq;

listFreq* createListFreq();
int insertListFreq(listFreq* l, elem x);
int removeListFreq(listFreq* l, elem x);
int searchListFreq(listFreq* l, elem x);
int isEmptyListFreq(listFreq* l);
void printListFreq(listFreq* l);
void destroyListFreq(listFreq* l);