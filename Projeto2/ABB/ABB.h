#ifndef TREE_H
#define TREE_H

#include "abbnode.h"

typedef struct{
  NodeABB *root;
}ABB;

ABB *createABB();
void destroyABB(ABB *t);
NodeABB *searchABB(ABB *t, elem x);
NodeABB *insertABB(ABB *t, elem x);
NodeABB *RemoveABB(ABB *t, elem x);

#endif
