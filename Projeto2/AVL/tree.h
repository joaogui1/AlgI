//basicamente um wrapper ao redor de node
#include "node.h"
typedef struct{
  Node *root;
}Tree;

Tree *create();
void destroy(Tree *t);
Node *search(Tree *t, elem x);
Node *insert(Tree *t, elem x);
Node *Remove(Tree *t, elem x);
