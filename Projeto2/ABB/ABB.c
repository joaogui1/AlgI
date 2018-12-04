#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  elem info;
  struct node *left, *right;
} Node;

struct _abb{
  Node *root;
};

Node *CreateNodeABB(elem x){
  Node  *ret;
  ret = calloc(1, sizeof(Node));
  ret->info = x;
  return ret;
}

void DestroyNodeABB(Node *n){
  if(n == NULL) return;
  if(n->right != NULL)  DestroyNodeABB(n->right);
  if(n->left != NULL)  DestroyNodeABB(n->left);
  free(n);
}

Node *SearchNodeABB(Node *n, elem x){
  if(n == NULL || n->info == x) return n;
  if(n->info > x) return SearchNodeABB(n->left, x);
  if(n->info < x) return SearchNodeABB(n->right, x);
  return NULL;
}

Node *InsertNodeABB(Node *n, elem x, int *erro){
  if(n == NULL) n = CreateNodeABB(x);
  else if(n->info > x)  n->left = InsertNodeABB(n->left, x, erro);
  else if(n->info < x)  n->right = InsertNodeABB(n->right, x, erro);
  else *erro = 1;

  return n;
}

Node *RemoveNodeABB(Node *n, elem x, int *erro){
  if(n == NULL){
    *erro = 1;
    return NULL;
  }
  int children = 0;
  Node *aux, *AuxParent;

  if(n->info > x) n->left = RemoveNodeABB(n->left, x, erro);
  else if(n->info < x) n->right =  RemoveNodeABB(n->right, x, erro);
  else if(n->info == x){
    if(n->left != NULL)  ++children;
    if(n->right != NULL)  ++children;

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
      n->left = RemoveNodeABB(n->left, n->info, erro);
    }

  }

  return n;
}

ABB *createABB(){
  ABB *ret;
  ret = calloc(1, sizeof(ABB));
  return ret;
}

void destroyABB(ABB *t){
  DestroyNodeABB(t->root);
}

int searchABB(ABB *t, elem x){
  Node* ans = SearchNodeABB(t->root, x);
  return ans != NULL;
}

int insertABB(ABB *t, elem x){
  int erro = 0;
  t->root = InsertNodeABB(t->root, x, &erro);
  return erro;
}

int RemoveABB(ABB *t, elem x){
  int erro = 0;
  t->root = RemoveNodeABB(t->root, x, &erro);
  return erro;
}
