#include "node.h"

Node *CreateNode(elem x, int BF){
  Node  *ret;
  ret = calloc(1, sizeof(Node));
  ret -> info = x;
  ret -> BalanceFactor = BF;
  return ret;
}

void DestroyNode(Node *n){
  if(n == NULL) return;
  if(n -> right != NULL)  DestroyNode(n -> right);
  if(n -> left != NULL)  DestroyNode(n -> left);
  free(n);
}
Node *SearchNode(Node *n, elem x){
  if(n == NULL || n -> info == x) return n;
  if(n -> info > x) return SearchNode(n -> left, x);
  if(n -> info < x) return SearchNode(n -> right, x);
  return NULL;
}

void LeftRotation(Node **n){
  Node *NewRoot, *reallocate;
  NewRoot = (*n) -> right;
  reallocate = NewRoot -> left;
  NewRoot -> left = *n;
  (*n) -> right = reallocate;
  *n = NewRoot;
  return;
}


void RightRotation(Node **n){
  Node *NewRoot, *reallocate;
  NewRoot = (*n) -> left;
  reallocate = NewRoot -> right;
  NewRoot -> right = *n;
  (*n) -> left = reallocate;
  *n = NewRoot;
  return;
}

void LeftRightRotation(Node **n){
  LeftRotation(&((*n) -> left));
  RightRotation(n);
}

void RightLeftRotation(Node **n){
  RightRotation(&((*n) -> right));
  LeftRotation(n);
}


int InsertNode(Node **n, elem x){
  if(*n == NULL){
    *n = CreateNode(x);
    return *n == NULL;
  }
  if((*n) -> info == x)
    return 1;
  if((*n) -> info > x) return InsertNode(&((*n) -> left), x);
  if((*n) -> info < x) return InsertNode(&((*n) -> right), x);
}

int RemoveNode(Node **n, elem x){
  if(*n == NULL)  return 1;

  int children = 0;
  Node *aux, *AuxParent;
  if((*n)->info == x){
    if((*n) -> left != NULL)  ++children;
    if((*n) -> right != NULL)  ++children;

    if(children == 0){
      free(*n);
      *n = NULL;
      return 0;
    }
    else if(children == 1){
      aux = *n;
      *n = ((*n) -> left != NULL) ? (*n) -> left : (*n) -> right;
      free(aux);
      return 0;
    }
    else{
      aux = (*n) -> left;
      AuxParent = *n;
      while(aux -> right != NULL){
        AuxParent = aux;
        aux = aux -> right;
      }
      (*n) -> info = aux -> info;
      return (AuxParent -> left == aux) ? RemoveNode(&(AuxParent -> left), aux->info) : (&(AuxParent -> right), aux -> info);
    }
  }
  if((*n) -> info > x) return RemoveNode(&((*n) -> left), x);
  if((*n) -> info < x) return RemoveNode(&((*n) -> right), x);
}
