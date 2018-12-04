//basicamente um wrapper ao redor de node
#include <stdlib.h>

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

typedef struct{
  NodeAVL *root;
}AVL;

AVL *createAVL();
void destroyAVL(AVL *t);
NodeAVL *searchAVL(AVL *t, elem x);
NodeAVL *insertAVL(AVL *t, elem x);
NodeAVL *RemoveAVL(AVL *t, elem x);
