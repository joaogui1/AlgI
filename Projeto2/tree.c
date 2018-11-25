#include "tree.h"
Tree *create(){
  Tree *ret;
  ret = calloc(1, sizeof(Tree));
  return ret;
}
void destroy(Tree *t){
  DestroyNode(t -> root);
}
Node *search(Tree *t, elem x){
  searchNode(t -> root, x);
}

Node balance(node *root){
  if(root -> right == NULL) return root; //se for uma folha, retorna

  node *parent, *baby = root, *giant = root, auxleft, auxright;

  while(giant != NULL){ //encontra o meio da arvore
    parent = baby;
    baby = baby -> right;
    giant = (giant -> right != NULL)?(giant -> right) -> right: giant -> right;
  }

  parent -> right = NULL; //desliga a parte anterior do caminho
  auxleft = balance(parent); //balancea o caminho que vem antes
  auxright = balance(baby -> right) //balancea o caminho que vem depois
  baby -> left = auxleft; //liga a árvore balanceada da esquerdo no lado esquerdo
  baby -> right = auxright; //liga a árvore balanceada da direita no lado direita
  return baby;
}
