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
  SearchNode(t -> root, x);
}
int insert(Tree *t, elem x){
  return InsertNode(&(t -> root), x);
}

int Remove(Tree *t, elem x){
  return RemoveNode(&(t -> root), x);
}
