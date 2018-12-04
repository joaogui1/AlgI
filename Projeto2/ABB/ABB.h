#ifndef TREE_H
#define TREE_H
#include <stdlib.h>

#define elem int

typedef struct nodeABB{
  elem info;
  struct nodeABB *left, *right;
} NodeABB;

NodeABB *CreateNodeABB(elem x);
void DestroyNodeABB(NodeABB *n);
NodeABB *SearchNodeABB(NodeABB *n, elem x);
NodeABB *InsertNodeABB(NodeABB *n, elem x);
NodeABB *RemoveNodeABB(NodeABB *n, elem x);


typedef struct{
  NodeABB *root;
}ABB;

ABB *createABB();
void destroyABB(ABB *t);
NodeABB *searchABB(ABB *t, elem x);
NodeABB *insertABB(ABB *t, elem x);
NodeABB *RemoveABB(ABB *t, elem x);

#endif
