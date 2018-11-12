//basicamente um wrapper ao redor de node
#include "node.h"
typedef struct{
  node *root;
}Tree;

Tree *create();
void destroy(Tree *t);
Node *search(Tree *t, elem x);
int insert(Tree *t, elem x);
