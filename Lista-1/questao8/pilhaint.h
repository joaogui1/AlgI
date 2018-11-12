#include<stdlib.h>

typedef struct{
  int *data;	
  int tam, pos;
}pilha;

pilha* cria_pilha();

int tamanho(pilha *p);

int empilha(pilha *p, int elemento);

int desempilha(pilha *p);
