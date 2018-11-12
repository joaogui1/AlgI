#ifndef CIRCULO_H
	#define CIRCULO_H
	#include "ponto.h"

	typedef struct circulo_ CIRCULO;

	CIRCULO* circulo_criar(float x, float y, float raio);
	void circulo_apagar(CIRCULO* circulo);
	float circulo_area(CIRCULO* circulo);
	float distancia(PONTO* p, CIRCULO* r);
#endif