typedef int elem;

typedef struct _node{
	elem info;
	struct _node *next, *prev;
}node;

typedef struct _listWS{
	node* start;
	node* end;
	node* sentinel;
} listWS;

listWS* createListWS();
int insertListWS(listWS* l, elem x);
int removeListWS(listWS* l, elem x);
int searchListWS(listWS* l, elem x);
int isEmptyListWS(listWS* l);
void printListWS(listWS* l);
void destroyListWS(listWS* l);