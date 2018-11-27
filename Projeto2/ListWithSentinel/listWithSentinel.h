#ifndef LISTWS_H
#define LISTWS_H

typedef int elem;

typedef struct _listWS listWS;

listWS* createListWS();
int insertListWS(listWS* l, elem x);
int removeListWS(listWS* l, elem x);
int searchListWS(listWS* l, elem x);
int isEmptyListWS(listWS* l);
void printListWS(listWS* l);
void destroyListWS(listWS* l);
#endif