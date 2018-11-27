#ifndef NODE_H
#define NODE_H

#define elem int
#include <stdlib.h>

typedef struct node{
  elem info;
  int height;
  struct node *left, *right;
} Node;


int max(int a, int b);
Node *CreateNode(elem x);
void DestroyNode(Node *n);
int GetHeight(Node *n);
Node * LeftRotation(Node *n);
Node * RightRotation(Node *n);
Node * LeftRightRotation(Node *n);
Node * RightLeftRotation(Node *n);
Node *SearchNode(Node *n, elem x);
Node * InsertNode(Node *n, elem x);
Node * RemoveNode(Node *n, elem x);
#endif
