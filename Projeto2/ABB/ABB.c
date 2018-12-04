#include "ABB.h"
ABB *createABB(){
  ABB *ret;
  ret = calloc(1, sizeof(ABB));
  return ret;
}
void destroyABB(ABB *t){
  DestroyNodeABB(t -> root);
}
NodeABB *searchABB(ABB *t, elem x){
  SearchNodeABB(t -> root, x);
}
NodeABB *insertABB(ABB *t, elem x){
  return t->root = InsertNodeABB(t -> root, x);
}

NodeABB *RemoveABB(ABB *t, elem x){
  return t->root = RemoveNodeABB(t -> root, x);
}
