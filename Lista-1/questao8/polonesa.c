#include <stdio.h>
#include "pilhaint.h"
#include <string.h>

int main(){
	int size, aux;
	char in[200];
	pilha *p = cria_pilha();
	fgets(in, 200, stdin); 
	size = strlen(in);
	for(int i = size - 1; i > -1; --i){
		if(in[i] >= '0' && in[i] <= '9')	empilha(p, in[i] - '0');
		else if(in[i] != ' '){
			aux = desempilha(p);
			switch(in[i]){
				case '+':
					aux += desempilha(p);
					break;
				case '-':
					aux -= desempilha(p);
					break;
				case '*':
					aux *= desempilha(p);
					break;
				default:
					aux /= desempilha(p);
					break;
					
			}
			empilha(p, aux);
		}
	}
	printf("resultado %d\n", desempilha(p));
	free(p);
}
