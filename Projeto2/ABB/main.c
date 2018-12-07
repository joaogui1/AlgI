#include "ABB.h"
#include <stdio.h>
#include <time.h>

// void in_order(Node *n){
//   if(n == NULL) return;
//   in_order(n -> left);
//   printf("%d ", n -> info);
//   in_order(n -> right);
// }

int main(){
  ABB *t;
  int n = 100000, aux;
  t = createABB();
  clock_t c;
  
  c = clock();
  for(int i = 0; i < n; ++i){
    insertABB(t, i);
  }
  c = clock() - c;

  // printAbb(t); 
  printf("%lf\n", c/(float)CLOCKS_PER_SEC);
  // for(int i = 0; i < q; ++i){
  //   scanf("%d", &aux);
  //   RemoveABB(t, aux);
  //   in_order(t -> root);
  //   printf("\n");
  // }

  destroyABB(t);
}
