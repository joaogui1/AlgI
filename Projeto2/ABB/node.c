#include <stdlib.h>
#include "node.h"

Node *CreateNode(elem x){
  Node  *ret;
  ret = calloc(1, sizeof(Node));
  ret -> info = x;
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
      return (AuxParent -> left == aux) ? RemoveNode(&(AuxParent -> left), aux->info) : RemoveNode(&(AuxParent -> right), aux -> info);
    }
  }
  if((*n) -> info > x) return RemoveNode(&((*n) -> left), x);
  if((*n) -> info < x) return RemoveNode(&((*n) -> right), x);
}
