#include "tree.h"
#include <stdio.h>

void in_order(Node *n){
  if(n == NULL) return;
  in_order(n -> left);
  printf("%d %d\n", n -> info, n -> height);
  in_order(n -> right);
}

int main(){
  Tree *t;
  int n, q, aux;
  t = create();
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i){
    scanf("%d", &aux);
    insert(t, aux);
  }

  in_order(t -> root);
  for(int i = 0; i < q; ++i){
    scanf("%d", &aux);
    Remove(t, aux);
    in_order(t -> root);
    printf("\n");
  }

}
