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
void LeftRotation(Node **n);
void RightRotation(Node **n);
void LeftRightRotation(Node **n);
void RightLeftRotation(Node **n);
Node *SearchNode(Node *n, elem x);
int InsertNode(Node **n, elem x);
int RemoveNode(Node **n, elem x);

#endif
