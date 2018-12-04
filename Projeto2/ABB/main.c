#include "ABB.h"
#include <stdio.h>

void in_order(NodeABB *n){
  if(n == NULL) return;
  in_order(n -> left);
  printf("%d ", n -> info);
  in_order(n -> right);
}

int main(){
  ABB *t;
  int n, q, aux;
  t = createABB();
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i){
    scanf("%d", &aux);
    insertABB(t, aux);
  }
  for(int i = 0; i < q; ++i){
    scanf("%d", &aux);
    RemoveABB(t, aux);
    in_order(t -> root);
    printf("\n");
  }

  destroyABB(t);
}
