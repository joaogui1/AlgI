#include <stdlib.h>
#ifndef NODE_H
#define NODE_H

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

#endif
