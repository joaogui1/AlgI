#ifndef NODE_H
#define NODE_H

#define elem int

typedef struct node{
  elem info;
  struct node *left, *right;
} Node;

Node *CreateNode(elem x);
void DestroyNode(Node *n);
Node *SearchNode(Node *n, elem x);
int InsertNode(Node **n, elem x);
int RemoveNode(Node **n, elem x);

#endif