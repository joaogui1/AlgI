#include "node.h"
#include <stdio.h>

int max(int a, int b){
  return (a > b)?a:b;
}

int abs(int a){
  return a > 0 ? a : -a;
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
  if(n == NULL) return -1;
  return n -> height;
}

int GetBalance(Node *n){
  return GetHeight(n -> left) - GetHeight(n -> right);
}

Node *SearchNode(Node *n, elem x){
  if(n == NULL || n -> info == x) return n;
  if(n -> info > x) return SearchNode(n -> left, x);
  if(n -> info < x) return SearchNode(n -> right, x);
  return NULL;
}

Node *LeftRotation(Node *n){
  Node *NewRoot = n -> right;
  n -> right = NewRoot -> left;
  NewRoot -> left = n;

  n -> height = 1 + max(GetHeight(n -> left), GetHeight(n -> right));
  NewRoot -> height = 1 + max(GetHeight(NewRoot -> left), GetHeight(NewRoot -> right));

  return NewRoot;
}

Node *RightRotation(Node *n){
  Node *NewRoot = n -> left;
  n -> left = NewRoot -> right;
  NewRoot -> right = n;

  n -> height = 1 + max(GetHeight(n -> left), GetHeight(n -> right));
  NewRoot -> height = 1 + max(GetHeight(NewRoot -> left), GetHeight(NewRoot -> right));

  return NewRoot;
}

Node *LeftRightRotation(Node *n){
  n -> left = LeftRotation(n -> left);
  return RightRotation(n);
}

Node *RightLeftRotation(Node *n){
  n -> right = RightRotation(n -> right);
  return LeftRotation(n);
}

Node *BringBalance(Node *n){
  int balance = GetBalance(n);

  if(balance >= 0)
    return GetBalance(n -> left) < 0 ? n = LeftRightRotation(n) : RightRotation(n);
  else
    return GetBalance(n -> right) < 0 ? n = RightLeftRotation(n) : LeftRotation(n);
}

Node *InsertNode(Node *n, elem x){
  int BalanceFactor;
  if(n == NULL) n = CreateNode(x);
  else if(n -> info > x) n -> left = InsertNode(n -> left, x);
  else if(n -> info < x) n -> right = InsertNode(n -> right, x);
  else  return n;

  n -> height = 1 + max(GetHeight(n -> left), GetHeight(n -> right));
  BalanceFactor = GetBalance(n);
  if(abs(BalanceFactor) > 1)  return BringBalance(n);

  return n;
}

Node *RemoveNode(Node *n, elem x){
  if(n == NULL)  return NULL;
  int children = 0;
  Node *aux, *AuxParent;

  if(n -> info > x) n -> left = RemoveNode(n -> left, x);
  if(n -> info < x) n -> right =  RemoveNode(n -> right, x);

  if(n->info == x){
    if(n -> left != NULL)  ++children;
    if(n -> right != NULL)  ++children;

    if(children == 0){
      free(n);
      n = NULL;
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
      n -> left = RemoveNode(n -> left, n -> info);
    }

  }

  if(n == NULL)  return n;

  n -> height = 1 + (GetHeight(n -> left), GetHeight(n -> right));

  int   BalanceFactor = GetBalance(n);
  if(abs(BalanceFactor) > 1)  return BringBalance(n);


  return n;
}
