#include "ABB.h"
ABB *createABB(){
  ABB *ret;
  ret = calloc(1, sizeof(Tree));
  return ret;
}
void destroyABB(Tree *t){
  DestroyNodeABB(t -> root);
}
NodeABB *searchABB(Tree *t, elem x){
  SearchNodeABB(t -> root, x);
}
NodeAB *insertABB(Tree *t, elem x){
  return InsertNodeABB(t -> root, x);
}

int RemoveABB(Tree *t, elem x){
  return RemoveNodeABB(t -> root, x);
}
