#include "pilhaint.h"
#include <stdio.h>
#include <string.h>

pilha* cria_pilha(){
  pilha *p = calloc(1, sizeof(pilha));
  p->tam = 4;
  p->pos = 0;
  p->data = calloc(p->tam, sizeof(int));
  return p;
}

int tamanho(pilha *p){
  return p->pos;
}

int empilha(pilha *p, int elemento){
  if(p->tam == p->pos){
    p->tam += 4;
    p->data = realloc(p->data, (p->tam)*sizeof(int*));
    if(p->data == NULL) return 1;
  }

  p->data[p->pos] = elemento;
  ++p->pos;
  return 0;
}

int desempilha(pilha *p){
  int topo;
  if(p->pos == 0)  return -100000000;
  topo = p->data[p->pos - 1];
  --p->pos;
  return topo;
}
