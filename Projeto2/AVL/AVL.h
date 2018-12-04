//basicamente um wrapper ao redor de node
#include "avlnode.h"
typedef struct{
  NodeAVL *root;
}AVL;

AVL *createAVL();
void destroyAVL(AVL *t);
NodeAVL *searchAVL(AVL *t, elem x);
NodeAVL *insertAVL(AVL *t, elem x);
NodeAVL *RemoveAVL(AVL *t, elem x);
