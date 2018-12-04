#ifndef NODE_H
#define NODE_H

typedef elem int;

typedef struct nodeAVL{
  elem info;
  int height;
  struct nodeAVL *left, *right;
} NodeAVL;


int max(int a, int b);
NodeAVL *CreateNodeAVL(elem x);
void DestroyNodeAVL(NodeAVL *n);
int GetHeight(NodeAVL *n);
NodeAVL * LeftRotation(NodeAVL *n);
NodeAVL * RightRotation(NodeAVL *n);
NodeAVL * LeftRightRotation(NodeAVL *n);
NodeAVL * RightLeftRotation(NodeAVL *n);
NodeAVL *SearchNodeAVL(NodeAVL *n, elem x);
NodeAVL * InsertNodeAVL(NodeAVL *n, elem x);
NodeAVL * RemoveNodeAVL(NodeAVL *n, elem x);
#endif
