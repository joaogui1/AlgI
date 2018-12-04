#include "AVL.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  elem info;
  int height;
  struct node *left, *right;
} Node;

struct _avl{
  Node *root;
};

int max(int a, int b){
  return (a > b)?a:b;
}

int abs(int a){
  return a > 0 ? a : -a;
}

Node* CreateNodeAVL(elem x){
  Node  *ret;
  ret = calloc(1, sizeof(Node));
  ret->info = x;
  ret->height = 1;
  return ret;
}

void DestroyNodeAVL(Node *n){
  if(n == NULL) return;
  if(n->right != NULL)  DestroyNodeAVL(n->right);
  if(n->left != NULL)  DestroyNodeAVL(n->left);
  free(n);
}

int GetHeight(Node *n){
  if(n == NULL) return -1;
  return n->height;
}

int GetBalance(Node *n){
  return GetHeight(n->left) - GetHeight(n->right);
}

Node *SearchNodeAVL(Node *n, elem x){
  if(n == NULL || n->info == x) return n;
  if(n->info > x) return SearchNodeAVL(n->left, x);
  if(n->info < x) return SearchNodeAVL(n->right, x);
  return NULL;
}

Node *LeftRotation(Node *n){
  Node *NewRoot = n->right;
  n->right = NewRoot->left;
  NewRoot->left = n;

  n->height = 1 + max(GetHeight(n->left), GetHeight(n->right));
  NewRoot->height = 1 + max(GetHeight(NewRoot->left), GetHeight(NewRoot->right));

  return NewRoot;
}

Node *RightRotation(Node *n){
  Node *NewRoot = n->left;
  n->left = NewRoot->right;
  NewRoot->right = n;

  n->height = 1 + max(GetHeight(n->left), GetHeight(n->right));
  NewRoot->height = 1 + max(GetHeight(NewRoot->left), GetHeight(NewRoot->right));

  return NewRoot;
}

Node *LeftRightRotation(Node *n){
  n->left = LeftRotation(n->left);
  return RightRotation(n);
}

Node *RightLeftRotation(Node *n){
  n->right = RightRotation(n->right);
  return LeftRotation(n);
}

Node *BringBalance(Node *n){
  int balance = GetBalance(n);
  if(balance >= 0)
    return GetBalance(n->left) < 0 ? n = LeftRightRotation(n) : RightRotation(n);
  else
    return GetBalance(n->right) > 0 ? n = RightLeftRotation(n) : LeftRotation(n);
}

Node *InsertNodeAVL(Node *n, elem x){
  int BalanceFactor;
  if(n == NULL) n = CreateNodeAVL(x);
  else if(n->info > x)  n->left = InsertNodeAVL(n->left, x);
  else if(n->info < x)  n->right = InsertNodeAVL(n->right, x);
  else  return n;

  n->height = 1 + max(GetHeight(n->left), GetHeight(n->right));
  BalanceFactor = GetBalance(n);
  if(abs(BalanceFactor) > 1)  return  BringBalance(n);

  return n;
}

int GetChildren(Node* n){
    return (n->left != NULL)  + (n->right != NULL);
}

Node *RemoveNodeAVL(Node *n, elem x){
  if(n == NULL)  return NULL;
  int children = 0;
  Node *aux, *AuxParent;

  if(n->info > x) n->left = RemoveNodeAVL(n->left, x);
  else if(n->info < x) n->right =  RemoveNodeAVL(n->right, x);
  else if(n->info == x){
    int children = GetChildren(n);
    
    if(children == 0){
      free(n);
      n = NULL;
      return n;
    }
    else if(children == 1){
      aux = (n->left != NULL) ? n->left : n->right;;
      free(n);
      n = aux;
    }
    else{
      aux = n->left;
      while(aux->right != NULL){
        aux = aux->right;
      }

      n->info = aux->info;
      n->left = RemoveNodeAVL(n->left, n->info);
    }

  }

  n->height = 1 + max(GetHeight(n->left), GetHeight(n->right));
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
  DestroyNodeAVL(t->root);
}

int searchAVL(AVL *t, elem x){
  Node* ans = SearchNodeAVL(t->root, x);
  return (ans != NULL);
}

int insertAVL(AVL *t, elem x){
  t->root = InsertNodeAVL(t->root, x);
  return (t->root != NULL);
}

int RemoveAVL(AVL *t, elem x){
  t->root = RemoveNodeAVL(t->root, x);
  return 0;
}