#ifndef LISTFREQ_H
#define LISTFREQ_H

typedef int elem;
typedef struct _listFreq listFreq;

listFreq* createListFreq();
int insertListFreq(listFreq* l, elem x);
int removeListFreq(listFreq* l, elem x);
int searchListFreq(listFreq* l, elem x);
int isEmptyListFreq(listFreq* l);
void printListFreq(listFreq* l);
void destroyListFreq(listFreq* l);
#endif