#include "AVL.h"

int max(int a, int b){
  return (a > b)?a:b;
}

int abs(int a){
  return a > 0 ? a : -a;
}

NodeAVL *CreateNodeAVL(elem x){
  NodeAVL  *ret;
  ret = calloc(1, sizeof(NodeAVL));
  ret -> info = x;
  ret -> height = 1;
  return ret;
}

void DestroyNodeAVL(NodeAVL *n){
  if(n == NULL) return;
  if(n -> right != NULL)  DestroyNodeAVL(n -> right);
  if(n -> left != NULL)  DestroyNodeAVL(n -> left);
  free(n);
}

int GetHeight(NodeAVL *n){
  if(n == NULL) return -1;
  return n -> height;
}

int GetBalance(NodeAVL *n){
  return GetHeight(n -> left) - GetHeight(n -> right);
}

NodeAVL *SearchNodeAVL(NodeAVL *n, elem x){
  if(n == NULL || n -> info == x) return n;
  if(n -> info > x) return SearchNodeAVL(n -> left, x);
  if(n -> info < x) return SearchNodeAVL(n -> right, x);
  return NULL;
}

NodeAVL *LeftRotation(NodeAVL *n){
  NodeAVL *NewRoot = n -> right;
  n -> right = NewRoot -> left;
  NewRoot -> left = n;

  n -> height = 1 + max(GetHeight(n -> left), GetHeight(n -> right));
  NewRoot -> height = 1 + max(GetHeight(NewRoot -> left), GetHeight(NewRoot -> right));

  return NewRoot;
}

NodeAVL *RightRotation(NodeAVL *n){
  NodeAVL *NewRoot = n -> left;
  n -> left = NewRoot -> right;
  NewRoot -> right = n;

  n -> height = 1 + max(GetHeight(n -> left), GetHeight(n -> right));
  NewRoot -> height = 1 + max(GetHeight(NewRoot -> left), GetHeight(NewRoot -> right));

  return NewRoot;
}

NodeAVL *LeftRightRotation(NodeAVL *n){
  n -> left = LeftRotation(n -> left);
  return RightRotation(n);
}

NodeAVL *RightLeftRotation(NodeAVL *n){
  n -> right = RightRotation(n -> right);
  return LeftRotation(n);
}

NodeAVL *BringBalance(NodeAVL *n){
  int balance = GetBalance(n);
  if(balance >= 0)
    return GetBalance(n -> left) < 0 ? n = LeftRightRotation(n) : RightRotation(n);
  else
    return GetBalance(n -> right) > 0 ? n = RightLeftRotation(n) : LeftRotation(n);
}

NodeAVL *InsertNodeAVL(NodeAVL *n, elem x){
  int BalanceFactor;
  if(n == NULL) n = CreateNodeAVL(x);
  else if(n -> info > x)  n -> left = InsertNodeAVL(n -> left, x);
  else if(n -> info < x)  n -> right = InsertNodeAVL(n -> right, x);
  else  return n;

  n -> height = 1 + max(GetHeight(n -> left), GetHeight(n -> right));
  BalanceFactor = GetBalance(n);
  if(abs(BalanceFactor) > 1)  return  BringBalance(n);

  return n;
}

NodeAVL *RemoveNodeAVL(NodeAVL *n, elem x){
  if(n == NULL)  return NULL;
  int children = 0;
  NodeAVL *aux, *AuxParent;

  if(n -> info > x) n -> left = RemoveNodeAVL(n -> left, x);
  else if(n -> info < x) n -> right =  RemoveNodeAVL(n -> right, x);
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
      n -> left = RemoveNodeAVL(n -> left, n -> info);
    }

  }

  n -> height = 1 + max(GetHeight(n -> left), GetHeight(n -> right));
  int   BalanceFactor = GetBalance(n);
  if(abs(BalanceFactor) > 1)  return BringBalance(n);

  return n;
}


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
