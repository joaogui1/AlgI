#include <math.h>
#include <stdlib.h>
#include "circulo.h"
#define PI 3.14159

struct circulo_ {
	PONTO* ponto_c;
	float raio;
};

CIRCULO* circulo_criar(float x, float y, float raio) {
	CIRCULO* c = malloc(sizeof(CIRCULO));
	c->ponto_c = ponto_criar(x, y);
	c->raio = raio;
	return c;
}

void circulo_apagar(CIRCULO* circulo) {
	if (circulo != NULL) {
		ponto_apagar(circulo->ponto_c);
		free(circulo);
	}
}

float circulo_area(CIRCULO* circulo) {
	return PI * circulo->raio * circulo->raio;
}

float distancia(PONTO *p, CIRCULO *r){
  float dist;
  PONTO *centro = r->ponto_c;
  dist = (ponto_x(p) - ponto_x(centro))*(ponto_x(p) - ponto_x(centro)) + (ponto_y(p) - ponto_y(centro))*(ponto_y(p) - ponto_y(centro));
  dist =  sqrt(dist);
  return dist;
}
