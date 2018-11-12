#include "tree.h"
Tree *create(){
  Tree *ret;
  ret = calloc(1, sizeof(Tree));
  return ret;
}
void destroy(Tree *t){
  DestroyNode(t -> root);
}
Node *search(Tree *t, elem x){
  searchNode(t -> root, x);
}
