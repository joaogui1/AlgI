#include<stdlib.h>

typedef struct{
  char** data;
  int tam, pos;
}pilha;

pilha* cria_pilha();

int tamanho(pilha *p);

int empilha(pilha *p, char *elemento);

char* desempilha(pilha *p);
