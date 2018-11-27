//basicamente um wrapper ao redor de node
#ifndef TREE_H
#define TREE_H

#include "node.h"

typedef struct{
  Node *root;
}Tree;

Tree *create();
void destroy(Tree *t);
Node *search(Tree *t, elem x);
int insert(Tree *t, elem x);
int remove(Tree *t, elem x);

#endif