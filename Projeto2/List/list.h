#ifndef list
typedef int elem;

typedef struct _nodeL {
	elem info;
	struct _nodeL *next, *prev;
} nodeL;

typedef struct _list {
	nodeL* start;
	nodeL* end;
} list;

list* createList();
int insertList(list* l, elem x);
int removeList(list* l, elem x);
int searchList(list* l, elem x);
int isEmptyList(list* l);
void printList(list* l);
void destroyList(list* l);
#endif