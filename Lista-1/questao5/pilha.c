#include "pilha.h"
#include <stdio.h>
#include <string.h>

pilha* cria_pilha(){
  pilha *p = calloc(1, sizeof(pilha));
  p->tam = 4;
  p->pos = 0;
  p->data = calloc(p->tam, sizeof(char*));
  return p;
}

int tamanho(pilha *p){
  return p->pos;
}

int empilha(pilha *p, char *elemento){
  if(p->tam == p->pos){
    p->tam += 4;
    p->data = realloc(p->data, (p->tam)*sizeof(char**));
    if(p->data == NULL) return 1;
  }

  p->data[p->pos] = calloc(10, sizeof(char));
  strcpy(p->data[p->pos], elemento);
  ++p->pos;
  return 0;
}

char* desempilha(pilha *p){
  char* topo;
  if(p->pos == 0)  return NULL;
  topo = calloc(10, sizeof(char));
  strcpy(topo, p->data[p->pos - 1]);
  --p->pos;
  return topo;
}
