#include "AVL.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
  elem info;
  int height;
  struct _node *left, *right;
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

Node* createNodeAVL(elem x){
  Node  *ret;
  ret = calloc(1, sizeof(Node));
  ret->info = x;
  ret->height = 1;
  return ret;
}

void destroyNodeAVL(Node *n){
  if(n == NULL) return;
  if(n->right != NULL)  destroyNodeAVL(n->right);
  if(n->left != NULL)  destroyNodeAVL(n->left);
  free(n);
}

int getHeight(Node *n){
  if(n == NULL) return -1;
  return n->height;
}

int getBalance(Node *n){
  return getHeight(n->left) - getHeight(n->right);
}

Node *searchNodeAVL(Node *n, elem x){
  if(n == NULL || n->info == x) return n;
  if(n->info > x) return searchNodeAVL(n->left, x);
  if(n->info < x) return searchNodeAVL(n->right, x);
  return NULL;
}

Node *leftRotation(Node *n){
  Node *NewRoot = n->right;
  n->right = NewRoot->left;
  NewRoot->left = n;

  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  NewRoot->height = 1 + max(getHeight(NewRoot->left), getHeight(NewRoot->right));

  return NewRoot;
}

Node *rightRotation(Node *n){
  Node *NewRoot = n->left;
  n->left = NewRoot->right;
  NewRoot->right = n;

  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  NewRoot->height = 1 + max(getHeight(NewRoot->left), getHeight(NewRoot->right));

  return NewRoot;
}

Node *leftRightRotation(Node *n){
  n->left = leftRotation(n->left);
  return rightRotation(n);
}

Node *rightLeftRotation(Node *n){
  n->right = rightRotation(n->right);
  return leftRotation(n);
}

Node *bringBalance(Node *n){
  int balance = getBalance(n);
  if(balance >= 0)
    return getBalance(n->left) < 0 ? n = leftRightRotation(n) : rightRotation(n);
  else
    return getBalance(n->right) > 0 ? n = rightLeftRotation(n) : leftRotation(n);
}

Node *insertNodeAVL(Node *n, elem x, int *erro){
  int BalanceFactor;
  if(n == NULL) n = createNodeAVL(x);
  else if(n->info > x)  n->left = insertNodeAVL(n->left, x, erro);
  else if(n->info < x)  n->right = insertNodeAVL(n->right, x, erro);
  else{
    *erro = 1;
    return n;
  }
  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  BalanceFactor = getBalance(n);
  if(abs(BalanceFactor) > 1)  return  bringBalance(n);

  return n;
}

int getChildrenAVL(Node* n){
    return (n->left != NULL)  + (n->right != NULL);
}

Node *removeNodeAVL(Node *n, elem x, int *erro){
  if(n == NULL){
    *erro = 1;
    return NULL;
  }
  int children = 0;
  Node *aux, *AuxParent;

  if(n->info > x) n->left = removeNodeAVL(n->left, x, erro);
  else if(n->info < x) n->right =  removeNodeAVL(n->right, x, erro);
  else if(n->info == x){
    int children = getChildrenAVL(n);

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
      n->left = removeNodeAVL(n->left, n->info, erro);
    }

  }

  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  int   BalanceFactor = getBalance(n);
  if(abs(BalanceFactor) > 1)  return bringBalance(n);

  return n;
}

AVL *createAVL(){
  AVL *ret;
  ret = calloc(1, sizeof(AVL));
  return ret;
}

void destroyAVL(AVL *t){
  destroyNodeAVL(t->root);
}

int searchAVL(AVL *t, elem x){
  Node* ans = searchNodeAVL(t->root, x);
  return (ans != NULL);
}

int insertAVL(AVL *t, elem x){
  int erro = 0;
  t->root = insertNodeAVL(t->root, x, &erro);
  return erro;
}

int removeAVL(AVL *t, elem x){
  int erro = 0;
  t->root = removeNodeAVL(t->root, x, &erro);
  return erro;
}
