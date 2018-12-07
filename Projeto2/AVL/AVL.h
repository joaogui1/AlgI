#ifndef AVL_H
#define AVL_H

typedef int elem;
typedef struct _avl AVL;

AVL *createAVL();
void destroyAVL(AVL *t);
int searchAVL(AVL *t, elem x);
int insertAVL(AVL *t, elem x);
int removeAVL(AVL *t, elem x);

#endif
