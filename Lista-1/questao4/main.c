#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main(){
  float x, y, x_c, y_c, raio;
  scanf("%f %f %f %f %f", &x, &y, &x_c, &y_c, &raio);
  PONTO* p = ponto_criar(x, y);
  CIRCULO* r = circulo_criar(x_c, y_c, raio);

  if(distancia(p, r) < raio)  printf("Interno\n");
  else  printf("Externo\n");


  return 0;
}
