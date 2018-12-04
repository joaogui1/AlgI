#ifndef TREE_H
#define TREE_H

typedef int elem;

typedef struct _abb ABB;

ABB *createABB();
void destroyABB(ABB *t);
int searchABB(ABB *t, elem x);
int insertABB(ABB *t, elem x);
int RemoveABB(ABB *t, elem x);

#endif