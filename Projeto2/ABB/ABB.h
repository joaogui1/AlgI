#ifndef TREE_H
#define TREE_H

#include "abbnode.h"

typedef struct{
  Node *root;
}Tree;

Tree *createABB();
void destroyABB(ABB *t);
NodeABB *searchABB(ABB *t, elem x);
NodeABB insertABB(ABB *t, elem x);
int RemoveABB(ABB *t, elem x);

#endif
