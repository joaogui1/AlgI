#include "lista.h"
#include <stdio.h>

int josephus(node *n, int k){
  //printf("%d\n", n->value);
  //if(n -> next == n || n -> next == NULL){
  //  return n->value;
  //}
  //node *killed = n -> next;
  // for(int i = 1; i < k; ++i){
  //   n = n -> next;
  //   killed = killed -> next;
  // }
  //remove_node(n, killed);
  //return josephus(n -> next, k);
  return 1;
}

int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  list *l;
  node *no;
  l = new_list();
  no = new_node(1);
  for(int i = 2; i <= n; ++i){
    no -> value = i;
    add_node(l, no);
  }
  free(no);
  printf("%d\n", josephus(l -> start, k - 1));
  return 0;
}
