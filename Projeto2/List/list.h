#ifndef LIST_H
#define LIST_H

typedef int elem;
typedef struct _list list;

list* createList();
int insertList(list* l, elem x);
int removeList(list* l, elem x);
int searchList(list* l, elem x);
int isEmptyList(list* l);
void printList(list* l);
void destroyList(list* l);
#endif