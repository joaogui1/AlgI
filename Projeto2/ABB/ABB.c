#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  elem info;
  struct _node *left, *right;
} node;

struct _abb {
  node *root;
};

node *createNodeABB(elem x) {
  node *ret;
  ret = calloc(1, sizeof(node));
  ret->left = ret->right = NULL;
  ret->info = x;
  return ret;
}

void destroyNodeABB(node *n) {
  if(n == NULL) return;
  if(n->right != NULL)  destroyNodeABB(n->right);
  if(n->left != NULL)  destroyNodeABB(n->left);
  free(n);
}

node *searchNodeABB(node *n, elem x) {
  if(n == NULL || n->info == x) return n;
  if(n->info > x) return searchNodeABB(n->left, x);
  if(n->info < x) return searchNodeABB(n->right, x);
  return NULL;
}

node *insertNodeABB(node *n, elem x, int *erro) {
  if(n == NULL) n = createNodeABB(x);
  else if(n->info > x)  n->left = insertNodeABB(n->left, x, erro);
  else if(n->info < x)  n->right = insertNodeABB(n->right, x, erro);
  else *erro = 1;
  return n;
}

int getChildrenABB(node* n) {
  return (n->left != NULL) + (n->right != NULL);
}

node *getGreatestLeft(node* n) {
  node* aux = n->left;
  while(aux->right != NULL) {
    aux = aux->right;
  }
  return aux;
}
 
node *removeNodeABB(node *n, elem x, int *erro){
  if(n == NULL) {
    *erro = 1;
    return NULL;
  }

  int children = 0;
  node *aux;

  if(n->info > x) n->left = removeNodeABB(n->left, x, erro);
  else if(n->info < x) n->right =  removeNodeABB(n->right, x, erro);
  else if(n->info == x) {
    children = getChildrenABB(n);

    if(children == 0) {
      free(n);
      n = NULL;
      return n;
    } else if(children == 1) {
      aux = (n->left != NULL) ? n->left : n->right;;
      free(n);
      n = aux;
    } else {
      aux = getGreatestLeft(n);
      n->info = aux->info;
      n->left = removeNodeABB(n->left, n->info, erro);
    }
  }

  return n;
}

ABB *createABB() {
  ABB *ret;
  ret = calloc(1, sizeof(ABB));
  return ret;
}

void destroyABB(ABB *t) {
  destroyNodeABB(t->root);
}

int searchABB(ABB *t, elem x) {
  node* ans = searchNodeABB(t->root, x);
  return ans != NULL;
}

int insertABB(ABB *t, elem x) {
  int erro = 0;
  t->root = insertNodeABB(t->root, x, &erro);
  return erro;
}

int removeABB(ABB *t, elem x) {
  int erro = 0;
  t->root = removeNodeABB(t->root, x, &erro);
  return erro;
}

void abb_print_debug(node* n, int depth) {
  if (n == NULL) {
    putchar('\n');
    return;
  }
  abb_print_debug(n->right, depth + 1);
  for (int i = 0; i < depth; i++) putchar('\t');
  printf("[%d]\n", n->info);
  abb_print_debug(n->left, depth + 1);
}

void printAbb(ABB* t) {
  abb_print_debug(t->root, 0);
}