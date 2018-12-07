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
  node *ret = malloc(sizeof(node));
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
  while(n != NULL && n->info != x){
    if(n->info > x) n = n->left;
    else if(n->info < x) n = n->right;
  }
  return n;
}

int insertNodeABB(node **root, elem x){
  node **n = root;
  while (*n != NULL){
    if ((*n)->info > x) {
      n = &(*n)->left;
    } else if((*n)->info < x) {
      n = &(*n)->right;
    } else {
      return 1;
    }
  }
  *n = createNodeABB(x);
  return 0;
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

int removeNodeABB(node **n, elem x){
  while((*n) != NULL && (*n)->info != x){
    if((*n)->info > x) (*n) = (*n)->left;
    else if((*n)->info < x) (*n) = (*n)->right;
  }

  if((*n) == NULL)  return 1;

  node *aux;
  int children = 0;
  children = getChildrenABB((*n));

  if(children == 0) {
    free((*n));
    (*n) = NULL;
    return 0;
  }
  else if(children == 1) {
    aux = ((*n)->left != NULL) ? (*n)->left : (*n)->right;;
    free((*n));
    (*n) = aux;
  }
  else {
    aux = getGreatestLeft((*n));
    (*n)->info = aux->info;
    removeNodeABB(&(*n)->left, (*n)->info);
  }

  return 0;
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
  return insertNodeABB(&(t->root), x);
}

int removeABB(ABB *t, elem x) {
  return removeNodeABB(&t->root, x);
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
