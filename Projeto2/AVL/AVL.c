#include "AVL.h"
AVL *createAVL(){
  AVL *ret;
  ret = calloc(1, sizeof(AVL));
  return ret;
}
void destroyAVL(AVL *t){
  DestroyNodeAVL(t -> root);
}
NodeAVL *searchAVL(AVL *t, elem x){
  SearchNodeAVL(t -> root, x);
}
NodeAVL *insertAVL(AVL *t, elem x){
  return t -> root = InsertNodeAVL(t -> root, x);
}

NodeAVL *RemoveAVL(AVL *t, elem x){
  return t -> root = RemoveNodeAVL(t -> root, x);
}
