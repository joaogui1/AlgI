#include "node.h"
void DestroyNode(Node *n){
  if(n == NULL) return;
  if(n -> right != NULL)  DestroyNode(n -> right);
  if(n -> left != NULL)  DestroyNode(n -> left);
  free(n);
}
Node *searchNode(Node *n, elem x){
  if(n == NULL || n -> info == x) return n;
  if(n -> info > x) return searchNode(n -> left, x); //queria ternario
  if(n -> info < x) return searchNode(n -> right, x);
  return NULL; //default inutil
}
