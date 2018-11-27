#define elem int
#include <stdlib.h>
typedef struct node{
  elem info;
  int BalanceFactor;
  struct node *left, *right;
} Node;
Node *CreateNode(elem x);
void DestroyNode(Node *n);
Node *SearchNode(Node *n, elem x);
int InsertNode(Node **n, elem x);
int RemoveNode(Node **n, elem x);
