#include <stdio.h>
#include "pilha.h"

int check(char *s){
  int is_b = 0;
  char *aux, a[2] = {'a', '\0'} ;
  pilha *p = cria_pilha();
  for(char *t = s; *t != '\0'; ++t){
    if(*t != 'a' && *t != 'b')  return 1;
    if(is_b && *t != 'b') return 1;
    if(is_b && *t == 'b') {
      aux = desempilha(p);
      if(aux == NULL) return 1;
    }
    else if(*t == 'b'){
      is_b = 1;
      aux = desempilha(p);
      if(aux == NULL) return 1;
    }
    else if(*t == 'a')  empilha(p, a);
  }
  return (tamanho(p) > 0);
}

int main() {
  char s[10];
  scanf("%s", s);
  if(check(s) == 1) printf("Nao\n");
  else  printf("Sim\n";
  return 0;
}
