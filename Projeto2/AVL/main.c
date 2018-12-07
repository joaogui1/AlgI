#include "AVL.h"
#include <stdio.h>

int main(){
  AVL *t;
  int n, q, aux;
  t = createAVL();
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i){
    scanf("%d", &aux);
    insertAVL(t, aux);
  }

  for(int i = 0; i < q; ++i){
    scanf("%d", &aux);
    removeAVL(t, aux);
    printf("\n");
  }
  destroyAVL(t);
}
