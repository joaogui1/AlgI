#include "node.h"
#include <stdio.h>

int max(int a, int b){
  return (a > b)?a:b;
}

Node *CreateNode(elem x){
  Node  *ret;
  ret = calloc(1, sizeof(Node));
  ret -> info = x;
  ret -> height = 1;
  return ret;
}

void DestroyNode(Node *n){
  if(n == NULL) return;
  if(n -> right != NULL)  DestroyNode(n -> right);
  if(n -> left != NULL)  DestroyNode(n -> left);
  free(n);
}

int GetHeight(Node *n){
  if(n == NULL) return 0;
  return n -> height;
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

  NewRoot -> height = 1 + max(GetHeight(NewRoot -> left), GetHeight(NewRoot -> right));
  (*n) -> height = 1 + max(GetHeight((*n) -> left), GetHeight((*n) -> right));

  *n = NewRoot;
  return;
}

void RightRotation(Node **n){
  Node *NewRoot, *reallocate;
  NewRoot = (*n) -> left;
  reallocate = NewRoot -> right;

  NewRoot -> right = *n;
  (*n) -> left = reallocate;

  (*n) -> height = 1 + max((*n) -> left -> height, (*n) -> right -> height);
  NewRoot -> height = 1 + max(NewRoot -> left -> height, NewRoot -> right -> height);


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
  int ret = 0, BalanceFactor;
  if(*n == NULL){
    *n = CreateNode(x);
    return *n == NULL;
  }

  if((*n) -> info == x)
    return 1;
  if((*n) -> info > x) ret = InsertNode(&((*n) -> left), x);
  if((*n) -> info < x) ret = InsertNode(&((*n) -> right), x);

  (*n) -> height = 1 + max(GetHeight((*n) -> left), GetHeight((*n) -> right));
  BalanceFactor = GetHeight((*n) -> left) - GetHeight((*n) -> right);

  if(BalanceFactor > 1 && x < (*n) -> left -> info)
    RightRotation(n);

  else if(BalanceFactor < -1 && x > (*n) -> right -> info)
    LeftRotation(n);

  else if(BalanceFactor > 1 && x > (*n) -> left -> info)
    LeftRightRotation(n);

  else if(BalanceFactor < -1 && x < (*n) -> right -> info)
    RightLeftRotation(n);

  return ret;
}

int RemoveNode(Node **n, elem x){
  if(*n == NULL)  return 1;
  int children = 0, ret;
  Node *aux, *AuxParent;

  if((*n) -> info > x) return RemoveNode(&((*n) -> left), x);
  if((*n) -> info < x) return RemoveNode(&((*n) -> right), x);

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
      ret = (AuxParent -> left == aux) ? RemoveNode(&(AuxParent -> left), aux->info) : RemoveNode(&(AuxParent -> right), aux -> info);
    }
  }

  if((*n) == NULL)  return ret;

  (*n) -> height = 1 + (GetHeight((*n) -> left), GetHeight((*n) -> right));
  int BalanceFactor = GetHeight((*n) -> left) - GetHeight((*n) -> right);

  if(BalanceFactor > 1){
    int LeftBalance = GetHeight((*n) -> left -> left) - GetHeight((*n) -> left -> right);
    if(LeftBalance >= 0)  RightRotation(n);
    else  LeftRightRotation(n);
  }

  else if(BalanceFactor < -1){
    int RightBalance = GetHeight((*n) -> right -> left) - GetHeight((*n) -> right -> right);
    if(RightBalance >= 0)  LeftRotation(n);
    else  RightLeftRotation(n);
  }

  return 0;
}
