#include "abbnode.h"
#include <stdio.h>

NodeABB *CreateNodeABB(elem x){
  NodeABB  *ret;
  ret = calloc(1, sizeof(NodeABB));
  ret -> info = x;
  return ret;
}

void DestroyNodeABB(NodeABB *n){
  if(n == NULL) return;
  if(n -> right != NULL)  DestroyNodeABB(n -> right);
  if(n -> left != NULL)  DestroyNodeABB(n -> left);
  free(n);
}

NodeABB *SearchNodeABB(NodeABB *n, elem x){
  if(n == NULL || n -> info == x) return n;
  if(n -> info > x) return SearchNodeABB(n -> left, x);
  if(n -> info < x) return SearchNodeABB(n -> right, x);
  return NULL;
}

NodeABB *InsertNodeABB(NodeABB *n, elem x){
  int BalanceFactor;
  if(n == NULL) n = CreateNodeABB(x);
  else if(n -> info > x)  n -> left = InsertNodeABB(n -> left, x);
  else if(n -> info < x)  n -> right = InsertNodeABB(n -> right, x);

  return n;
}

NodeABB *RemoveNodeABB(NodeABB *n, elem x){
  if(n == NULL)  return NULL;
  int children = 0;
  NodeABB *aux, *AuxParent;

  if(n -> info > x) n -> left = RemoveNodeABB(n -> left, x);
  else if(n -> info < x) n -> right =  RemoveNodeABB(n -> right, x);
  else if(n->info == x){
    if(n -> left != NULL)  ++children;
    if(n -> right != NULL)  ++children;

    if(children == 0){
      free(n);
      n = NULL;
      return n;
    }
    else if(children == 1){
      aux = (n -> left != NULL) ? n -> left : n -> right;;
      free(n);
      n = aux;
    }
    else{
      aux = n -> left;
      while(aux -> right != NULL){
        aux = aux -> right;
      }

      n -> info = aux -> info;
      n -> left = RemoveNodeABB(n -> left, n -> info);
    }

  }

  return n;
}
