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
Node *insert(Tree *t, elem x){
  return t -> root = InsertNode(t -> root, x);
}

Node *Remove(Tree *t, elem x){
  return t -> root = RemoveNode(t -> root, x);
}
