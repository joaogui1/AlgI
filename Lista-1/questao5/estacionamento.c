#include <stdio.h>
#include "pilha.h"
#include <string.h>

int estaciona_carro(pilha *p, char *placa){
  return empilha(p, placa);
}
int cont;
int retira_carro(pilha *p, char *placa){
  int status;
  char carro[10], *aux;
  aux = desempilha(p);
  //printf("oks\n");
  if(aux == NULL) return 1;
  strcpy(carro, aux);
  if(strcmp(placa, carro) != 0){
    status = retira_carro(p, placa);
    empilha(p, carro);
    return status;
  }
  return 0;
}

int main(){
  int n, q;
  char s[10];
  pilha *p = cria_pilha();
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    estaciona_carro(p, s);
  }
  for (int i = 0; i < q; ++i) {
    scanf("%s", s);
    printf("%d\n", retira_carro(p, s));
  }
}
