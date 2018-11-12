#include "lista.h"
node *new_node(int value){
  node *ret;
  ret = calloc(1, sizeof(node*));
  ret -> value = value;
  return ret;
}

list *new_list(){
  list *ret;
  ret = calloc(1, sizeof(list*));
  ret -> start = new_node(1);
  ret -> end = ret -> start;
  ret -> start -> next = ret -> end;
  return ret;
}

void free_list(list *l, int n){
  if(n == 1){
    free(l -> start);
    free(l);
    return;
  }
  node *tmp = l-> start -> next;
  free(l -> start);
  l -> start = tmp;
  free_list(l, n - 1);
}

void add_node(list *l, node *n){
  l -> end = n;
  l -> end -> next = l -> start;
}

void remove_node(node *ant, node *n){
  ant -> next = n -> next;
  free(n);
}
