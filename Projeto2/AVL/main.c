#include "AVL.h"
#include <stdio.h>

void in_order(NodeAVL *n){
  if(n == NULL) return;
  in_order(n -> left);
  printf("%d %d\n", n -> info, n -> height);
  in_order(n -> right);
}

int main(){
  AVL *t;
  int n, q, aux;
  t = createAVL();
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i){
    scanf("%d", &aux);
    insertAVL(t, aux);
  }

  in_order(t -> root);
  for(int i = 0; i < q; ++i){
    scanf("%d", &aux);
    RemoveAVL(t, aux);
    in_order(t -> root);
    printf("\n");
  }
  destroyAVL(t);
}
