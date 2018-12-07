#include "BST.h"
#include <stdio.h>
#include <time.h>

int main(){
  BST *t;
  int n = 100000, aux;
  t = createBST();
  clock_t c;
  
  c = clock();
  for(int i = 0; i < n; ++i){
    insertBST(t, i);
  }
  c = clock() - c;

  // printBST(t); 
  printf("%lf\n", c/(float)CLOCKS_PER_SEC);
  // for(int i = 0; i < q; ++i){
  //   scanf("%d", &aux);
  //   RemoveBST(t, aux);
  //   in_order(t -> root);
  //   printf("\n");
  // }

  destroyBST(t);
}
