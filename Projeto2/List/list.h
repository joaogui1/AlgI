typedef int elem;

typedef struct _node{
	elem info;
	struct _node *next, *prev;
}node;

typedef struct _list{
	node* start;
	node* end;
} list;

list* createList();
int insertList(list* l, elem x);
int removeList(list* l, elem x);
int searchList(list* l, elem x);
int isEmptyList(list* l);
void printList(list* l);
void destroyList(list* l);